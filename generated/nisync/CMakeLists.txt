
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(GenerateGrpcSources)
include(GenerateServices)

set(metadata_files
  ${metadata_dir}/nisync/attributes.py
  ${metadata_dir}/nisync/attributes_addon.py
  ${metadata_dir}/nisync/config.py
  ${metadata_dir}/nisync/config_addon.py
  ${metadata_dir}/nisync/enums.py
  ${metadata_dir}/nisync/enums_addon.py
  ${metadata_dir}/nisync/functions.py
  ${metadata_dir}/nisync/functions_addon.py
  ${metadata_dir}/nisync/__init__.py
  )

set(output_files
  ${service_output_dir}/nisync/nisync_client.cpp
  ${service_output_dir}/nisync/nisync_client.h
  ${service_output_dir}/nisync/nisync_library_interface.h
  ${service_output_dir}/nisync/nisync_library.cpp
  ${service_output_dir}/nisync/nisync_library.h
  ${service_output_dir}/nisync/nisync_mock_library.h
  ${service_output_dir}/nisync/nisync.proto
  ${service_output_dir}/nisync/nisync_service.cpp
  ${service_output_dir}/nisync/nisync_service.h
  )

GenerateGrpcSources(
  ${service_output_dir}/nisync/nisync.proto
  ${service_output_dir}/nisync/
  ${proto_srcs_dir}/nisync.pb.cc
  ${proto_srcs_dir}/nisync.pb.h
  ${proto_srcs_dir}/nisync.grpc.pb.cc
  ${proto_srcs_dir}/nisync.grpc.pb.h
  )

GenerateServices(
  nisync
  ${metadata_files}
  ${output_files}
)

add_library(nisync_service
  ${proto_srcs_dir}/nisync.pb.cc
  ${proto_srcs_dir}/nisync.grpc.pb.cc
  ${service_output_dir}/nisync/nisync_client.cpp
  ${service_output_dir}/nisync/nisync_library.cpp
  ${service_output_dir}/nisync/nisync_service.cpp
  ${custom_dir}/nisync_service.custom.cpp
)

target_link_libraries(nisync_service
  ni_grpc_device_server_core
  ${_GRPC_GRPCPP}
  ${CMAKE_DL_LIBS}
)

if(WIN32)
  target_link_libraries(nisync_service Delayimp ${CMAKE_CURRENT_SOURCE_DIR}/../../imports/lib/win64/nisync.lib)
  target_link_options(nisync_service INTERFACE "/DELAYLOAD:nisync.dll")
endif()

target_include_directories(nisync_service
  PUBLIC 
    ${proto_srcs_dir} 
  PRIVATE
    "./"
  INTERFACE
    "../"
)
