
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(GenerateGrpcSources)
include(GenerateServices)

set(metadata_files
  ${metadata_dir}/nifgen/attributes.py
  ${metadata_dir}/nifgen/attributes_addon.py
  ${metadata_dir}/nifgen/config.py
  ${metadata_dir}/nifgen/config_addon.py
  ${metadata_dir}/nifgen/enums.py
  ${metadata_dir}/nifgen/enums_addon.py
  ${metadata_dir}/nifgen/functions.py
  ${metadata_dir}/nifgen/functions_addon.py
  ${metadata_dir}/nifgen/__init__.py
  )

set(output_files
  ${service_output_dir}/nifgen/nifgen_client.cpp
  ${service_output_dir}/nifgen/nifgen_client.h
  ${service_output_dir}/nifgen/nifgen_library_interface.h
  ${service_output_dir}/nifgen/nifgen_library.cpp
  ${service_output_dir}/nifgen/nifgen_library.h
  ${service_output_dir}/nifgen/nifgen_mock_library.h
  ${service_output_dir}/nifgen/nifgen.proto
  ${service_output_dir}/nifgen/nifgen_service.cpp
  ${service_output_dir}/nifgen/nifgen_service.h
  )

GenerateGrpcSources(
  ${service_output_dir}/nifgen/nifgen.proto
  ${service_output_dir}/nifgen/
  ${proto_srcs_dir}/nifgen.pb.cc
  ${proto_srcs_dir}/nifgen.pb.h
  ${proto_srcs_dir}/nifgen.grpc.pb.cc
  ${proto_srcs_dir}/nifgen.grpc.pb.h
  )

GenerateServices(
  nifgen
  ${metadata_files}
  ${output_files}
)

add_library(nifgen_service
  ${proto_srcs_dir}/nifgen.pb.cc
  ${proto_srcs_dir}/nifgen.grpc.pb.cc
  ${service_output_dir}/nifgen/nifgen_client.cpp
  ${service_output_dir}/nifgen/nifgen_library.cpp
  ${service_output_dir}/nifgen/nifgen_service.cpp
  ${custom_dir}/nifgen_service.custom.cpp
)

target_link_libraries(nifgen_service
  ni_grpc_device_server_core
  ${_GRPC_GRPCPP}
  ${CMAKE_DL_LIBS}
)

if(WIN32)
  target_link_libraries(nifgen_service Delayimp ${CMAKE_CURRENT_SOURCE_DIR}/../../imports/lib/win64/niFgen.lib)
  target_link_options(nifgen_service INTERFACE "/DELAYLOAD:niFgen_64.dll")
endif()

target_include_directories(nifgen_service
  PUBLIC 
    ${proto_srcs_dir} 
  PRIVATE
    "./"
  INTERFACE
    "../"
)
