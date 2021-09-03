import sys
import os
import argparse
import importlib
import importlib.util
from typing import Dict
import mako.template
from pathlib import Path
import metadata_mutation
from mako.lookup import TemplateLookup

def instantiate_template(template_file_name: str) -> mako.template.Template:
  current_dir = os.path.dirname(__file__)
  template_file_path = os.path.join(current_dir, "templates", template_file_name)
  template_directory = os.path.dirname(template_file_path)
  template_lookup = TemplateLookup(directories = template_directory + "/")
  return mako.template.Template(filename=template_file_path, lookup=template_lookup)


def generate_service_file(metadata, template_file_name, generated_file_suffix, gen_dir):
  module_name = metadata["config"]["module_name"]
  output_dir = os.path.join(gen_dir, module_name)
  if generated_file_suffix == "CMakeLists.txt":
    file_name = generated_file_suffix
  else:
    file_name = module_name + generated_file_suffix
  output_file_path = os.path.join(output_dir, file_name)

  os.makedirs(output_dir, exist_ok=True)
  template = template = instantiate_template(template_file_name)
  write_if_changed(
    output_file_path,
    template.render(data=metadata))


def read_file_contents(output_file_path: str) -> str:
  try:
    with open(output_file_path, "r", newline="") as f:
      return f.read()
  except FileNotFoundError:
    return ""


def write_if_changed(output_file_path: str, new_contents: str) -> None:
  """Write new_contents to output_file_path if new_contents != the contents
  of output_file_path.

  This prevents downstream recompiles when codegen runs but does not change
  a given file.
  """
  old_contents = read_file_contents(output_file_path)
  if old_contents != new_contents:
    with open(output_file_path, "w+", newline="") as f:
        f.write(new_contents)



def mutate_metadata(metadata):
  config = metadata["config"]
  
  attribute_expander = metadata_mutation.AttributeAccessorExpander(metadata)
  for function_name in metadata["functions"]:
    function = metadata["functions"][function_name]
    parameters = function["parameters"]
    metadata_mutation.sanitize_names(parameters)
    metadata_mutation.set_var_args_types(parameters, config)
    metadata_mutation.mark_size_params(parameters)
    metadata_mutation.mark_non_proto_params(parameters)
    metadata_mutation.mark_mapped_enum_params(parameters, metadata["enums"])
    metadata_mutation.populate_grpc_types(parameters, config)
    attribute_expander.expand_attribute_value_params(function)
    attribute_expander.patch_attribute_enum_type(function_name, function)


def load_metadata(metadata_dir: str) -> Dict:
  metadata_path = Path(metadata_dir)
  module = importlib.import_module("metadata." + metadata_path.name)
  metadata = module.metadata
  lookup = TemplateLookup(directories = metadata_dir)
  metadata["lookup"] = lookup
  return metadata


def generate_all(metadata_dir, gen_dir):
  metadata = load_metadata(metadata_dir)
  mutate_metadata(metadata)
  generate_service_file(metadata, "proto.mako", ".proto", gen_dir)
  generate_service_file(metadata, "service.h.mako", "_service.h", gen_dir)
  generate_service_file(metadata, "service.cpp.mako", "_service.cpp", gen_dir)
  generate_service_file(metadata, "library_interface.h.mako", "_library_interface.h", gen_dir)
  generate_service_file(metadata, "library.cpp.mako", "_library.cpp", gen_dir)
  generate_service_file(metadata, "library.h.mako", "_library.h", gen_dir)
  generate_service_file(metadata, "mock_library.h.mako", "_mock_library.h", gen_dir)
  generate_service_file(metadata, "client.h.mako", "_client.h", gen_dir)
  generate_service_file(metadata, "client.cpp.mako", "_client.cpp", gen_dir)
  generate_cmake_lists(metadata_dir, gen_dir)


def generate_cmake_lists(metadata_dir, gen_dir):
  metadata = load_metadata(metadata_dir)
  generate_service_file(metadata, "cmake_lists.mako", "CMakeLists.txt", gen_dir)


if __name__ == "__main__":
  parser = argparse.ArgumentParser(description = "Generate files for specified NI driver API gRPC service.")
  parser.add_argument("metadata", help = "The path to the directory containing the metadata for the API being generated.")
  parser.add_argument("--output", "-o", help = "The path to the top-level directory to save the generated files. The API-specific sub-directories will be automatically created.")
  args = parser.parse_args()
  output = "." if args.output is None else args.output
  generate_all(args.metadata, output)
