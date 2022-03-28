//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Library wrapper for implementing interactions with NI-XNETSOCKET
//---------------------------------------------------------------------
#ifndef NIXNETSOCKET_GRPC_LIBRARY_WRAPPER_H
#define NIXNETSOCKET_GRPC_LIBRARY_WRAPPER_H

#include <grpcpp/grpcpp.h>
#include <nxsocket.h>
#include "custom/xnetsocket_aliases.h"

namespace nixnetsocket_grpc {

class NiXnetSocketLibraryInterface {
 public:
  virtual ~NiXnetSocketLibraryInterface() {}

  virtual nxSOCKET Accept(nxSOCKET socket, nxsockaddr* addr, nxsocklen_t* addrlen) = 0;
  virtual int32_t Bind(nxSOCKET socket, nxsockaddr* name, nxsocklen_t namelen) = 0;
  virtual int32_t Close(nxSOCKET socket) = 0;
  virtual int32_t Connect(nxSOCKET socket, nxsockaddr* name, nxsocklen_t namelen) = 0;
  virtual int32_t FreeAddrInfo(nxaddrinfo* res) = 0;
  virtual int32_t GetAddrInfo(nxIpStackRef_t stack_ref, const char node_api[], const char service_api[], nxaddrinfo* hints, nxaddrinfo** res) = 0;
  virtual int32_t GetLastErrorNum() = 0;
  virtual char* GetLastErrorStr(char buf[], size_t bufLen) = 0;
  virtual int32_t GetNameInfo(nxIpStackRef_t stack_ref, nxsockaddr* addr, nxsocklen_t addrlen, char host[], nxsocklen_t hostlen, char serv[], nxsocklen_t servlen, int32_t flags) = 0;
  virtual int32_t GetPeerName(nxSOCKET socket, nxsockaddr* addr, nxsocklen_t* addrlen) = 0;
  virtual int32_t GetSockName(nxSOCKET socket, nxsockaddr* addr, nxsocklen_t* addrlen) = 0;
  virtual int32_t GetSockOpt(nxSOCKET socket, int32_t level, int32_t optname, void* optval, nxsocklen_t* optlen) = 0;
  virtual uint32_t InetAddr(nxIpStackRef_t stack_ref, const char cp[]) = 0;
  virtual int32_t InetAToN(nxIpStackRef_t stack_ref, const char cp[], nxin_addr* name) = 0;
  virtual char* InetNToA(nxIpStackRef_t stack_ref, nxin_addr inParameter) = 0;
  virtual const char* InetNToP(nxIpStackRef_t stack_ref, int32_t af, void* src, char dst[nxINET6_ADDRSTRLEN], nxsocklen_t size) = 0;
  virtual int32_t InetPToN(nxIpStackRef_t stack_ref, int32_t af, const char src[], void* dst) = 0;
  virtual int32_t IpStackClear(nxIpStackRef_t stack_ref) = 0;
  virtual int32_t IpStackCreate(char stack_name[], char config[], nxIpStackRef_t* stack_ref) = 0;
  virtual void IpStackFreeAllStacksInfoStr(nixnetsocket_grpc::IpStackInfoString info) = 0;
  virtual int32_t IpStackFreeInfo(nxVirtualInterface_t* firstVirtualInterface) = 0;
  virtual int32_t IpStackGetAllStacksInfoStr(uint32_t format, nixnetsocket_grpc::IpStackInfoString* info) = 0;
  virtual int32_t IpStackGetInfo(nxIpStackRef_t stack_ref, uint32_t info_id, nxVirtualInterface_t** virtual_interfaces) = 0;
  virtual int32_t IpStackOpen(char stack_name[], nxIpStackRef_t* stack_ref) = 0;
  virtual int32_t IpStackWaitForInterface(nxIpStackRef_t stack_ref, const char localInterface[], int32_t timeoutMs) = 0;
  virtual int32_t IsSet(nxSOCKET fd, nxfd_set* set) = 0;
  virtual int32_t Listen(nxSOCKET socket, int32_t backlog) = 0;
  virtual int32_t Recv(nxSOCKET socket, char mem[], int32_t size, int32_t flags) = 0;
  virtual int32_t RecvFrom(nxSOCKET socket, char mem[], int32_t size, int32_t flags, nxsockaddr* from, nxsocklen_t* fromlen) = 0;
  virtual int32_t Select(int32_t nfds, nxfd_set* readfds, nxfd_set* writefds, nxfd_set* exceptfds, nxtimeval* timeout) = 0;
  virtual int32_t Send(nxSOCKET socket, char dataptr[], int32_t size, int32_t flags) = 0;
  virtual int32_t SendTo(nxSOCKET socket, char dataptr[], int32_t size, int32_t flags, nxsockaddr* to, nxsocklen_t tolen) = 0;
  virtual int32_t SetSockOpt(nxSOCKET socket, int32_t level, int32_t optname, void* optval, nxsocklen_t optlen) = 0;
  virtual int32_t Shutdown(nxSOCKET socket, int32_t how) = 0;
  virtual nxSOCKET Socket(nxIpStackRef_t stack_ref, int32_t domain, int32_t type, int32_t prototcol) = 0;
  virtual char* StrErrR(int errnum, char buf[], size_t bufLen) = 0;
};

}  // namespace nixnetsocket_grpc
#endif  // NIXNETSOCKET_GRPC_LIBRARY_WRAPPER_H
