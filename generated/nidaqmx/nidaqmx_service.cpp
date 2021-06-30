
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service implementation for the NI-DAQMX Metadata
//---------------------------------------------------------------------
#include "nidaqmx_service.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include <atomic>
#include <vector>

namespace nidaqmx_grpc {

  NiDAQmxService::NiDAQmxService(NiDAQmxLibraryInterface* library, ResourceRepositorySharedPtr session_repository)
      : library_(library), session_repository_(session_repository)
  {
  }

  NiDAQmxService::~NiDAQmxService()
  {
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiDAQmxService::ClearTask(::grpc::ServerContext* context, const ClearTaskRequest* request, ClearTaskResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto task_grpc_session = request->task();
      TaskHandle task = session_repository_->access_session(task_grpc_session.id(), task_grpc_session.name());
      session_repository_->remove_session(task);
      auto status = library_->ClearTask(task);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiDAQmxService::CreateTask(::grpc::ServerContext* context, const CreateTaskRequest* request, CreateTaskResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      const char* session_name = request->session_name().c_str();

      auto init_lambda = [&] () {
        TaskHandle task;
        int status = library_->CreateTask(session_name, &task);
        return std::make_tuple(status, task);
      };
      uint32_t session_id = 0;
      const std::string& grpc_device_session_name = request->session_name();
      auto cleanup_lambda = [&] (TaskHandle id) { library_->ClearTask(id); };
      int status = session_repository_->add_session(grpc_device_session_name, init_lambda, cleanup_lambda, session_id);
      response->set_status(status);
      if (status == 0) {
        response->mutable_task()->set_id(session_id);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

} // namespace nidaqmx_grpc

