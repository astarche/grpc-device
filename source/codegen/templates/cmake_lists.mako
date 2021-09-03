<%
import cmake_helpers
import common_helpers

config = data["config"]
module_name = config["module_name"]
static_library_name = config["library_info"]["Windows"]["64bit"].get("static_name", None)
dll_name = config["library_info"]["Windows"]["64bit"]["name"]
server_library_name = f"{module_name}_service"

CMAKE_CURRENT_SOURCE_DIR = r"${CMAKE_CURRENT_SOURCE_DIR}"
codegen_dir = r"${codegen_dir}"
metadata_dir = r"${metadata_dir}"
proto_srcs_dir = r"${proto_srcs_dir}"
service_output_dir = r"${service_output_dir}"
%>\

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(GenerateGrpcSources)
include(GenerateServices)

set(metadata_files
% for metadata_file in cmake_helpers.list_metadata_files(metadata_dir, module_name):
  ${metadata_file}
% endfor
  )

set(output_files
% for output_file in cmake_helpers.list_output_files(config, service_output_dir):
  ${output_file}
% endfor
  )

<%
generates_sources = cmake_helpers.create_generate_sources_request(module_name, proto_srcs_dir, service_output_dir)
%>\
GenerateGrpcSources(
  ${generates_sources.proto_file}
  ${generates_sources.proto_path}
  ${generates_sources.proto_srcs}
  ${generates_sources.proto_hdrs}
  ${generates_sources.grpc_srcs}
  ${generates_sources.grpc_hdrs}
  )

GenerateServices(
  ${module_name}
  ${r"${metadata_files}"}
  ${r"${output_files}"}
)

add_library(${server_library_name}
  ${generates_sources.proto_srcs}
  ${generates_sources.grpc_srcs}
% for output_file in cmake_helpers.list_output_cpp_files(config, service_output_dir):
  ${output_file}
% endfor
  ${cmake_helpers.get_custom_cpp_path(r"${custom_dir}", module_name)}
)

target_link_libraries(${server_library_name}
  ni_grpc_device_server_core
  ${r"${_GRPC_GRPCPP}"}
  ${r"${CMAKE_DL_LIBS}"}
)

% if static_library_name:
if(WIN32)
  target_link_libraries(${server_library_name} Delayimp ${CMAKE_CURRENT_SOURCE_DIR}/../../imports/lib/win64/${static_library_name}.lib)
  target_link_options(${server_library_name} INTERFACE "/DELAYLOAD:${dll_name}")
endif()
% endif

target_include_directories(${server_library_name}
  PUBLIC ${r"${proto_srcs_dir}"} "./")