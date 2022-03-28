//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service implementation for the NI-XNETSOCKET Metadata
//---------------------------------------------------------------------
#include "nixnetsocket_library.h"

#if defined(_MSC_VER)
static const char* kLibraryName = "nixntipstack.dll";
#else
static const char* kLibraryName = "libnixntipstack.so.1";
#endif

namespace nixnetsocket_grpc {

NiXnetSocketLibrary::NiXnetSocketLibrary() : shared_library_(kLibraryName)
{
  shared_library_.load();
  bool loaded = shared_library_.is_loaded();
  memset(&function_pointers_, 0, sizeof(function_pointers_));
  if (!loaded) {
    return;
  }
  function_pointers_.Accept = reinterpret_cast<AcceptPtr>(shared_library_.get_function_pointer("nxaccept"));
  function_pointers_.Bind = reinterpret_cast<BindPtr>(shared_library_.get_function_pointer("nxbind"));
  function_pointers_.Close = reinterpret_cast<ClosePtr>(shared_library_.get_function_pointer("nxclose"));
  function_pointers_.Connect = reinterpret_cast<ConnectPtr>(shared_library_.get_function_pointer("nxconnect"));
  function_pointers_.FreeAddrInfo = reinterpret_cast<FreeAddrInfoPtr>(shared_library_.get_function_pointer("nxfreeaddrinfo"));
  function_pointers_.GetAddrInfo = reinterpret_cast<GetAddrInfoPtr>(shared_library_.get_function_pointer("nxgetaddrinfo"));
  function_pointers_.GetLastErrorNum = reinterpret_cast<GetLastErrorNumPtr>(shared_library_.get_function_pointer("nxgetlasterrornum"));
  function_pointers_.GetLastErrorStr = reinterpret_cast<GetLastErrorStrPtr>(shared_library_.get_function_pointer("nxgetlasterrorstr"));
  function_pointers_.GetNameInfo = reinterpret_cast<GetNameInfoPtr>(shared_library_.get_function_pointer("nxgetnameinfo"));
  function_pointers_.GetPeerName = reinterpret_cast<GetPeerNamePtr>(shared_library_.get_function_pointer("nxgetpeername"));
  function_pointers_.GetSockName = reinterpret_cast<GetSockNamePtr>(shared_library_.get_function_pointer("nxgetsockname"));
  function_pointers_.GetSockOpt = reinterpret_cast<GetSockOptPtr>(shared_library_.get_function_pointer("nxgetsockopt"));
  function_pointers_.InetAddr = reinterpret_cast<InetAddrPtr>(shared_library_.get_function_pointer("nxinet_addr"));
  function_pointers_.InetAToN = reinterpret_cast<InetAToNPtr>(shared_library_.get_function_pointer("nxinet_aton"));
  function_pointers_.InetNToA = reinterpret_cast<InetNToAPtr>(shared_library_.get_function_pointer("nxinet_ntoa"));
  function_pointers_.InetNToP = reinterpret_cast<InetNToPPtr>(shared_library_.get_function_pointer("nxinet_ntop"));
  function_pointers_.InetPToN = reinterpret_cast<InetPToNPtr>(shared_library_.get_function_pointer("nxinet_pton"));
  function_pointers_.IpStackClear = reinterpret_cast<IpStackClearPtr>(shared_library_.get_function_pointer("nxIpStackClear"));
  function_pointers_.IpStackCreate = reinterpret_cast<IpStackCreatePtr>(shared_library_.get_function_pointer("nxIpStackCreate"));
  function_pointers_.IpStackFreeAllStacksInfoStr = reinterpret_cast<IpStackFreeAllStacksInfoStrPtr>(shared_library_.get_function_pointer("nxIpStackFreeAllStacksInfoStr"));
  function_pointers_.IpStackFreeInfo = reinterpret_cast<IpStackFreeInfoPtr>(shared_library_.get_function_pointer("nxIpStackFreeInfo"));
  function_pointers_.IpStackGetAllStacksInfoStr = reinterpret_cast<IpStackGetAllStacksInfoStrPtr>(shared_library_.get_function_pointer("nxIpStackGetAllStacksInfoStr"));
  function_pointers_.IpStackGetInfo = reinterpret_cast<IpStackGetInfoPtr>(shared_library_.get_function_pointer("nxIpStackGetInfo"));
  function_pointers_.IpStackOpen = reinterpret_cast<IpStackOpenPtr>(shared_library_.get_function_pointer("nxIpStackOpen"));
  function_pointers_.IpStackWaitForInterface = reinterpret_cast<IpStackWaitForInterfacePtr>(shared_library_.get_function_pointer("nxIpStackWaitForInterface"));
  function_pointers_.IsSet = reinterpret_cast<IsSetPtr>(shared_library_.get_function_pointer("nxfd_isset"));
  function_pointers_.Listen = reinterpret_cast<ListenPtr>(shared_library_.get_function_pointer("nxlisten"));
  function_pointers_.Recv = reinterpret_cast<RecvPtr>(shared_library_.get_function_pointer("nxrecv"));
  function_pointers_.RecvFrom = reinterpret_cast<RecvFromPtr>(shared_library_.get_function_pointer("nxrecvfrom"));
  function_pointers_.Select = reinterpret_cast<SelectPtr>(shared_library_.get_function_pointer("nxselect"));
  function_pointers_.Send = reinterpret_cast<SendPtr>(shared_library_.get_function_pointer("nxsend"));
  function_pointers_.SendTo = reinterpret_cast<SendToPtr>(shared_library_.get_function_pointer("nxsendto"));
  function_pointers_.SetSockOpt = reinterpret_cast<SetSockOptPtr>(shared_library_.get_function_pointer("nxsetsockopt"));
  function_pointers_.Shutdown = reinterpret_cast<ShutdownPtr>(shared_library_.get_function_pointer("nxshutdown"));
  function_pointers_.Socket = reinterpret_cast<SocketPtr>(shared_library_.get_function_pointer("nxsocket"));
  function_pointers_.StrErrR = reinterpret_cast<StrErrRPtr>(shared_library_.get_function_pointer("nxstrerr_r"));
}

NiXnetSocketLibrary::~NiXnetSocketLibrary()
{
}

::grpc::Status NiXnetSocketLibrary::check_function_exists(std::string functionName)
{
  return shared_library_.function_exists(functionName.c_str())
    ? ::grpc::Status::OK
    : ::grpc::Status(::grpc::NOT_FOUND, "Could not find the function " + functionName);
}

nxSOCKET NiXnetSocketLibrary::Accept(nxSOCKET socket, nxsockaddr* addr, nxsocklen_t* addrlen)
{
  if (!function_pointers_.Accept) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxaccept.");
  }
#if defined(_MSC_VER)
  return nxaccept(socket, addr, addrlen);
#else
  return function_pointers_.Accept(socket, addr, addrlen);
#endif
}

