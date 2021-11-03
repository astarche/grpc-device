<%
include_guard_name = "NIDEVICE_GRPC_REGISTER_ALL_SERVICES_H"
namespace = "nidevice_grpc"
%>\
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Register all services header.
//---------------------------------------------------------------------
#ifndef ${include_guard_name}
#define ${include_guard_name}
#include <server/feature_toggles.h>

#include <memory>

namespace grpc {
class ServerBuilder;
}

namespace ${namespace} {

std::shared_ptr<void> register_all_services(
  grpc::ServerBuilder& server_builder,
  const nidevice_grpc::FeatureToggles& feature_toggles,
  nidevice_grpc::FeatureToggles::CodeReadiness code_readiness);

} // ${namespace}

#endif  // ${include_guard_name}
