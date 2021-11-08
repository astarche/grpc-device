<%
import common_helpers
import proto_helpers

config = data["config"]
enums = data["enums"]
functions = data["functions"]

service_class_prefix = config["service_class_prefix"]
function_enums = common_helpers.get_function_enums(functions)
uses_timestamp = common_helpers.any_function_uses_timestamp(functions)
%>\
<%namespace name="mako_helper" file="/proto_helpers.mako"/>\

//---------------------------------------------------------------------
// This file is MAGICALLY generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Proto file for the ${config["driver_name"]} Metadata
//---------------------------------------------------------------------
syntax = "proto3";

option java_multiple_files = true;
option java_package = "${config["java_package"]}";
option java_outer_classname = "${service_class_prefix}";
option csharp_namespace = "${config["csharp_namespace"]}";

package ${config["namespace_component"]}_grpc;

% if common_helpers.uses_nidevice_common_message_types(functions):
import "nidevice.proto";
% endif
import "session.proto";
% if uses_timestamp:
import "google/protobuf/timestamp.proto";
% endif

service ${service_class_prefix} {
% for function in common_helpers.filter_proto_rpc_functions(functions):
<%
  method_name = common_helpers.snake_to_pascal(function)
  streaming_qualifier = proto_helpers.get_streaming_response_qualifier(functions[function])
%>\
  rpc ${method_name}(${method_name}Request) returns (${streaming_qualifier}${method_name}Response);
% endfor
}

% for group in common_helpers.get_attribute_groups(data):
%   for define_attribute_enum, attributes in group.get_attributes_split_by_sub_group().items():
${mako_helper.define_attribute_enum(group.name, define_attribute_enum, attributes)}\
%   endfor
% endfor
${mako_helper.define_function_enums(function_enums)}\
${mako_helper.insert_custom_template_if_found()}\
% for custom_type in common_helpers.get_custom_types(config):
${mako_helper.define_custom_type(custom_type)}\

% endfor
% for function in common_helpers.filter_proto_rpc_functions(functions):
<%
  input_parameters, output_parameters = proto_helpers.get_parameters(functions[function])
%>\
${mako_helper.define_request_message(function, input_parameters)}\

${mako_helper.define_response_message(function, output_parameters)}\

% endfor