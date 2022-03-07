
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service registrar implementation for the NI-RFMXNR Metadata
//---------------------------------------------------------------------
#include "nirfmxnr_library.h"

#include <grpcpp/server_builder.h>

#include "nirfmxnr_service.h"
#include "nirfmxnr_service_registrar.h"

namespace nirfmxnr_grpc {

namespace {
struct LibraryAndService {
  LibraryAndService(
    const std::shared_ptr<nidevice_grpc::SessionResourceRepository<niRFmxInstrHandle>>& resource_repository,
    const std::shared_ptr<nidevice_grpc::SessionResourceRepository<ViSession>>& vi_session_resource_repository,
    const NiRFmxNRFeatureToggles& feature_toggles) 
      : library(), 
      service(
        &library, 
        resource_repository,
        vi_session_resource_repository,
        feature_toggles) {
  }
  NiRFmxNRLibrary library;
  NiRFmxNRService service;
};
}

std::shared_ptr<void> register_service(
  grpc::ServerBuilder& builder, 
  const std::shared_ptr<nidevice_grpc::SessionResourceRepository<niRFmxInstrHandle>>& resource_repository,
  const std::shared_ptr<nidevice_grpc::SessionResourceRepository<ViSession>>& vi_session_resource_repository,
  const nidevice_grpc::FeatureToggles& feature_toggles)
{
  auto toggles = NiRFmxNRFeatureToggles(feature_toggles);

  if (toggles.is_enabled)
  {
    auto library_and_service_ptr = std::make_shared<LibraryAndService>(
      resource_repository,
      vi_session_resource_repository,
      toggles);
    auto& service = library_and_service_ptr->service;
    builder.RegisterService(&service);
    return library_and_service_ptr;
  }

  return {};
}

} // nirfmxnr_grpc
