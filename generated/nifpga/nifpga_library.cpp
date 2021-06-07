//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service implementation for the NI-FPGA Metadata
//---------------------------------------------------------------------
#include "nifpga_library.h"

#if defined(_MSC_VER)
static const char* kLibraryName = "NiFpga.dll";
#else
static const char* kLibraryName = "liblibNiFpga.so.so";
#endif

namespace nifpga_grpc {

NiFpgaLibrary::NiFpgaLibrary() : shared_library_(kLibraryName)
{
  shared_library_.load();
  bool loaded = shared_library_.is_loaded();
  memset(&function_pointers_, 0, sizeof(function_pointers_));
  if (!loaded) {
    return;
  }
  function_pointers_.Open = reinterpret_cast<OpenPtr>(shared_library_.get_function_pointer("NiFpgaDll_Open"));
  function_pointers_.Close = reinterpret_cast<ClosePtr>(shared_library_.get_function_pointer("NiFpgaDll_Close"));
}

NiFpgaLibrary::~NiFpgaLibrary()
{
}

::grpc::Status NiFpgaLibrary::check_function_exists(std::string functionName)
{
  return shared_library_.function_exists(functionName.c_str())
    ? ::grpc::Status::OK
    : ::grpc::Status(::grpc::NOT_FOUND, "Could not find the function " + functionName);
}

int32_t NiFpgaLibrary::Open(const char* bitfile, const char* signature, const char* resource, uint32_t attribute, NiFpga_Session* session)
{
  if (!function_pointers_.Open) {
    throw nidevice_grpc::LibraryLoadException("Could not find NiFpgaDll_Open.");
  }
  return function_pointers_.Open(bitfile, signature, resource, attribute, session);
}

int32_t NiFpgaLibrary::Close(NiFpga_Session session, uint32_t attribute)
{
  if (!function_pointers_.Close) {
    throw nidevice_grpc::LibraryLoadException("Could not find NiFpgaDll_Close.");
  }
  return function_pointers_.Close(session, attribute);
}

}  // namespace nifpga_grpc
