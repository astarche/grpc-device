//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Library wrapper for implementing interactions with NI-XNETSOCKET
//---------------------------------------------------------------------
#ifndef NIXNETSOCKET_GRPC_LIBRARY_WRAPPER_H
#define NIXNETSOCKET_GRPC_LIBRARY_WRAPPER_H

#include <grpcpp/grpcpp.h>
#include <nxsocket.h>

namespace nixnetsocket_grpc {

class NiXnetSocketLibraryInterface {
 public:
  virtual ~NiXnetSocketLibraryInterface() {}

  virtual int32_t Bind(nxSOCKET socket, nxsockaddr* name, nxsocklen_t namelen) = 0;
  virtual int32_t Close(nxSOCKET socket) = 0;
  virtual int32_t GetLastErrorNum() = 0;
  virtual char* GetLastErrorStr(char buf[], size_t bufLen) = 0;
  virtual int32_t IpStackClear(nxIpStackRef_t stack_ref) = 0;
  virtual int32_t IpStackCreate(char stack_name[], char config[], nxIpStackRef_t* stack_ref) = 0;
  virtual nxSOCKET Socket(nxIpStackRef_t stack_ref, int32_t domain, int32_t type, int32_t prototcol) = 0;
};

}  // namespace nixnetsocket_grpc
#endif  // NIXNETSOCKET_GRPC_LIBRARY_WRAPPER_H