int32_t NiXnetSocketLibrary::Bind(nxSOCKET socket, nxsockaddr* name, nxsocklen_t namelen)
{
  if (!function_pointers_.Bind) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxbind.");
  }
#if defined(_MSC_VER)
  return nxbind(socket, name, namelen);
#else
  return function_pointers_.Bind(socket, name, namelen);
#endif
}

int32_t NiXnetSocketLibrary::Close(nxSOCKET socket)
{
  if (!function_pointers_.Close) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxclose.");
  }
#if defined(_MSC_VER)
  return nxclose(socket);
#else
  return function_pointers_.Close(socket);
#endif
}

int32_t NiXnetSocketLibrary::Connect(nxSOCKET socket, nxsockaddr* name, nxsocklen_t namelen)
{
  if (!function_pointers_.Connect) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxconnect.");
  }
#if defined(_MSC_VER)
  return nxconnect(socket, name, namelen);
#else
  return function_pointers_.Connect(socket, name, namelen);
#endif
}

int32_t NiXnetSocketLibrary::FreeAddrInfo(nxaddrinfo* res)
{
  if (!function_pointers_.FreeAddrInfo) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxfreeaddrinfo.");
  }
  return function_pointers_.FreeAddrInfo(res);
}

int32_t NiXnetSocketLibrary::GetAddrInfo(nxIpStackRef_t stack_ref, const char node_api[], const char service_api[], nxaddrinfo* hints, nxaddrinfo** res)
{
  if (!function_pointers_.GetAddrInfo) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxgetaddrinfo.");
  }
