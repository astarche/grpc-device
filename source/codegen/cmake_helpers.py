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


def list_output_cpp_files(config: dict, output_dir: str) -> List[str]:
  module_name = config["module_name"]
  is_fake = module_name.startswith("nifake")
  return [
    f
    for f in list_output_files(config, output_dir)
    if f.endswith(".cpp") and not (is_fake and (f.endswith("_library.cpp") or f.endswith("_client.cpp")))
    # grr -> fake libs not buildable
  ]

GenerateSourcesRequest = namedtuple(
  "GenerateSourcesRequest",
  ["output_dir", "proto_file", "proto_path", "proto_srcs", "proto_hdrs", "grpc_srcs", "grpc_hdrs"])


def create_generate_sources_request(module_name: str, proto_srcs_dir: str, service_output_dir: str) -> GenerateSourcesRequest:
  return GenerateSourcesRequest(
    f"{proto_srcs_dir}",
    f"{service_output_dir}/{module_name}/{module_name}.proto",
    f"{service_output_dir}/{module_name}/",
    f"{proto_srcs_dir}/{module_name}.pb.cc",
    f"{proto_srcs_dir}/{module_name}.pb.h",
    f"{proto_srcs_dir}/{module_name}.grpc.pb.cc",
    f"{proto_srcs_dir}/{module_name}.grpc.pb.h",
  )


def service_library_name(driver_module_name: str) -> str:
  return f"{driver_module_name}_service"


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