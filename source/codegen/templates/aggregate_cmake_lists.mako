<%
import cmake_helpers
CMAKE_CURRENT_SOURCE_DIR = r"${CMAKE_CURRENT_SOURCE_DIR}"

%>\

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(GenerateGrpcSources)

% for driver_name in drivers:
add_subdirectory(${driver_name})
% endfor

add_library(driver_services INTERFACE)
add_library(fake_services INTERFACE)

target_link_libraries(fake_services
  INTERFACE
% for fake_name in cmake_helpers.filter_fakes_only(drivers):
    ${cmake_helpers.service_library_name(fake_name)}
% endfor
)

target_link_libraries(driver_services
  INTERFACE
% for driver_name in cmake_helpers.filter_real_drivers_only(drivers):
    ${cmake_helpers.service_library_name(driver_name)}
% endfor
)

target_include_directories(driver_services
  INTERFACE "./")

target_include_directories(fake_services
  INTERFACE "./")