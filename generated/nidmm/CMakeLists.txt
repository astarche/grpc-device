
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(GenerateGrpcSources)
include(GenerateServices)

set(metadata_files
  ${metadata_dir}/nidmm/attributes.py
  ${metadata_dir}/nidmm/attributes_addon.py
  ${metadata_dir}/nidmm/config.py
  ${metadata_dir}/nidmm/config_addon.py
  ${metadata_dir}/nidmm/enums.py
  ${metadata_dir}/nidmm/enums_addon.py
  ${metadata_dir}/nidmm/functions.py
  ${metadata_dir}/nidmm/functions_addon.py
  ${metadata_dir}/nidmm/__init__.py
  )

set(output_files
  ${service_output_dir}/nidmm/nidmm_client.cpp
  ${service_output_dir}/nidmm/nidmm_client.h
  ${service_output_dir}/nidmm/nidmm_library_interface.h
  ${service_output_dir}/nidmm/nidmm_library.cpp
  ${service_output_dir}/nidmm/nidmm_library.h
  ${service_output_dir}/nidmm/nidmm_mock_library.h
  ${service_output_dir}/nidmm/nidmm.proto
  ${service_output_dir}/nidmm/nidmm_service.cpp
  ${service_output_dir}/nidmm/nidmm_service.h
  )

GenerateGrpcSources(
  ${service_output_dir}/nidmm/nidmm.proto
  ${service_output_dir}/nidmm/
  ${proto_srcs_dir}/nidmm.pb.cc
  ${proto_srcs_dir}/nidmm.pb.h
  ${proto_srcs_dir}/nidmm.grpc.pb.cc
  ${proto_srcs_dir}/nidmm.grpc.pb.h
  )

GenerateServices(
  nidmm
  ${metadata_files}
  ${output_files}
)

add_library(nidmm_service
  ${proto_srcs_dir}/nidmm.pb.cc
  ${proto_srcs_dir}/nidmm.grpc.pb.cc
  ${service_output_dir}/nidmm/nidmm_client.cpp
  ${service_output_dir}/nidmm/nidmm_library.cpp
  ${service_output_dir}/nidmm/nidmm_service.cpp
  ${custom_dir}/nidmm_service.custom.cpp
)

target_link_libraries(nidmm_service
  ni_grpc_device_server_core
  ${_GRPC_GRPCPP}
  ${CMAKE_DL_LIBS}
)

if(WIN32)
  target_link_libraries(nidmm_service Delayimp ${CMAKE_CURRENT_SOURCE_DIR}/../../imports/lib/win64/nidmm.lib)
  target_link_options(nidmm_service INTERFACE "/DELAYLOAD:nidmm_64.dll")
endif()

target_include_directories(nidmm_service
  PUBLIC 
    ${proto_srcs_dir} 
  PRIVATE
    "./"
  INTERFACE
    "../"
)
