
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(GenerateGrpcSources)
include(GenerateServices)

set(metadata_files
  ${metadata_dir}/niscope/attributes.py
  ${metadata_dir}/niscope/attributes_addon.py
  ${metadata_dir}/niscope/config.py
  ${metadata_dir}/niscope/config_addon.py
  ${metadata_dir}/niscope/enums.py
  ${metadata_dir}/niscope/enums_addon.py
  ${metadata_dir}/niscope/functions.py
  ${metadata_dir}/niscope/functions_addon.py
  ${metadata_dir}/niscope/__init__.py
  )

set(output_files
  ${service_output_dir}/niscope/niscope_client.cpp
  ${service_output_dir}/niscope/niscope_client.h
  ${service_output_dir}/niscope/niscope_library_interface.h
  ${service_output_dir}/niscope/niscope_library.cpp
  ${service_output_dir}/niscope/niscope_library.h
  ${service_output_dir}/niscope/niscope_mock_library.h
  ${service_output_dir}/niscope/niscope.proto
  ${service_output_dir}/niscope/niscope_service.cpp
  ${service_output_dir}/niscope/niscope_service.h
  )

GenerateGrpcSources(
  ${service_output_dir}/niscope/niscope.proto
  ${service_output_dir}/niscope/
  ${proto_srcs_dir}/niscope.pb.cc
  ${proto_srcs_dir}/niscope.pb.h
  ${proto_srcs_dir}/niscope.grpc.pb.cc
  ${proto_srcs_dir}/niscope.grpc.pb.h
  )

GenerateServices(
  niscope
  ${metadata_files}
  ${output_files}
)

add_library(niscope_service
  ${proto_srcs_dir}/niscope.pb.cc
  ${proto_srcs_dir}/niscope.grpc.pb.cc
  ${service_output_dir}/niscope/niscope_client.cpp
  ${service_output_dir}/niscope/niscope_library.cpp
  ${service_output_dir}/niscope/niscope_service.cpp
  ${custom_dir}/niscope_service.custom.cpp
)

target_link_libraries(niscope_service
  ni_grpc_device_server_core
  ${_GRPC_GRPCPP}
  ${CMAKE_DL_LIBS}
)

if(WIN32)
  target_link_libraries(niscope_service Delayimp ${CMAKE_CURRENT_SOURCE_DIR}/../../imports/lib/win64/niScope.lib)
  target_link_options(niscope_service INTERFACE "/DELAYLOAD:niScope_64.dll")
endif()

target_include_directories(niscope_service
  PUBLIC ${proto_srcs_dir} "./")