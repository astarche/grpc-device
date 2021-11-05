
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service registrar implementation for the NI-DAQMX Metadata
//---------------------------------------------------------------------
#include "nidaqmx_library.h"

#include <grpcpp/server_builder.h>

#include "nidaqmx_service.h"
#include "nidaqmx_service_registrar.h"

namespace nidaqmx_grpc {

namespace {
struct LibraryAndService {
  LibraryAndService(
    const std::shared_ptr<nidevice_grpc::SessionResourceRepository<TaskHandle>>& resource_repository,
    const NiDAQmxFeatureToggles& feature_toggles) 
      : library(), 
      service(
        &library, 
        resource_repository, 
        feature_toggles) {
  }
  NiDAQmxLibrary library;
  NiDAQmxService service;
};
}

std::shared_ptr<void> register_service(
  grpc::ServerBuilder& builder, 
  const std::shared_ptr<nidevice_grpc::SessionResourceRepository<TaskHandle>>& resource_repository,
  const nidevice_grpc::FeatureToggles& feature_toggles)
{
  auto toggles = NiDAQmxFeatureToggles(feature_toggles);

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

} // nidaqmx_grpc
