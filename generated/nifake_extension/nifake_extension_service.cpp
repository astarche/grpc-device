
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service implementation for the NI-FAKE-EXTENSION Metadata
//---------------------------------------------------------------------
#include "nifake_extension_service.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include <atomic>
#include <vector>

namespace nifake_extension_grpc {

  using nidevice_grpc::converters::convert_from_grpc;
  using nidevice_grpc::converters::convert_to_grpc;

  NiFakeExtensionService::NiFakeExtensionService(
      NiFakeExtensionLibraryInterface* library,
      ResourceRepositorySharedPtr session_repository, 
      const nidevice_grpc::FeatureToggles& feature_toggles)
      : library_(library), session_repository_(session_repository), feature_toggles_(feature_toggles)
  {
  }

  NiFakeExtensionService::~NiFakeExtensionService()
  {
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeExtensionService::AddCoolFunctionality(::grpc::ServerContext* context, const AddCoolFunctionalityRequest* request, AddCoolFunctionalityResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViInt32 param = request->param();
      auto status = library_->AddCoolFunctionality(vi, param);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  bool NiFakeExtensionService::is_enabled()
  {
    return feature_toggles_.is_enabled;
  }

  NiFakeExtensionService::NiFakeExtensionFeatureToggles::NiFakeExtensionFeatureToggles(
    const nidevice_grpc::FeatureToggles& feature_toggles)
    : is_enabled(
        feature_toggles.is_feature_enabled("nifake_extension", CodeReadiness::kRelease))
  {
  }
} // namespace nifake_extension_grpc

