
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(GenerateGrpcSources)
include(GenerateServices)

set(metadata_files
  ${metadata_dir}/nidcpower/attributes.py
  ${metadata_dir}/nidcpower/attributes_addon.py
  ${metadata_dir}/nidcpower/config.py
  ${metadata_dir}/nidcpower/config_addon.py
  ${metadata_dir}/nidcpower/enums.py
  ${metadata_dir}/nidcpower/enums_addon.py
  ${metadata_dir}/nidcpower/functions.py
  ${metadata_dir}/nidcpower/functions_addon.py
  ${metadata_dir}/nidcpower/__init__.py
  )

set(output_files
  ${service_output_dir}/nidcpower/nidcpower_client.cpp
  ${service_output_dir}/nidcpower/nidcpower_client.h
  ${service_output_dir}/nidcpower/nidcpower_library_interface.h
  ${service_output_dir}/nidcpower/nidcpower_library.cpp
  ${service_output_dir}/nidcpower/nidcpower_library.h
  ${service_output_dir}/nidcpower/nidcpower_mock_library.h
  ${service_output_dir}/nidcpower/nidcpower.proto
  ${service_output_dir}/nidcpower/nidcpower_service.cpp
  ${service_output_dir}/nidcpower/nidcpower_service.h
  )

GenerateGrpcSources(
  ${service_output_dir}/nidcpower/nidcpower.proto
  ${service_output_dir}/nidcpower/
  ${proto_srcs_dir}/nidcpower.pb.cc
  ${proto_srcs_dir}/nidcpower.pb.h
  ${proto_srcs_dir}/nidcpower.grpc.pb.cc
  ${proto_srcs_dir}/nidcpower.grpc.pb.h
  )

GenerateServices(
  nidcpower
  ${metadata_files}
  ${output_files}
)

add_library(nidcpower_service
  ${proto_srcs_dir}/nidcpower.pb.cc
  ${proto_srcs_dir}/nidcpower.grpc.pb.cc
  ${service_output_dir}/nidcpower/nidcpower_client.cpp
  ${service_output_dir}/nidcpower/nidcpower_library.cpp
  ${service_output_dir}/nidcpower/nidcpower_service.cpp
  ${custom_dir}/nidcpower_service.custom.cpp
)

target_link_libraries(nidcpower_service
  ni_grpc_device_server_core
  ${_GRPC_GRPCPP}
  ${CMAKE_DL_LIBS}
)

if(WIN32)
  target_link_libraries(nidcpower_service Delayimp ${CMAKE_CURRENT_SOURCE_DIR}/../../imports/lib/win64/nidcpower.lib)
  target_link_options(nidcpower_service INTERFACE "/DELAYLOAD:nidcpower_64.dll")
endif()

target_include_directories(nidcpower_service
  PUBLIC 
    ${proto_srcs_dir} 
  PRIVATE
    "./"
  INTERFACE
    "../"
)
