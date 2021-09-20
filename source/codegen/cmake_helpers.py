from collections import namedtuple
from typing import List


def list_metadata_files(metadata_dir: str, module_name: str) -> List[str]:
  metadata_files = [
    "attributes.py",
    "attributes_addon.py",
    "config.py",
    "config_addon.py",
    "enums.py",
    "enums_addon.py",
    "functions.py",
    "functions_addon.py",
    "__init__.py"
  ]

  return [f"{metadata_dir}/{module_name}/{f}" for f in metadata_files]


def list_output_files(config: dict, output_dir: str) -> List[str]:
  module_name = config["module_name"]
  suffixes = [
    "_client.cpp",
    "_client.h",
    "_library_interface.h",
    "_library.cpp",
    "_library.h",
    "_mock_library.h",
    ".proto",
    "_service.cpp",
    "_service.h"
  ]

  return [f"{output_dir}/{module_name}/{module_name}{s}" for s in suffixes]


def is_client_file(file: str) -> bool:
  name, _ = file.rsplit(".")
  return name.endswith("_client")


def list_service_output_cpp_files(config: dict, output_dir: str) -> List[str]:
  return [
    f
    for f in list_output_cpp_files(config, output_dir)
    if not is_client_file(f)
  ]


def list_client_output_cpp_files(config: dict, output_dir: str) -> List[str]:
  return [
    f
    for f in list_output_cpp_files(config, output_dir)
    if is_client_file(f)
  ]


def is_fake(module_name: str) -> bool:
  return module_name.startswith("nifake")


# grr -> fake libs and clients not buildable
def is_supported_cpp_file(module_name: str, file_name: str) -> bool:
  if not file_name.endswith("cpp"):
    return False
  if is_fake(module_name):
    return not (
      file_name.endswith("_library.cpp") 
      or file_name.endswith("_client.cpp")
    )
  return True


def list_output_cpp_files(config: dict, output_dir: str) -> List[str]:
  module_name = config["module_name"]
  return [
    f
    for f in list_output_files(config, output_dir)
    if is_supported_cpp_file(module_name, f)
  ]


GenerateSourcesRequest = namedtuple(
  "GenerateSourcesRequest",
  ["proto_file", "proto_path", "proto_srcs", "proto_hdrs", "grpc_srcs", "grpc_hdrs"])


def create_generate_sources_request(module_name: str, proto_srcs_dir: str, service_output_dir: str) -> GenerateSourcesRequest:
  return GenerateSourcesRequest(
    f"{service_output_dir}/{module_name}/{module_name}.proto",
    f"{service_output_dir}/{module_name}/",
    f"{proto_srcs_dir}/{module_name}.pb.cc",
    f"{proto_srcs_dir}/{module_name}.pb.h",
    f"{proto_srcs_dir}/{module_name}.grpc.pb.cc",
    f"{proto_srcs_dir}/{module_name}.grpc.pb.h",
  )


def service_library_name(driver_module_name: str) -> str:
  return f"{driver_module_name}_service"


def client_library_name(driver_module_name: str) -> str:
  return f"{driver_module_name}_client"


def is_fake(driver: str) -> bool:
  return driver.startswith("nifake")


def filter_fakes_only(drivers: List[str]) -> List[str]:
  return [
    d
    for d in drivers
    if is_fake(d)
  ]


def filter_real_drivers_only(drivers: List[str]) -> List[str]:
  return [
    d
    for d in drivers
    if not is_fake(d)
  ]


def get_custom_cpp_path(custom_dir: str, driver_module_name: str) -> str:
  return f"{custom_dir}/{driver_module_name}_service.custom.cpp"