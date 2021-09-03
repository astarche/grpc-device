
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(GenerateGrpcSources)
include(GenerateServices)

set(metadata_files
  ${metadata_dir}/nidigitalpattern/attributes.py
  ${metadata_dir}/nidigitalpattern/attributes_addon.py
  ${metadata_dir}/nidigitalpattern/config.py
  ${metadata_dir}/nidigitalpattern/config_addon.py
  ${metadata_dir}/nidigitalpattern/enums.py
  ${metadata_dir}/nidigitalpattern/enums_addon.py
  ${metadata_dir}/nidigitalpattern/functions.py
  ${metadata_dir}/nidigitalpattern/functions_addon.py
  ${metadata_dir}/nidigitalpattern/__init__.py
  )

set(output_files
  ${service_output_dir}/nidigitalpattern/nidigitalpattern_client.cpp
  ${service_output_dir}/nidigitalpattern/nidigitalpattern_client.h
  ${service_output_dir}/nidigitalpattern/nidigitalpattern_library_interface.h
  ${service_output_dir}/nidigitalpattern/nidigitalpattern_library.cpp
  ${service_output_dir}/nidigitalpattern/nidigitalpattern_library.h
  ${service_output_dir}/nidigitalpattern/nidigitalpattern_mock_library.h
  ${service_output_dir}/nidigitalpattern/nidigitalpattern.proto
  ${service_output_dir}/nidigitalpattern/nidigitalpattern_service.cpp
  ${service_output_dir}/nidigitalpattern/nidigitalpattern_service.h
  )

GenerateGrpcSources(
  ${service_output_dir}/nidigitalpattern/nidigitalpattern.proto
  ${service_output_dir}/nidigitalpattern/
  ${proto_srcs_dir}/nidigitalpattern.pb.cc
  ${proto_srcs_dir}/nidigitalpattern.pb.h
  ${proto_srcs_dir}/nidigitalpattern.grpc.pb.cc
  ${proto_srcs_dir}/nidigitalpattern.grpc.pb.h
  )

GenerateServices(
  nidigitalpattern
  ${metadata_files}
  ${output_files}
)

add_library(nidigitalpattern_service
  ${proto_srcs_dir}/nidigitalpattern.pb.cc
  ${proto_srcs_dir}/nidigitalpattern.grpc.pb.cc
  ${service_output_dir}/nidigitalpattern/nidigitalpattern_client.cpp
  ${service_output_dir}/nidigitalpattern/nidigitalpattern_library.cpp
  ${service_output_dir}/nidigitalpattern/nidigitalpattern_service.cpp
  ${custom_dir}/nidigitalpattern_service.custom.cpp
)

target_link_libraries(nidigitalpattern_service
  ni_grpc_device_server_core
  ${_GRPC_GRPCPP}
  ${CMAKE_DL_LIBS}
)

if(WIN32)
  target_link_libraries(nidigitalpattern_service Delayimp ${CMAKE_CURRENT_SOURCE_DIR}/../../imports/lib/win64/niDigital.lib)
  set_target_properties(nidigitalpattern_service PROPERTIES LINK_FLAGS "/DELAYLOAD:niDigital_64.dll")
endif()

target_include_directories(nidigitalpattern_service
  PUBLIC ${proto_srcs_dir} "./")