
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(GenerateGrpcSources)
include(GenerateServices)

set(metadata_files
  ${metadata_dir}/nidaqmx/attributes.py
  ${metadata_dir}/nidaqmx/attributes_addon.py
  ${metadata_dir}/nidaqmx/config.py
  ${metadata_dir}/nidaqmx/config_addon.py
  ${metadata_dir}/nidaqmx/enums.py
  ${metadata_dir}/nidaqmx/enums_addon.py
  ${metadata_dir}/nidaqmx/functions.py
  ${metadata_dir}/nidaqmx/functions_addon.py
  ${metadata_dir}/nidaqmx/__init__.py
  )

set(output_files
  ${service_output_dir}/nidaqmx/nidaqmx_client.cpp
  ${service_output_dir}/nidaqmx/nidaqmx_client.h
  ${service_output_dir}/nidaqmx/nidaqmx_library_interface.h
  ${service_output_dir}/nidaqmx/nidaqmx_library.cpp
  ${service_output_dir}/nidaqmx/nidaqmx_library.h
  ${service_output_dir}/nidaqmx/nidaqmx_mock_library.h
  ${service_output_dir}/nidaqmx/nidaqmx.proto
  ${service_output_dir}/nidaqmx/nidaqmx_service.cpp
  ${service_output_dir}/nidaqmx/nidaqmx_service.h
  )

GenerateGrpcSources(
  ${service_output_dir}/nidaqmx/nidaqmx.proto
  ${service_output_dir}/nidaqmx/
  ${proto_srcs_dir}/nidaqmx.pb.cc
  ${proto_srcs_dir}/nidaqmx.pb.h
  ${proto_srcs_dir}/nidaqmx.grpc.pb.cc
  ${proto_srcs_dir}/nidaqmx.grpc.pb.h
  )

GenerateServices(
  nidaqmx
  ${metadata_files}
  ${output_files}
)

add_library(nidaqmx_service
  ${proto_srcs_dir}/nidaqmx.pb.cc
  ${proto_srcs_dir}/nidaqmx.grpc.pb.cc
  ${service_output_dir}/nidaqmx/nidaqmx_client.cpp
  ${service_output_dir}/nidaqmx/nidaqmx_library.cpp
  ${service_output_dir}/nidaqmx/nidaqmx_service.cpp
  ${custom_dir}/nidaqmx_service.custom.cpp
)

target_link_libraries(nidaqmx_service
  ni_grpc_device_server_core
  ${_GRPC_GRPCPP}
  ${CMAKE_DL_LIBS}
)

if(WIN32)
  target_link_libraries(nidaqmx_service Delayimp ${CMAKE_CURRENT_SOURCE_DIR}/../../imports/lib/win64/nidaqmx.lib)
  target_link_options(nidaqmx_service INTERFACE "/DELAYLOAD:nicaiu.dll")
endif()

target_include_directories(nidaqmx_service
  PUBLIC ${proto_srcs_dir} "./")