//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Real implementation of LibraryInterface for NI-XNET
//---------------------------------------------------------------------
#ifndef NIXNET_GRPC_LIBRARY_H
#define NIXNET_GRPC_LIBRARY_H

#include "nixnet_library_interface.h"

#include <server/shared_library.h>

namespace nixnet_grpc {

class NiXnetLibrary : public nixnet_grpc::NiXnetLibraryInterface {
 public:
  NiXnetLibrary();
  virtual ~NiXnetLibrary();

  ::grpc::Status check_function_exists(std::string functionName);
  nxSessionRef_t CreateSession(const char* databaseName, const char* clusterName, const char* list, const char* interfaceParameter, u32 mode, nxSessionRef_t* session);
  nxSessionRef_t Clear(nxSessionRef_t session);

 private:
  using CreateSessionPtr = nxSessionRef_t (*)(const char* databaseName, const char* clusterName, const char* list, const char* interfaceParameter, u32 mode, nxSessionRef_t* session);
  using ClearPtr = nxSessionRef_t (*)(nxSessionRef_t session);

  typedef struct FunctionPointers {
    CreateSessionPtr CreateSession;
    ClearPtr Clear;
  } FunctionLoadStatus;

  nidevice_grpc::SharedLibrary shared_library_;
  FunctionPointers function_pointers_;
};

}  // namespace nixnet_grpc

#endif  // NIXNET_GRPC_LIBRARY_H
