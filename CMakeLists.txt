cmake_minimum_required(VERSION 3.12.0)

project(ni_grpc_device_server C CXX)

# Workaround for: https://bugs.chromium.org/p/boringssl/issues/detail?id=423
if (CMAKE_SYSTEM_PROCESSOR STREQUAL "AMD64")
  set(CMAKE_SYSTEM_PROCESSOR "amd64")
endif()

#----------------------------------------------------------------------
# Use the grpc targets directly from this build, only when not cross-compiling.
#----------------------------------------------------------------------
if(NOT CMAKE_CROSSCOMPILING OR _GRPC_DEVICE_NILRT_LEGACY_TOOLCHAIN)
  add_subdirectory(third_party/grpc ${CMAKE_CURRENT_BINARY_DIR}/grpc EXCLUDE_FROM_ALL)
endif()

#----------------------------------------------------------------------
# Use C++17 (needed for shared_mutex support on Linux)
#----------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(ImportGrpc)
include(GenerateServices)

# ni_fake_service_tests.cpp and several DAQ cpp files exceed the MSVC limit for the number of sections 
# in an obj file defined by PE-COFF. This line disables the limit.
if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj /D_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING")
endif(MSVC)

add_subdirectory("source/server")
add_subdirectory("source/protobuf")
GenerateServiceCMakeLists()
add_subdirectory("generated")

add_executable(ni_grpc_device_server
  "source/server/core_server.cpp"
  ${nidriver_service_srcs})

if(CMAKE_SYSTEM_NAME STREQUAL Linux)
  target_sources(ni_grpc_device_server
    PRIVATE "source/server/linux/syslog_logging.cpp"
    PRIVATE "source/server/linux/daemonize.cpp")
endif()

target_link_libraries(ni_grpc_device_server
  ni_grpc_device_server_core
  driver_services
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF}
  ${CMAKE_DL_LIBS}
  nlohmann_json::nlohmann_json
  )

set_target_properties(ni_grpc_device_server PROPERTIES BUILD_WITH_INSTALL_RPATH TRUE)

#----------------------------------------------------------------------
# Copy server_config.json to binary output directory
#----------------------------------------------------------------------
add_custom_command(
   TARGET ni_grpc_device_server POST_BUILD
   COMMAND  ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_SOURCE_DIR}/source/config/insecure_config.json
            $<TARGET_FILE_DIR:ni_grpc_device_server>/server_config.json)

#----------------------------------------------------------------------
# Add JSON parser and configure google tests
#----------------------------------------------------------------------
if(CMAKE_CROSSCOMPILING AND NOT _GRPC_DEVICE_NILRT_LEGACY_TOOLCHAIN)
  find_package(nlohmann_json REQUIRED)
  find_library(gtest REQUIRED)
else()
  add_subdirectory(third_party/json ${CMAKE_CURRENT_BINARY_DIR}/json EXCLUDE_FROM_ALL)
  enable_testing()
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  add_subdirectory(third_party/gtest ${CMAKE_CURRENT_BINARY_DIR}/gtest EXCLUDE_FROM_ALL)
endif()

# Link test executable against gtest
add_executable(IntegrationTestsRunner
    "source/tests/utilities/run_all_tests.cpp"
    "source/tests/integration/ni_fake_non_ivi_service_tests_endtoend.cpp"
    "source/tests/integration/session_utilities_service_tests.cpp"
    "source/tests/integration/session_utilities_service_tests_endtoend.cpp"
)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

target_link_libraries(IntegrationTestsRunner
    ni_grpc_device_server_core
    fake_services
    gtest
    gmock
    ${_GRPC_GRPCPP}
    ${CMAKE_DL_LIBS}
    Threads::Threads)

add_library(TestApi SHARED
    "source/tests/utilities/test_api.cpp")
add_compile_definitions(TestApi TEST_API_BUILDING)

add_executable(UnitTestsRunner
    "source/tests/utilities/run_all_tests.cpp"
    "source/tests/unit/callback_router_tests.cpp"
    "source/tests/unit/session_resource_repository_tests.cpp"
    "source/tests/unit/session_repository_tests.cpp"
    "source/tests/unit/device_enumerator_tests.cpp"
    "source/tests/unit/server_configuration_parser_tests.cpp"
    "source/tests/unit/server_security_configuration_tests.cpp"
    "source/tests/unit/ni_fake_non_ivi_service_tests.cpp"
    "source/tests/unit/ni_fake_service_tests.cpp"
    "source/tests/unit/shared_library_tests.cpp"
    "source/tests/unit/syscfg_library_tests.cpp"
)

target_link_libraries(UnitTestsRunner
  ni_grpc_device_server_core
  fake_services
  gtest
  gmock
  ${_GRPC_GRPCPP}
  ${CMAKE_DL_LIBS}
  Threads::Threads
  nlohmann_json::nlohmann_json)

#----------------------------------------------------------------------
# Copy test asset certificates to binary output certs sub-directory
#----------------------------------------------------------------------
add_custom_command(
  TARGET UnitTestsRunner POST_BUILD
  COMMAND  ${CMAKE_COMMAND} -E copy_directory
           ${CMAKE_SOURCE_DIR}/source/tests/assets/
           $<TARGET_FILE_DIR:UnitTestsRunner>/)

add_executable(SystemTestsRunner
    "source/tests/utilities/run_all_tests.cpp"
    "source/tests/system/device_server.cpp"
    "source/tests/system/enumerate_devices.cpp"
    "source/tests/system/session_utilities_service_tests.cpp"
    "source/tests/system/nidaqmx_driver_api_tests.cpp"
    "source/tests/system/nidaqmx_session_tests.cpp"
    "source/tests/system/nidcpower_driver_api_tests.cpp"
    "source/tests/system/nidcpower_session_tests.cpp"
    "source/tests/system/nidigital_driver_api_tests.cpp"
    "source/tests/system/nidigital_session_tests.cpp"
    "source/tests/system/nidmm_driver_api_tests.cpp"
    "source/tests/system/nidmm_session_tests.cpp"
    "source/tests/system/nifgen_driver_api_tests.cpp"
    "source/tests/system/nifgen_session_tests.cpp"
    "source/tests/system/niscope_driver_api_tests.cpp"
    "source/tests/system/niscope_session_tests.cpp"
    "source/tests/system/niswitch_driver_api_tests.cpp"
    "source/tests/system/niswitch_session_tests.cpp"
    "source/tests/system/nisync_driver_api_tests.cpp"
    "source/tests/system/nisync_session_tests.cpp"
    "source/tests/system/nitclk_driver_api_tests.cpp"
)

target_link_libraries(SystemTestsRunner
  ni_grpc_device_server_core
  driver_services
  gtest
  gmock
  ${_GRPC_GRPCPP}
  ${CMAKE_DL_LIBS}
  )

# Hook up different google test runners to CTest
# add_test( NAME UnitTests COMMAND UnitTestsRunner )
add_test( NAME UnitTests COMMAND UnitTestsRunner )
add_test( NAME IntegrationTests COMMAND IntegrationTestsRunner )
add_test( NAME SystemTests COMMAND SystemTestsRunner )
