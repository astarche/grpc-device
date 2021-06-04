//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Library wrapper for implementing interactions with NI-XNET
//---------------------------------------------------------------------
#ifndef NIXNET_GRPC_LIBRARY_WRAPPER_H
#define NIXNET_GRPC_LIBRARY_WRAPPER_H

#include <grpcpp/grpcpp.h>
#include <nixnet.h>

namespace nixnet_grpc {

class NiXnetLibraryInterface {
 public:
  virtual ~NiXnetLibraryInterface() {}

  virtual nxSessionRef_t CreateSession(const char* databaseName, const char* clusterName, const char* list, const char* interfaceParameter, u32 mode, nxSessionRef_t* session) = 0;
  virtual nxSessionRef_t Clear(nxSessionRef_t session) = 0;
};

}  // namespace nixnet_grpc
#endif  // NIXNET_GRPC_LIBRARY_WRAPPER_H