#if defined(_MSC_VER)
  return nxgetaddrinfo(stack_ref, node_api, service_api, hints, res);
#else
  return function_pointers_.GetAddrInfo(stack_ref, node_api, service_api, hints, res);
#endif
}

int32_t NiXnetSocketLibrary::GetLastErrorNum()
{
  if (!function_pointers_.GetLastErrorNum) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxgetlasterrornum.");
  }
  return function_pointers_.GetLastErrorNum();
}

char* NiXnetSocketLibrary::GetLastErrorStr(char buf[], size_t bufLen)
{
  if (!function_pointers_.GetLastErrorStr) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxgetlasterrorstr.");
  }
  return function_pointers_.GetLastErrorStr(buf, bufLen);
}

int32_t NiXnetSocketLibrary::GetNameInfo(nxIpStackRef_t stack_ref, nxsockaddr* addr, nxsocklen_t addr_len, char host[], nxsocklen_t host_len, char serv[], nxsocklen_t serv_len, int32_t flags)
{
  if (!function_pointers_.GetNameInfo) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxgetnameinfo.");
  }
#if defined(_MSC_VER)
  return nxgetnameinfo(stack_ref, addr, addr_len, host, host_len, serv, serv_len, flags);
#else
  return function_pointers_.GetNameInfo(stack_ref, addr, addr_len, host, host_len, serv, serv_len, flags);
#endif
}

int32_t NiXnetSocketLibrary::GetPeerName(nxSOCKET socket, nxsockaddr* addr, nxsocklen_t* addrlen)
{
  if (!function_pointers_.GetPeerName) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxgetpeername.");
  }
#if defined(_MSC_VER)
  return nxgetpeername(socket, addr, addrlen);
#else
  return function_pointers_.GetPeerName(socket, addr, addrlen);
#endif
}

int32_t NiXnetSocketLibrary::GetSockName(nxSOCKET socket, nxsockaddr* addr, nxsocklen_t* addrlen)
{
  if (!function_pointers_.GetSockName) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxgetsockname.");
  }
#if defined(_MSC_VER)
  return nxgetsockname(socket, addr, addrlen);
#else
  return function_pointers_.GetSockName(socket, addr, addrlen);
#endif
}

int32_t NiXnetSocketLibrary::GetSockOpt(nxSOCKET socket, int32_t level, int32_t optname, void* optval, nxsocklen_t* optlen)
{
  if (!function_pointers_.GetSockOpt) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxgetsockopt.");
  }
#if defined(_MSC_VER)
  return nxgetsockopt(socket, level, optname, optval, optlen);
#else
  return function_pointers_.GetSockOpt(socket, level, optname, optval, optlen);
#endif
}

uint32_t NiXnetSocketLibrary::InetAddr(nxIpStackRef_t stack_ref, const char cp[])
{
  if (!function_pointers_.InetAddr) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxinet_addr.");
  }
#if defined(_MSC_VER)
  return nxinet_addr(stack_ref, cp);
#else
  return function_pointers_.InetAddr(stack_ref, cp);
#endif
}

int32_t NiXnetSocketLibrary::InetAToN(nxIpStackRef_t stack_ref, const char cp[], nxin_addr* name)
{
  if (!function_pointers_.InetAToN) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxinet_aton.");
  }
#if defined(_MSC_VER)
  return nxinet_aton(stack_ref, cp, name);
#else
  return function_pointers_.InetAToN(stack_ref, cp, name);
#endif
}

char* NiXnetSocketLibrary::InetNToA(nxIpStackRef_t stack_ref, nxin_addr inParameter)
{
  if (!function_pointers_.InetNToA) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxinet_ntoa.");
  }
#if defined(_MSC_VER)
  return nxinet_ntoa(stack_ref, inParameter);
#else
  return function_pointers_.InetNToA(stack_ref, inParameter);
#endif
}

const char* NiXnetSocketLibrary::InetNToP(nxIpStackRef_t stack_ref, int32_t af, void* src, char dst[nxINET6_ADDRSTRLEN], nxsocklen_t size)
{
  if (!function_pointers_.InetNToP) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxinet_ntop.");
  }
#if defined(_MSC_VER)
  return nxinet_ntop(stack_ref, af, src, dst, size);
