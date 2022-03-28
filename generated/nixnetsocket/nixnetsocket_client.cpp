
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// EXPERIMENTAL Client convenience wrapper for NI-XNETSOCKET.
//---------------------------------------------------------------------
#include "nixnetsocket_client.h"

#include <grpcpp/grpcpp.h>

#include <nixnetsocket.grpc.pb.h>

#include <cstdint>
#include <memory>
#include <stdexcept>
#include <vector>

namespace nixnetsocket_grpc::experimental::client {

AcceptResponse
accept(const StubPtr& stub, const nidevice_grpc::Session& socket)
{
  ::grpc::ClientContext context;

  auto request = AcceptRequest{};
  request.mutable_socket()->CopyFrom(socket);

  auto response = AcceptResponse{};

  raise_if_error(
      stub->Accept(&context, request, &response));

  return response;
}

BindResponse
bind(const StubPtr& stub, const nidevice_grpc::Session& socket, const SockAddr& name)
{
  ::grpc::ClientContext context;

  auto request = BindRequest{};
  request.mutable_socket()->CopyFrom(socket);
  request.mutable_name()->CopyFrom(name);

  auto response = BindResponse{};

  raise_if_error(
      stub->Bind(&context, request, &response));

  return response;
}

CloseResponse
close(const StubPtr& stub, const nidevice_grpc::Session& socket)
{
  ::grpc::ClientContext context;

  auto request = CloseRequest{};
  request.mutable_socket()->CopyFrom(socket);

  auto response = CloseResponse{};

  raise_if_error(
      stub->Close(&context, request, &response));

  return response;
}

ConnectResponse
connect(const StubPtr& stub, const nidevice_grpc::Session& socket, const SockAddr& name)
{
  ::grpc::ClientContext context;

  auto request = ConnectRequest{};
  request.mutable_socket()->CopyFrom(socket);
  request.mutable_name()->CopyFrom(name);

  auto response = ConnectResponse{};

  raise_if_error(
      stub->Connect(&context, request, &response));

  return response;
}

GetAddrInfoResponse
get_addr_info(const StubPtr& stub, const nidevice_grpc::Session& stack_ref, const pb::string& node, const pb::string& service, const AddrInfoHint& hints)
{
  ::grpc::ClientContext context;

  auto request = GetAddrInfoRequest{};
  request.mutable_stack_ref()->CopyFrom(stack_ref);
  request.set_node(node);
  request.set_service(service);
  request.mutable_hints()->CopyFrom(hints);

  auto response = GetAddrInfoResponse{};

  raise_if_error(
      stub->GetAddrInfo(&context, request, &response));

  return response;
}

GetNameInfoResponse
get_name_info(const StubPtr& stub, const nidevice_grpc::Session& stack_ref, const SockAddr& addr, const pb::int32& hostlen, const pb::int32& servlen, const simple_variant<GetNameInfoFlags, pb::int32>& flags)
{
  ::grpc::ClientContext context;

  auto request = GetNameInfoRequest{};
  request.mutable_stack_ref()->CopyFrom(stack_ref);
  request.mutable_addr()->CopyFrom(addr);
  request.set_hostlen(hostlen);
  request.set_servlen(servlen);
  const auto flags_ptr = flags.get_if<GetNameInfoFlags>();
  const auto flags_raw_ptr = flags.get_if<pb::int32>();
  if (flags_ptr) {
    request.set_flags(*flags_ptr);
  }
  else if (flags_raw_ptr) {
    request.set_flags_raw(*flags_raw_ptr);
  }

  auto response = GetNameInfoResponse{};

  raise_if_error(
      stub->GetNameInfo(&context, request, &response));

  return response;
}

GetPeerNameResponse
get_peer_name(const StubPtr& stub, const nidevice_grpc::Session& socket)
{
  ::grpc::ClientContext context;

  auto request = GetPeerNameRequest{};
  request.mutable_socket()->CopyFrom(socket);

  auto response = GetPeerNameResponse{};

  raise_if_error(
      stub->GetPeerName(&context, request, &response));

  return response;
}

GetSockNameResponse
get_sock_name(const StubPtr& stub, const nidevice_grpc::Session& socket)
{
  ::grpc::ClientContext context;

  auto request = GetSockNameRequest{};
  request.mutable_socket()->CopyFrom(socket);

  auto response = GetSockNameResponse{};

  raise_if_error(
      stub->GetSockName(&context, request, &response));

  return response;
}

GetSockOptResponse
get_sock_opt(const StubPtr& stub, const nidevice_grpc::Session& socket, const simple_variant<SocketOptionLevel, pb::int32>& level, const simple_variant<OptName, pb::int32>& optname)
{
  ::grpc::ClientContext context;

  auto request = GetSockOptRequest{};
  request.mutable_socket()->CopyFrom(socket);
  const auto level_ptr = level.get_if<SocketOptionLevel>();
  const auto level_raw_ptr = level.get_if<pb::int32>();
  if (level_ptr) {
    request.set_level(*level_ptr);
  }
  else if (level_raw_ptr) {
    request.set_level_raw(*level_raw_ptr);
  }
  const auto optname_ptr = optname.get_if<OptName>();
  const auto optname_raw_ptr = optname.get_if<pb::int32>();
  if (optname_ptr) {
    request.set_optname(*optname_ptr);
  }
  else if (optname_raw_ptr) {
    request.set_optname_raw(*optname_raw_ptr);
  }

  auto response = GetSockOptResponse{};

  raise_if_error(
      stub->GetSockOpt(&context, request, &response));

  return response;
}

InetAddrResponse
inet_addr(const StubPtr& stub, const nidevice_grpc::Session& stack_ref, const pb::string& cp)
{
  ::grpc::ClientContext context;

  auto request = InetAddrRequest{};
  request.mutable_stack_ref()->CopyFrom(stack_ref);
  request.set_cp(cp);

  auto response = InetAddrResponse{};

  raise_if_error(
      stub->InetAddr(&context, request, &response));

  return response;
}

InetAToNResponse
inet_a_to_n(const StubPtr& stub, const nidevice_grpc::Session& stack_ref, const pb::string& cp)
{
  ::grpc::ClientContext context;

  auto request = InetAToNRequest{};
  request.mutable_stack_ref()->CopyFrom(stack_ref);
  request.set_cp(cp);

  auto response = InetAToNResponse{};

  raise_if_error(
      stub->InetAToN(&context, request, &response));

  return response;
}

InetNToAResponse
inet_n_to_a(const StubPtr& stub, const nidevice_grpc::Session& stack_ref, const InAddr& in_parameter)
{
  ::grpc::ClientContext context;

  auto request = InetNToARequest{};
  request.mutable_stack_ref()->CopyFrom(stack_ref);
  request.mutable_in()->CopyFrom(in_parameter);

  auto response = InetNToAResponse{};

  raise_if_error(
      stub->InetNToA(&context, request, &response));

  return response;
}

InetNToPResponse
inet_n_to_p(const StubPtr& stub, const nidevice_grpc::Session& stack_ref, const Addr& src)
{
  ::grpc::ClientContext context;

  auto request = InetNToPRequest{};
  request.mutable_stack_ref()->CopyFrom(stack_ref);
  request.mutable_src()->CopyFrom(src);

  auto response = InetNToPResponse{};

  raise_if_error(
      stub->InetNToP(&context, request, &response));

  return response;
}

InetPToNResponse
inet_p_to_n(const StubPtr& stub, const nidevice_grpc::Session& stack_ref, const pb::int32& af, const pb::string& src)
{
  ::grpc::ClientContext context;

  auto request = InetPToNRequest{};
  request.mutable_stack_ref()->CopyFrom(stack_ref);
  request.set_af(af);
  request.set_src(src);

  auto response = InetPToNResponse{};

  raise_if_error(
      stub->InetPToN(&context, request, &response));

  return response;
}

IpStackClearResponse
ip_stack_clear(const StubPtr& stub, const nidevice_grpc::Session& stack_ref)
{
  ::grpc::ClientContext context;

  auto request = IpStackClearRequest{};
  request.mutable_stack_ref()->CopyFrom(stack_ref);

  auto response = IpStackClearResponse{};

  raise_if_error(
      stub->IpStackClear(&context, request, &response));

  return response;
}

IpStackCreateResponse
ip_stack_create(const StubPtr& stub, const pb::string& stack_name, const pb::string& config)
{
  ::grpc::ClientContext context;

  auto request = IpStackCreateRequest{};
  request.set_stack_name(stack_name);
  request.set_config(config);

  auto response = IpStackCreateResponse{};

  raise_if_error(
      stub->IpStackCreate(&context, request, &response));

  return response;
}

IpStackGetAllStacksInfoStrResponse
ip_stack_get_all_stacks_info_str(const StubPtr& stub)
{
  ::grpc::ClientContext context;

  auto request = IpStackGetAllStacksInfoStrRequest{};

  auto response = IpStackGetAllStacksInfoStrResponse{};

  raise_if_error(
      stub->IpStackGetAllStacksInfoStr(&context, request, &response));

  return response;
}

IpStackGetInfoResponse
ip_stack_get_info(const StubPtr& stub, const nidevice_grpc::Session& stack_ref)
{
  ::grpc::ClientContext context;

  auto request = IpStackGetInfoRequest{};
  request.mutable_stack_ref()->CopyFrom(stack_ref);

  auto response = IpStackGetInfoResponse{};

  raise_if_error(
      stub->IpStackGetInfo(&context, request, &response));

  return response;
}

IpStackOpenResponse
ip_stack_open(const StubPtr& stub, const pb::string& stack_name)
{
  ::grpc::ClientContext context;

  auto request = IpStackOpenRequest{};
  request.set_stack_name(stack_name);

  auto response = IpStackOpenResponse{};

  raise_if_error(
      stub->IpStackOpen(&context, request, &response));

  return response;
}

IpStackWaitForInterfaceResponse
ip_stack_wait_for_interface(const StubPtr& stub, const nidevice_grpc::Session& stack_ref, const pb::string& local_interface, const pb::int32& timeout_ms)
{
  ::grpc::ClientContext context;

  auto request = IpStackWaitForInterfaceRequest{};
  request.mutable_stack_ref()->CopyFrom(stack_ref);
  request.set_local_interface(local_interface);
  request.set_timeout_ms(timeout_ms);

  auto response = IpStackWaitForInterfaceResponse{};

  raise_if_error(
      stub->IpStackWaitForInterface(&context, request, &response));

  return response;
}

FdIsSetResponse
fd_is_set(const StubPtr& stub, const nidevice_grpc::Session& fd, const std::vector<nidevice_grpc::Session>& set)
{
  ::grpc::ClientContext context;

  auto request = FdIsSetRequest{};
  request.mutable_fd()->CopyFrom(fd);
  copy_array(set, request.mutable_set());

  auto response = FdIsSetResponse{};

  raise_if_error(
      stub->FdIsSet(&context, request, &response));

  return response;
}

ListenResponse
listen(const StubPtr& stub, const nidevice_grpc::Session& socket, const pb::int32& backlog)
{
  ::grpc::ClientContext context;

  auto request = ListenRequest{};
  request.mutable_socket()->CopyFrom(socket);
  request.set_backlog(backlog);

  auto response = ListenResponse{};

  raise_if_error(
      stub->Listen(&context, request, &response));

  return response;
}

RecvResponse
recv(const StubPtr& stub, const nidevice_grpc::Session& socket, const pb::int32& size, const pb::int32& flags)
{
  ::grpc::ClientContext context;

  auto request = RecvRequest{};
  request.mutable_socket()->CopyFrom(socket);
  request.set_size(size);
  request.set_flags(flags);

  auto response = RecvResponse{};

  raise_if_error(
      stub->Recv(&context, request, &response));

  return response;
}

RecvFromResponse
recv_from(const StubPtr& stub, const nidevice_grpc::Session& socket, const pb::int32& size, const pb::int32& flags)
{
  ::grpc::ClientContext context;

  auto request = RecvFromRequest{};
  request.mutable_socket()->CopyFrom(socket);
  request.set_size(size);
  request.set_flags(flags);

  auto response = RecvFromResponse{};

  raise_if_error(
      stub->RecvFrom(&context, request, &response));

  return response;
}

SelectResponse
select(const StubPtr& stub, const std::vector<nidevice_grpc::Session>& readfds, const std::vector<nidevice_grpc::Session>& writefds, const std::vector<nidevice_grpc::Session>& exceptfds, const google::protobuf::Duration& timeout)
{
  ::grpc::ClientContext context;

  auto request = SelectRequest{};
  copy_array(readfds, request.mutable_readfds());
  copy_array(writefds, request.mutable_writefds());
  copy_array(exceptfds, request.mutable_exceptfds());
  request.mutable_timeout()->CopyFrom(timeout);

  auto response = SelectResponse{};

  raise_if_error(
      stub->Select(&context, request, &response));

  return response;
}

SendResponse
send(const StubPtr& stub, const nidevice_grpc::Session& socket, const pb::string& dataptr, const pb::int32& flags)
{
  ::grpc::ClientContext context;

  auto request = SendRequest{};
  request.mutable_socket()->CopyFrom(socket);
  request.set_dataptr(dataptr);
  request.set_flags(flags);

  auto response = SendResponse{};

  raise_if_error(
      stub->Send(&context, request, &response));

  return response;
}

SendToResponse
send_to(const StubPtr& stub, const nidevice_grpc::Session& socket, const pb::string& dataptr, const pb::int32& flags, const SockAddr& to)
{
  ::grpc::ClientContext context;

  auto request = SendToRequest{};
  request.mutable_socket()->CopyFrom(socket);
  request.set_dataptr(dataptr);
  request.set_flags(flags);
  request.mutable_to()->CopyFrom(to);

  auto response = SendToResponse{};

  raise_if_error(
      stub->SendTo(&context, request, &response));

  return response;
}

SetSockOptResponse
set_sock_opt(const StubPtr& stub, const nidevice_grpc::Session& socket, const simple_variant<SocketOptionLevel, pb::int32>& level, const simple_variant<OptName, pb::int32>& optname, const SockOptData& opt_data)
{
  ::grpc::ClientContext context;

  auto request = SetSockOptRequest{};
  request.mutable_socket()->CopyFrom(socket);
  const auto level_ptr = level.get_if<SocketOptionLevel>();
  const auto level_raw_ptr = level.get_if<pb::int32>();
  if (level_ptr) {
    request.set_level(*level_ptr);
  }
  else if (level_raw_ptr) {
    request.set_level_raw(*level_raw_ptr);
  }
  const auto optname_ptr = optname.get_if<OptName>();
  const auto optname_raw_ptr = optname.get_if<pb::int32>();
  if (optname_ptr) {
    request.set_optname(*optname_ptr);
  }
  else if (optname_raw_ptr) {
    request.set_optname_raw(*optname_raw_ptr);
  }
  request.mutable_opt_data()->CopyFrom(opt_data);

  auto response = SetSockOptResponse{};

  raise_if_error(
      stub->SetSockOpt(&context, request, &response));

  return response;
}

ShutdownResponse
shutdown(const StubPtr& stub, const nidevice_grpc::Session& socket, const simple_variant<Shutdown, pb::int32>& how)
{
  ::grpc::ClientContext context;

  auto request = ShutdownRequest{};
  request.mutable_socket()->CopyFrom(socket);
  const auto how_ptr = how.get_if<Shutdown>();
  const auto how_raw_ptr = how.get_if<pb::int32>();
  if (how_ptr) {
    request.set_how(*how_ptr);
  }
  else if (how_raw_ptr) {
    request.set_how_raw(*how_raw_ptr);
  }

  auto response = ShutdownResponse{};

  raise_if_error(
      stub->Shutdown(&context, request, &response));

  return response;
}

SocketResponse
socket(const StubPtr& stub, const nidevice_grpc::Session& stack_ref, const simple_variant<AddressFamily, pb::int32>& domain, const simple_variant<SocketProtocolType, pb::int32>& type, const simple_variant<IPProtocol, pb::int32>& prototcol)
{
  ::grpc::ClientContext context;

  auto request = SocketRequest{};
  request.mutable_stack_ref()->CopyFrom(stack_ref);
  const auto domain_ptr = domain.get_if<AddressFamily>();
  const auto domain_raw_ptr = domain.get_if<pb::int32>();
  if (domain_ptr) {
    request.set_domain(*domain_ptr);
  }
  else if (domain_raw_ptr) {
    request.set_domain_raw(*domain_raw_ptr);
  }
  const auto type_ptr = type.get_if<SocketProtocolType>();
  const auto type_raw_ptr = type.get_if<pb::int32>();
  if (type_ptr) {
    request.set_type(*type_ptr);
  }
  else if (type_raw_ptr) {
    request.set_type_raw(*type_raw_ptr);
  }
  const auto prototcol_ptr = prototcol.get_if<IPProtocol>();
  const auto prototcol_raw_ptr = prototcol.get_if<pb::int32>();
  if (prototcol_ptr) {
    request.set_prototcol(*prototcol_ptr);
  }
  else if (prototcol_raw_ptr) {
    request.set_prototcol_raw(*prototcol_raw_ptr);
  }

  auto response = SocketResponse{};

  raise_if_error(
      stub->Socket(&context, request, &response));

  return response;
}

StrErrRResponse
str_err_r(const StubPtr& stub, const pb::int32& errnum, const pb::uint64& buf_len)
{
  ::grpc::ClientContext context;

  auto request = StrErrRRequest{};
  request.set_errnum(errnum);
  request.set_buf_len(buf_len);

  auto response = StrErrRResponse{};

  raise_if_error(
      stub->StrErrR(&context, request, &response));

  return response;
}


} // namespace nixnetsocket_grpc::experimental::client
