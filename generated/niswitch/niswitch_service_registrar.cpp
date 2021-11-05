
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service registrar implementation for the NI-SWITCH Metadata
//---------------------------------------------------------------------
#include "niswitch_library.h"

#include <grpcpp/server_builder.h>

#include "niswitch_service.h"
#include "niswitch_service_registrar.h"

namespace niswitch_grpc {

namespace {
struct LibraryAndService {
  LibraryAndService(
    const std::shared_ptr<nidevice_grpc::SessionResourceRepository<ViSession>>& resource_repository,
    const NiSwitchFeatureToggles& feature_toggles) 
      : library(), 
      service(
        &library, 
        resource_repository, 
        feature_toggles) {
  }
  NiSwitchLibrary library;
  NiSwitchService service;
};
}

std::shared_ptr<void> register_service(
  grpc::ServerBuilder& builder, 
  const std::shared_ptr<nidevice_grpc::SessionResourceRepository<ViSession>>& resource_repository,
  const nidevice_grpc::FeatureToggles& feature_toggles)
{
  auto toggles = NiSwitchFeatureToggles(feature_toggles);

  if (toggles.is_enabled)
  {
    auto library_and_service_ptr = std::make_shared<LibraryAndService>(
      resource_repository,
      toggles);
    auto& service = library_and_service_ptr->service;
    builder.RegisterService(&service);
    return library_and_service_ptr;
  }

  return {};
}

} // niswitch_grpc