#else
  return function_pointers_.InetNToP(stack_ref, af, src, dst, size);
#endif
}

int32_t NiXnetSocketLibrary::InetPToN(nxIpStackRef_t stack_ref, int32_t af, const char src[], void* dst)
{
  if (!function_pointers_.InetPToN) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxinet_pton.");
  }
#if defined(_MSC_VER)
  return nxinet_pton(stack_ref, af, src, dst);
#else
  return function_pointers_.InetPToN(stack_ref, af, src, dst);
#endif
}

int32_t NiXnetSocketLibrary::IpStackClear(nxIpStackRef_t stack_ref)
{
  if (!function_pointers_.IpStackClear) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxIpStackClear.");
  }
#if defined(_MSC_VER)
  return nxIpStackClear(stack_ref);
#else
  return function_pointers_.IpStackClear(stack_ref);
#endif
}

int32_t NiXnetSocketLibrary::IpStackCreate(char stack_name[], char config[], nxIpStackRef_t* stack_ref)
{
  if (!function_pointers_.IpStackCreate) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxIpStackCreate.");
  }
#if defined(_MSC_VER)
  return nxIpStackCreate(stack_name, config, stack_ref);
#else
  return function_pointers_.IpStackCreate(stack_name, config, stack_ref);
#endif
}

void NiXnetSocketLibrary::IpStackFreeAllStacksInfoStr(nixnetsocket_grpc::IpStackInfoString info)
{
  if (!function_pointers_.IpStackFreeAllStacksInfoStr) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxIpStackFreeAllStacksInfoStr.");
  }
  return function_pointers_.IpStackFreeAllStacksInfoStr(info);
}

int32_t NiXnetSocketLibrary::IpStackFreeInfo(nxVirtualInterface_t* firstVirtualInterface)
{
  if (!function_pointers_.IpStackFreeInfo) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxIpStackFreeInfo.");
  }
  return function_pointers_.IpStackFreeInfo(firstVirtualInterface);
}

int32_t NiXnetSocketLibrary::IpStackGetAllStacksInfoStr(uint32_t format, nixnetsocket_grpc::IpStackInfoString* info)
{
  if (!function_pointers_.IpStackGetAllStacksInfoStr) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxIpStackGetAllStacksInfoStr.");
  }
#if defined(_MSC_VER)
  return nxIpStackGetAllStacksInfoStr(format, info);
#else
  return function_pointers_.IpStackGetAllStacksInfoStr(format, info);
#endif
}

int32_t NiXnetSocketLibrary::IpStackGetInfo(nxIpStackRef_t stack_ref, uint32_t info_id, nxVirtualInterface_t** virtual_interfaces)
{
  if (!function_pointers_.IpStackGetInfo) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxIpStackGetInfo.");
  }
#if defined(_MSC_VER)
  return nxIpStackGetInfo(stack_ref, info_id, virtual_interfaces);
#else
  return function_pointers_.IpStackGetInfo(stack_ref, info_id, virtual_interfaces);
#endif
}

int32_t NiXnetSocketLibrary::IpStackOpen(char stack_name[], nxIpStackRef_t* stack_ref)
{
  if (!function_pointers_.IpStackOpen) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxIpStackOpen.");
  }
#if defined(_MSC_VER)
  return nxIpStackOpen(stack_name, stack_ref);
#else
  return function_pointers_.IpStackOpen(stack_name, stack_ref);
#endif
}

int32_t NiXnetSocketLibrary::IpStackWaitForInterface(nxIpStackRef_t stack_ref, const char localInterface[], int32_t timeoutMs)
{
  if (!function_pointers_.IpStackWaitForInterface) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxIpStackWaitForInterface.");
  }
#if defined(_MSC_VER)
  return nxIpStackWaitForInterface(stack_ref, localInterface, timeoutMs);
#else
  return function_pointers_.IpStackWaitForInterface(stack_ref, localInterface, timeoutMs);
#endif
}

int32_t NiXnetSocketLibrary::IsSet(nxSOCKET fd, nxfd_set* set)
{
  if (!function_pointers_.IsSet) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxfd_isset.");
  }
#if defined(_MSC_VER)
  return nxfd_isset(fd, set);
#else
  return function_pointers_.IsSet(fd, set);
