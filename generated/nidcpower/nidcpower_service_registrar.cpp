
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service registrar implementation for the NI-DCPower Metadata
//---------------------------------------------------------------------
#include "nidcpower_library.h"

#include <grpcpp/server_builder.h>

#include "nidcpower_service.h"
#include "nidcpower_service_registrar.h"

namespace nidcpower_grpc {

namespace {
struct LibraryAndService {
  LibraryAndService(
    const std::shared_ptr<nidevice_grpc::SessionResourceRepository<ViSession>>& resource_repository,
    const NiDCPowerFeatureToggles& feature_toggles) 
      : library(), 
      service(
        &library, 
        resource_repository,
        feature_toggles) {
  }
  NiDCPowerLibrary library;
  NiDCPowerService service;
};
}

std::shared_ptr<void> register_service(
  grpc::ServerBuilder& builder, 
  const std::shared_ptr<nidevice_grpc::SessionResourceRepository<ViSession>>& resource_repository,
  const nidevice_grpc::FeatureToggles& feature_toggles)
{
  auto toggles = NiDCPowerFeatureToggles(feature_toggles);

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

} // nidcpower_grpc
