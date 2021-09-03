from argparse import ArgumentParser
from generate_service import generate_cmake_lists, instantiate_template, generate_service_file, load_metadata
from pathlib import Path


def generate_all_cmake_lists(input: str, output: str) -> None:
  subdirectories = [p for p in Path(input).iterdir() if p.is_dir()]

  modules = []
  for module in subdirectories:
    module_name = module.name
    generate_cmake_lists(str(module), output)
    modules.append(module_name)

  aggregate_template = instantiate_template("aggregate_cmake_lists.mako")
  
  f=open(Path(output) / "CMakeLists.txt", "w+", newline="")
  f.write(aggregate_template.render(drivers=modules))
  f.close()


if __name__ == "__main__":
  parser = ArgumentParser(description = "Generate files for specified NI driver API gRPC service.")
  parser.add_argument("input", help = "The path to the directory containing the metadata for the API being generated.")
  parser.add_argument("--output", "-o", help = "The path to the top-level directory to save the gener ated files. The API-specific sub-directories will be automatically created.")
  args = parser.parse_args()
  output = "." if args.output is None else args.output
  generate_all_cmake_lists(args.input, output)