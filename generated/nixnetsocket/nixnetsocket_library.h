//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Real implementation of LibraryInterface for NI-XNETSOCKET
//---------------------------------------------------------------------
#ifndef NIXNETSOCKET_GRPC_LIBRARY_H
#define NIXNETSOCKET_GRPC_LIBRARY_H

#include "nixnetsocket_library_interface.h"

#include <server/shared_library.h>

namespace nixnetsocket_grpc {

class NiXnetSocketLibrary : public nixnetsocket_grpc::NiXnetSocketLibraryInterface {
 public:
  NiXnetSocketLibrary();
  virtual ~NiXnetSocketLibrary();

  ::grpc::Status check_function_exists(std::string functionName);
  nxSOCKET Accept(nxSOCKET socket, nxsockaddr* addr, nxsocklen_t* addrlen);
  int32_t Bind(nxSOCKET socket, nxsockaddr* name, nxsocklen_t namelen);
  int32_t Close(nxSOCKET socket);
  int32_t Connect(nxSOCKET socket, nxsockaddr* name, nxsocklen_t namelen);
  int32_t FreeAddrInfo(nxaddrinfo* res);
  int32_t GetAddrInfo(nxIpStackRef_t stack_ref, const char node_api[], const char service_api[], nxaddrinfo* hints, nxaddrinfo** res);
  int32_t GetLastErrorNum();
  char* GetLastErrorStr(char buf[], size_t bufLen);
  int32_t GetNameInfo(nxIpStackRef_t stack_ref, nxsockaddr* addr, nxsocklen_t addrlen, char host[], nxsocklen_t hostlen, char serv[], nxsocklen_t servlen, int32_t flags);
  int32_t GetPeerName(nxSOCKET socket, nxsockaddr* addr, nxsocklen_t* addrlen);
  int32_t GetSockName(nxSOCKET socket, nxsockaddr* addr, nxsocklen_t* addrlen);
  int32_t GetSockOpt(nxSOCKET socket, int32_t level, int32_t optname, void* optval, nxsocklen_t* optlen);
  uint32_t InetAddr(nxIpStackRef_t stack_ref, const char cp[]);
  int32_t InetAToN(nxIpStackRef_t stack_ref, const char cp[], nxin_addr* name);
  char* InetNToA(nxIpStackRef_t stack_ref, nxin_addr inParameter);
  const char* InetNToP(nxIpStackRef_t stack_ref, int32_t af, void* src, char dst[nxINET6_ADDRSTRLEN], nxsocklen_t size);
  int32_t InetPToN(nxIpStackRef_t stack_ref, int32_t af, const char src[], void* dst);
  int32_t IpStackClear(nxIpStackRef_t stack_ref);
  int32_t IpStackCreate(char stack_name[], char config[], nxIpStackRef_t* stack_ref);
  void IpStackFreeAllStacksInfoStr(nixnetsocket_grpc::IpStackInfoString info);
  int32_t IpStackFreeInfo(nxVirtualInterface_t* firstVirtualInterface);
  int32_t IpStackGetAllStacksInfoStr(uint32_t format, nixnetsocket_grpc::IpStackInfoString* info);
  int32_t IpStackGetInfo(nxIpStackRef_t stack_ref, uint32_t info_id, nxVirtualInterface_t** virtual_interfaces);
  int32_t IpStackOpen(char stack_name[], nxIpStackRef_t* stack_ref);
  int32_t IpStackWaitForInterface(nxIpStackRef_t stack_ref, const char localInterface[], int32_t timeoutMs);
  int32_t FdIsSet(nxSOCKET fd, nxfd_set* set);
  int32_t Listen(nxSOCKET socket, int32_t backlog);
  int32_t Recv(nxSOCKET socket, char mem[], int32_t size, int32_t flags);
  int32_t RecvFrom(nxSOCKET socket, char mem[], int32_t size, int32_t flags, nxsockaddr* from, nxsocklen_t* fromlen);
  int32_t Select(int32_t nfds, nxfd_set* readfds, nxfd_set* writefds, nxfd_set* exceptfds, nxtimeval* timeout);
  int32_t Send(nxSOCKET socket, char dataptr[], int32_t size, int32_t flags);
  int32_t SendTo(nxSOCKET socket, char dataptr[], int32_t size, int32_t flags, nxsockaddr* to, nxsocklen_t tolen);
  int32_t SetSockOpt(nxSOCKET socket, int32_t level, int32_t optname, void* optval, nxsocklen_t optlen);
  int32_t Shutdown(nxSOCKET socket, int32_t how);
  nxSOCKET Socket(nxIpStackRef_t stack_ref, int32_t domain, int32_t type, int32_t protocol);
  char* StrErrR(int errnum, char buf[], size_t bufLen);

