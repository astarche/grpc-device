
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(GenerateGrpcSources)
include(GenerateServices)

set(metadata_files
  ${metadata_dir}/nitclk/attributes.py
  ${metadata_dir}/nitclk/attributes_addon.py
  ${metadata_dir}/nitclk/config.py
  ${metadata_dir}/nitclk/config_addon.py
  ${metadata_dir}/nitclk/enums.py
  ${metadata_dir}/nitclk/enums_addon.py
  ${metadata_dir}/nitclk/functions.py
  ${metadata_dir}/nitclk/functions_addon.py
  ${metadata_dir}/nitclk/__init__.py
  )

set(output_files
  ${service_output_dir}/nitclk/nitclk_client.cpp
  ${service_output_dir}/nitclk/nitclk_client.h
  ${service_output_dir}/nitclk/nitclk_library_interface.h
  ${service_output_dir}/nitclk/nitclk_library.cpp
  ${service_output_dir}/nitclk/nitclk_library.h
  ${service_output_dir}/nitclk/nitclk_mock_library.h
  ${service_output_dir}/nitclk/nitclk.proto
  ${service_output_dir}/nitclk/nitclk_service.cpp
  ${service_output_dir}/nitclk/nitclk_service.h
  )

GenerateGrpcSources(
  ${service_output_dir}/nitclk/nitclk.proto
  ${service_output_dir}/nitclk/
  ${proto_srcs_dir}/nitclk.pb.cc
  ${proto_srcs_dir}/nitclk.pb.h
  ${proto_srcs_dir}/nitclk.grpc.pb.cc
  ${proto_srcs_dir}/nitclk.grpc.pb.h
  )

GenerateServices(
  nitclk
  ${metadata_files}
  ${output_files}
)

add_library(nitclk_service
  ${proto_srcs_dir}/nitclk.pb.cc
  ${proto_srcs_dir}/nitclk.grpc.pb.cc
  ${service_output_dir}/nitclk/nitclk_client.cpp
  ${service_output_dir}/nitclk/nitclk_library.cpp
  ${service_output_dir}/nitclk/nitclk_service.cpp
  ${custom_dir}/nitclk_service.custom.cpp
)

target_link_libraries(nitclk_service
  ni_grpc_device_server_core
  ${_GRPC_GRPCPP}
  ${CMAKE_DL_LIBS}
)

if(WIN32)
  target_link_libraries(nitclk_service Delayimp ${CMAKE_CURRENT_SOURCE_DIR}/../../imports/lib/win64/niTclk.lib)
  set_target_properties(nitclk_service PROPERTIES LINK_FLAGS "/DELAYLOAD:nitclk_64.dll")
endif()

target_include_directories(nitclk_service
  PUBLIC ${proto_srcs_dir} "./")