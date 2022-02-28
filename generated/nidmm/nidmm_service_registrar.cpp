
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service registrar implementation for the NI-DMM Metadata
//---------------------------------------------------------------------
#include "nidmm_library.h"

#include <grpcpp/server_builder.h>

#include "nidmm_service.h"
#include "nidmm_service_registrar.h"

namespace nidmm_grpc {

namespace {
struct LibraryAndService {
  LibraryAndService(
    const std::shared_ptr<nidevice_grpc::SessionResourceRepository<ViSession>>& resource_repository,
    const NiDmmFeatureToggles& feature_toggles) 
      : library(), 
      service(
        &library, 
        resource_repository,
        feature_toggles) {
  }
  NiDmmLibrary library;
  NiDmmService service;
};
}

std::shared_ptr<void> register_service(
  grpc::ServerBuilder& builder, 
  const std::shared_ptr<nidevice_grpc::SessionResourceRepository<ViSession>>& resource_repository,
  const nidevice_grpc::FeatureToggles& feature_toggles)
{
  auto toggles = NiDmmFeatureToggles(feature_toggles);

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

} // nidmm_grpc