 private:
  using AcceptPtr = decltype(&nxaccept);
  using BindPtr = decltype(&nxbind);
  using ClosePtr = decltype(&nxclose);
  using ConnectPtr = decltype(&nxconnect);
  using FreeAddrInfoPtr = int32_t (*)(nxaddrinfo* res);
  using GetAddrInfoPtr = decltype(&nxgetaddrinfo);
  using GetLastErrorNumPtr = int32_t (*)();
  using GetLastErrorStrPtr = char* (*)(char buf[], size_t bufLen);
  using GetNameInfoPtr = decltype(&nxgetnameinfo);
  using GetPeerNamePtr = decltype(&nxgetpeername);
  using GetSockNamePtr = decltype(&nxgetsockname);
  using GetSockOptPtr = decltype(&nxgetsockopt);
  using InetAddrPtr = decltype(&nxinet_addr);
  using InetAToNPtr = decltype(&nxinet_aton);
  using InetNToAPtr = decltype(&nxinet_ntoa);
  using InetNToPPtr = decltype(&nxinet_ntop);
  using InetPToNPtr = decltype(&nxinet_pton);
  using IpStackClearPtr = decltype(&nxIpStackClear);
  using IpStackCreatePtr = decltype(&nxIpStackCreate);
  using IpStackFreeAllStacksInfoStrPtr = void (*)(nixnetsocket_grpc::IpStackInfoString info);
  using IpStackFreeInfoPtr = int32_t (*)(nxVirtualInterface_t* firstVirtualInterface);
  using IpStackGetAllStacksInfoStrPtr = decltype(&nxIpStackGetAllStacksInfoStr);
  using IpStackGetInfoPtr = decltype(&nxIpStackGetInfo);
  using IpStackOpenPtr = decltype(&nxIpStackOpen);
  using IpStackWaitForInterfacePtr = decltype(&nxIpStackWaitForInterface);
  using FdIsSetPtr = decltype(&nxfd_isset);
  using ListenPtr = decltype(&nxlisten);
  using RecvPtr = decltype(&nxrecv);
  using RecvFromPtr = decltype(&nxrecvfrom);
  using SelectPtr = decltype(&nxselect);
  using SendPtr = decltype(&nxsend);
  using SendToPtr = decltype(&nxsendto);
  using SetSockOptPtr = decltype(&nxsetsockopt);
  using ShutdownPtr = decltype(&nxshutdown);
  using SocketPtr = decltype(&nxsocket);
  using StrErrRPtr = decltype(&nxstrerr_r);

  typedef struct FunctionPointers {
    AcceptPtr Accept;
    BindPtr Bind;
    ClosePtr Close;
    ConnectPtr Connect;
    FreeAddrInfoPtr FreeAddrInfo;
    GetAddrInfoPtr GetAddrInfo;
    GetLastErrorNumPtr GetLastErrorNum;
    GetLastErrorStrPtr GetLastErrorStr;
    GetNameInfoPtr GetNameInfo;
    GetPeerNamePtr GetPeerName;
    GetSockNamePtr GetSockName;
    GetSockOptPtr GetSockOpt;
    InetAddrPtr InetAddr;
    InetAToNPtr InetAToN;
    InetNToAPtr InetNToA;
    InetNToPPtr InetNToP;
    InetPToNPtr InetPToN;
    IpStackClearPtr IpStackClear;
    IpStackCreatePtr IpStackCreate;
    IpStackFreeAllStacksInfoStrPtr IpStackFreeAllStacksInfoStr;
    IpStackFreeInfoPtr IpStackFreeInfo;
    IpStackGetAllStacksInfoStrPtr IpStackGetAllStacksInfoStr;
    IpStackGetInfoPtr IpStackGetInfo;
    IpStackOpenPtr IpStackOpen;
    IpStackWaitForInterfacePtr IpStackWaitForInterface;
    FdIsSetPtr FdIsSet;
    ListenPtr Listen;
    RecvPtr Recv;
    RecvFromPtr RecvFrom;
    SelectPtr Select;
    SendPtr Send;
    SendToPtr SendTo;
    SetSockOptPtr SetSockOpt;
    ShutdownPtr Shutdown;
    SocketPtr Socket;
    StrErrRPtr StrErrR;
  } FunctionLoadStatus;

  nidevice_grpc::SharedLibrary shared_library_;
  FunctionPointers function_pointers_;
};

}  // namespace nixnetsocket_grpc

#endif  // NIXNETSOCKET_GRPC_LIBRARY_H