#endif
}

int32_t NiXnetSocketLibrary::Listen(nxSOCKET socket, int32_t backlog)
{
  if (!function_pointers_.Listen) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxlisten.");
  }
#if defined(_MSC_VER)
  return nxlisten(socket, backlog);
#else
  return function_pointers_.Listen(socket, backlog);
#endif
}

int32_t NiXnetSocketLibrary::Recv(nxSOCKET socket, char mem[], int32_t size, int32_t flags)
{
  if (!function_pointers_.Recv) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxrecv.");
  }
#if defined(_MSC_VER)
  return nxrecv(socket, mem, size, flags);
#else
  return function_pointers_.Recv(socket, mem, size, flags);
#endif
}

int32_t NiXnetSocketLibrary::RecvFrom(nxSOCKET socket, char mem[], int32_t size, int32_t flags, nxsockaddr* from, nxsocklen_t* fromlen)
{
  if (!function_pointers_.RecvFrom) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxrecvfrom.");
  }
#if defined(_MSC_VER)
  return nxrecvfrom(socket, mem, size, flags, from, fromlen);
#else
  return function_pointers_.RecvFrom(socket, mem, size, flags, from, fromlen);
#endif
}

int32_t NiXnetSocketLibrary::Select(int32_t nfds, nxfd_set* read_fds, nxfd_set* write_fds, nxfd_set* except_fds, nxtimeval* timeout)
{
  if (!function_pointers_.Select) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxselect.");
  }
#if defined(_MSC_VER)
  return nxselect(nfds, read_fds, write_fds, except_fds, timeout);
#else
  return function_pointers_.Select(nfds, read_fds, write_fds, except_fds, timeout);
#endif
}

int32_t NiXnetSocketLibrary::Send(nxSOCKET socket, char dataptr[], int32_t size, int32_t flags)
{
  if (!function_pointers_.Send) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxsend.");
  }
#if defined(_MSC_VER)
  return nxsend(socket, dataptr, size, flags);
#else
  return function_pointers_.Send(socket, dataptr, size, flags);
#endif
}

int32_t NiXnetSocketLibrary::SendTo(nxSOCKET socket, char dataptr[], int32_t size, int32_t flags, nxsockaddr* to, nxsocklen_t tolen)
{
  if (!function_pointers_.SendTo) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxsendto.");
  }
#if defined(_MSC_VER)
  return nxsendto(socket, dataptr, size, flags, to, tolen);
#else
  return function_pointers_.SendTo(socket, dataptr, size, flags, to, tolen);
#endif
}

int32_t NiXnetSocketLibrary::SetSockOpt(nxSOCKET socket, int32_t level, int32_t optname, void* optval, nxsocklen_t optlen)
{
  if (!function_pointers_.SetSockOpt) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxsetsockopt.");
  }
#if defined(_MSC_VER)
  return nxsetsockopt(socket, level, optname, optval, optlen);
#else
  return function_pointers_.SetSockOpt(socket, level, optname, optval, optlen);
#endif
}

int32_t NiXnetSocketLibrary::Shutdown(nxSOCKET socket, int32_t how)
{
  if (!function_pointers_.Shutdown) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxshutdown.");
  }
#if defined(_MSC_VER)
  return nxshutdown(socket, how);
#else
  return function_pointers_.Shutdown(socket, how);
#endif
}

nxSOCKET NiXnetSocketLibrary::Socket(nxIpStackRef_t stack_ref, int32_t domain, int32_t type, int32_t prototcol)
{
  if (!function_pointers_.Socket) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxsocket.");
  }
#if defined(_MSC_VER)
  return nxsocket(stack_ref, domain, type, prototcol);
#else
  return function_pointers_.Socket(stack_ref, domain, type, prototcol);
#endif
}

char* NiXnetSocketLibrary::StrErrR(int errnum, char buf[], size_t bufLen)
{
  if (!function_pointers_.StrErrR) {
    throw nidevice_grpc::LibraryLoadException("Could not find nxstrerr_r.");
  }
#if defined(_MSC_VER)
  return nxstrerr_r(errnum, buf, bufLen);
#else
  return function_pointers_.StrErrR(errnum, buf, bufLen);
#endif
}

}  // namespace nixnetsocket_grpc
