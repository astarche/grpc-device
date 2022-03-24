
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// EXPERIMENTAL Client convenience wrapper for NI-XNETSOCKET.
//---------------------------------------------------------------------
#ifndef NIXNETSOCKET_GRPC_CLIENT_H
#define NIXNETSOCKET_GRPC_CLIENT_H

#include <grpcpp/grpcpp.h>

#include <nixnetsocket.grpc.pb.h>
#include <tests/utilities/client_helpers.h>

#include <memory>
#include <vector>

namespace nixnetsocket_grpc::experimental::client {

namespace pb = ::google::protobuf;
using StubPtr = std::unique_ptr<NiXnetSocket::Stub>;
using namespace nidevice_grpc::experimental::client;


AcceptResponse accept(const StubPtr& stub, const nidevice_grpc::Session& socket);
BindResponse bind(const StubPtr& stub, const nidevice_grpc::Session& socket, const SockAddr& name);
ConnectResponse connect(const StubPtr& stub, const nidevice_grpc::Session& socket, const SockAddr& name);
InetAddrResponse inet_addr(const StubPtr& stub, const nidevice_grpc::Session& stack_ref, const pb::string& cp);
InetAToNResponse inet_a_to_n(const StubPtr& stub, const nidevice_grpc::Session& stack_ref, const pb::string& cp);
InetNToAResponse inet_n_to_a(const StubPtr& stub, const nidevice_grpc::Session& stack_ref, const IPv4Addr& in_parameter);
InetNToPResponse inet_n_to_p(const StubPtr& stub, const nidevice_grpc::Session& stack_ref, const Addr& src);
InetPToNResponse inet_p_to_n(const StubPtr& stub, const nidevice_grpc::Session& stack_ref, const pb::int32& af, const pb::string& src);
GetAddrInfoResponse get_addr_info(const StubPtr& stub, const nidevice_grpc::Session& stack_ref, const pb::string& node, const pb::string& service, const AddrInfoHint& hints);
GetNameInfoResponse get_name_info(const StubPtr& stub, const nidevice_grpc::Session& stack_ref, const SockAddr& addr, const pb::int32& host_len, const pb::int32& serv_len, const pb::int32& flags);
ListenResponse listen(const StubPtr& stub, const nidevice_grpc::Session& socket, const pb::int32& backlog);
SendToResponse send_to(const StubPtr& stub, const nidevice_grpc::Session& socket, const pb::string& dataptr, const pb::int32& flags, const SockAddr& to);
SendResponse send(const StubPtr& stub, const nidevice_grpc::Session& socket, const pb::string& dataptr, const pb::int32& flags);
RecvFromResponse recv_from(const StubPtr& stub, const nidevice_grpc::Session& socket, const pb::int32& size, const pb::int32& flags);
RecvResponse recv(const StubPtr& stub, const nidevice_grpc::Session& socket, const pb::int32& size, const pb::int32& flags);
GetSockNameResponse get_sock_name(const StubPtr& stub, const nidevice_grpc::Session& socket);
GetPeerNameResponse get_peer_name(const StubPtr& stub, const nidevice_grpc::Session& socket);
ShutdownResponse shutdown(const StubPtr& stub, const nidevice_grpc::Session& socket, const simple_variant<Shutdown, pb::int32>& how);
CloseResponse close(const StubPtr& stub, const nidevice_grpc::Session& socket);
GetSockOptResponse get_sock_opt(const StubPtr& stub, const nidevice_grpc::Session& socket, const simple_variant<SocketOptionLevel, pb::int32>& level, const simple_variant<OptName, pb::int32>& optname);
IpStackClearResponse ip_stack_clear(const StubPtr& stub, const nidevice_grpc::Session& stack_ref);
IpStackCreateResponse ip_stack_create(const StubPtr& stub, const pb::string& stack_name, const pb::string& config);
IpStackGetAllStacksInfoStrResponse ip_stack_get_all_stacks_info_str(const StubPtr& stub);
IpStackGetInfoResponse ip_stack_get_info(const StubPtr& stub, const nidevice_grpc::Session& stack_ref);
IpStackOpenResponse ip_stack_open(const StubPtr& stub, const pb::string& stack_name);
IpStackWaitForInterfaceResponse ip_stack_wait_for_interface(const StubPtr& stub, const nidevice_grpc::Session& stack_ref, const pb::string& local_interface, const pb::int32& timeout_ms);
IsSetResponse is_set(const StubPtr& stub, const nidevice_grpc::Session& fd, const std::vector<nidevice_grpc::Session>& set);
SelectResponse select(const StubPtr& stub, const std::vector<nidevice_grpc::Session>& read_fds, const std::vector<nidevice_grpc::Session>& write_fds, const std::vector<nidevice_grpc::Session>& except_fds, const google::protobuf::Duration& timeout);
SetSockOptResponse set_sock_opt(const StubPtr& stub, const nidevice_grpc::Session& socket, const simple_variant<SocketOptionLevel, pb::int32>& level, const simple_variant<OptName, pb::int32>& optname, const SockOptData& opt_data);
SocketResponse socket(const StubPtr& stub, const nidevice_grpc::Session& stack_ref, const simple_variant<AddressFamily, pb::int32>& domain, const simple_variant<SocketProtocolType, pb::int32>& type, const simple_variant<IPProtocol, pb::int32>& prototcol);
StrErrRResponse str_err_r(const StubPtr& stub, const pb::int32& errnum, const pb::uint64& buf_len);

} // namespace nixnetsocket_grpc::experimental::client

#endif /* NIXNETSOCKET_GRPC_CLIENT_H */
