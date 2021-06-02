
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

  NiDAQmxService::NiDAQmxService(NiDAQmxLibraryInterface* library, nidevice_grpc::SessionRepository* session_repository)
      : library_(library), session_repository_(session_repository)
  {
  }

  NiDAQmxService::~NiDAQmxService()
  {
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiDAQmxService::CreateTask(::grpc::ServerContext* context, const CreateTaskRequest* request, CreateTaskResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      const char* task_name = request->task_name().c_str();

      auto init_lambda = [&] () {
        TaskHandle task;
        int status = library_->CreateTask(task_name, &task);
        return std::make_tuple(status, task);
      };
      uint32_t session_id = 0;
      const std::string& session_name = request->session_name();
      auto cleanup_lambda = [&] (TaskHandle id) { library_->ClearTask (id); };
      int status = session_repository_.add_session(session_name, init_lambda, cleanup_lambda, session_id);
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

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiDAQmxService::ClearTask(::grpc::ServerContext* context, const ClearTaskRequest* request, ClearTaskResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto task_grpc_session = request->task();
      auto task = session_repository_.access_session(task_grpc_session.id(), task_grpc_session.name());
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
  ::grpc::Status NiDAQmxService::StartTask(::grpc::ServerContext* context, const StartTaskRequest* request, StartTaskResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto task_grpc_session = request->task();
      auto task = session_repository_.access_session(task_grpc_session.id(), task_grpc_session.name());
      auto status = library_->StartTask(task);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiDAQmxService::StopTask(::grpc::ServerContext* context, const StopTaskRequest* request, StopTaskResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto task_grpc_session = request->task();
      auto task = session_repository_.access_session(task_grpc_session.id(), task_grpc_session.name());
      auto status = library_->StopTask(task);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiDAQmxService::CreateAIVoltageChan(::grpc::ServerContext* context, const CreateAIVoltageChanRequest* request, CreateAIVoltageChanResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto task_grpc_session = request->task();
      auto task = session_repository_.access_session(task_grpc_session.id(), task_grpc_session.name());
      const char* physical_channel = request->physical_channel().c_str();
      const char* name_to_assign_to_channel = request->name_to_assign_to_channel().c_str();
      int32 terminal_config = request->terminal_config();
      double min_val = request->min_val();
      double max_val = request->max_val();
      int32 units = request->units();
      const char* custom_scale_name = request->custom_scale_name().c_str();
      auto status = library_->CreateAIVoltageChan(task, physical_channel, name_to_assign_to_channel, terminal_config, min_val, max_val, units, custom_scale_name);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiDAQmxService::GetChanAttributeU32(::grpc::ServerContext* context, const GetChanAttributeU32Request* request, GetChanAttributeU32Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto task_grpc_session = request->task();
      auto task = session_repository_.access_session(task_grpc_session.id(), task_grpc_session.name());
      const char* channel = request->channel().c_str();
      int32 attribute;
      switch (request->attribute_enum_case()) {
        case nidaqmx_grpc::GetChanAttributeU32Request::AttributeEnumCase::kAttribute:
          attribute = (int32)request->attribute();
          break;
        case nidaqmx_grpc::GetChanAttributeU32Request::AttributeEnumCase::kAttributeRaw:
          attribute = (int32)request->attribute_raw();
          break;
        case nidaqmx_grpc::GetChanAttributeU32Request::AttributeEnumCase::ATTRIBUTE_ENUM_NOT_SET:
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for attribute was not specified or out of range");
          break;
      }

      uInt32 value {};
      auto status = library_->GetChanAttributeU32(task, channel, attribute, &value);
      response->set_status(status);
      if (status == 0) {
        response->set_value(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiDAQmxService::SetChanAttributeU32(::grpc::ServerContext* context, const SetChanAttributeU32Request* request, SetChanAttributeU32Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto task_grpc_session = request->task();
      auto task = session_repository_.access_session(task_grpc_session.id(), task_grpc_session.name());
      const char* channel = request->channel().c_str();
      int32 attribute;
      switch (request->attribute_enum_case()) {
        case nidaqmx_grpc::SetChanAttributeU32Request::AttributeEnumCase::kAttribute:
          attribute = (int32)request->attribute();
          break;
        case nidaqmx_grpc::SetChanAttributeU32Request::AttributeEnumCase::kAttributeRaw:
          attribute = (int32)request->attribute_raw();
          break;
        case nidaqmx_grpc::SetChanAttributeU32Request::AttributeEnumCase::ATTRIBUTE_ENUM_NOT_SET:
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for attribute was not specified or out of range");
          break;
      }

      uInt32 value = request->value();
      auto status = library_->SetChanAttributeU32(task, channel, attribute, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiDAQmxService::GetChanAttributeF64(::grpc::ServerContext* context, const GetChanAttributeF64Request* request, GetChanAttributeF64Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto task_grpc_session = request->task();
      auto task = session_repository_.access_session(task_grpc_session.id(), task_grpc_session.name());
      const char* channel = request->channel().c_str();
      int32 attribute;
      switch (request->attribute_enum_case()) {
        case nidaqmx_grpc::GetChanAttributeF64Request::AttributeEnumCase::kAttribute:
          attribute = (int32)request->attribute();
          break;
        case nidaqmx_grpc::GetChanAttributeF64Request::AttributeEnumCase::kAttributeRaw:
          attribute = (int32)request->attribute_raw();
          break;
        case nidaqmx_grpc::GetChanAttributeF64Request::AttributeEnumCase::ATTRIBUTE_ENUM_NOT_SET:
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for attribute was not specified or out of range");
          break;
      }

      double value {};
      auto status = library_->GetChanAttributeF64(task, channel, attribute, &value);
      response->set_status(status);
      if (status == 0) {
        response->set_value(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiDAQmxService::SetChanAttributeF64(::grpc::ServerContext* context, const SetChanAttributeF64Request* request, SetChanAttributeF64Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto task_grpc_session = request->task();
      auto task = session_repository_.access_session(task_grpc_session.id(), task_grpc_session.name());
      const char* channel = request->channel().c_str();
      int32 attribute;
      switch (request->attribute_enum_case()) {
        case nidaqmx_grpc::SetChanAttributeF64Request::AttributeEnumCase::kAttribute:
          attribute = (int32)request->attribute();
          break;
        case nidaqmx_grpc::SetChanAttributeF64Request::AttributeEnumCase::kAttributeRaw:
          attribute = (int32)request->attribute_raw();
          break;
        case nidaqmx_grpc::SetChanAttributeF64Request::AttributeEnumCase::ATTRIBUTE_ENUM_NOT_SET:
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for attribute was not specified or out of range");
          break;
      }

      double value = request->value();
      auto status = library_->SetChanAttributeF64(task, channel, attribute, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiDAQmxService::GetChanAttributeStr(::grpc::ServerContext* context, const GetChanAttributeStrRequest* request, GetChanAttributeStrResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto task_grpc_session = request->task();
      auto task = session_repository_.access_session(task_grpc_session.id(), task_grpc_session.name());
      const char* channel = request->channel().c_str();
      int32 attribute;
      switch (request->attribute_enum_case()) {
        case nidaqmx_grpc::GetChanAttributeStrRequest::AttributeEnumCase::kAttribute:
          attribute = (int32)request->attribute();
          break;
        case nidaqmx_grpc::GetChanAttributeStrRequest::AttributeEnumCase::kAttributeRaw:
          attribute = (int32)request->attribute_raw();
          break;
        case nidaqmx_grpc::GetChanAttributeStrRequest::AttributeEnumCase::ATTRIBUTE_ENUM_NOT_SET:
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for attribute was not specified or out of range");
          break;
      }

      int32 size = request->size();
      std::string value;
      if (size > 0) {
          value.resize(size-1);
      }
      auto status = library_->GetChanAttributeStr(task, channel, attribute, (char*)value.data(), size);
      response->set_status(status);
      if (status == 0) {
        response->set_value(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiDAQmxService::SetChanAttributeStr(::grpc::ServerContext* context, const SetChanAttributeStrRequest* request, SetChanAttributeStrResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto task_grpc_session = request->task();
      auto task = session_repository_.access_session(task_grpc_session.id(), task_grpc_session.name());
      const char* channel = request->channel().c_str();
      int32 attribute;
      switch (request->attribute_enum_case()) {
        case nidaqmx_grpc::SetChanAttributeStrRequest::AttributeEnumCase::kAttribute:
          attribute = (int32)request->attribute();
          break;
        case nidaqmx_grpc::SetChanAttributeStrRequest::AttributeEnumCase::kAttributeRaw:
          attribute = (int32)request->attribute_raw();
          break;
        case nidaqmx_grpc::SetChanAttributeStrRequest::AttributeEnumCase::ATTRIBUTE_ENUM_NOT_SET:
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for attribute was not specified or out of range");
          break;
      }

      const char* value = request->value().c_str();
      auto status = library_->SetChanAttributeStr(task, channel, attribute, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiDAQmxService::ReadAnalogF64(::grpc::ServerContext* context, const ReadAnalogF64Request* request, ReadAnalogF64Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto task_grpc_session = request->task();
      auto task = session_repository_.access_session(task_grpc_session.id(), task_grpc_session.name());
      int32 num_samps_per_chan = request->num_samps_per_chan();
      double timeout = request->timeout();
      int32 fill_mode = request->fill_mode();
      uInt32 array_size_in_samps = request->array_size_in_samps();
      uInt64 reserved = request->reserved();
      response->mutable_read_array()->Resize(array_size_in_samps, 0);
      float64* read_array = response->mutable_read_array()->mutable_data();
      int32 samps_per_chan {};
      auto status = library_->ReadAnalogF64(task, num_samps_per_chan, timeout, fill_mode, read_array, array_size_in_samps, &samps_per_chan, reserved);
      response->set_status(status);
      if (status == 0) {
        response->set_samps_per_chan(samps_per_chan);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiDAQmxService::ReadAnalogF64StreamCodegen(::grpc::ServerContext* context, const ReadAnalogF64StreamCodegenRequest* request, ::grpc::ServerWriter<ReadAnalogF64StreamCodegenResponse>* writer)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      ReadAnalogF64StreamCodegenResponse localResponse;
      auto response = &localResponse;
      auto task_grpc_session = request->task();
      auto task = session_repository_.access_session(task_grpc_session.id(), task_grpc_session.name());
      int32 num_samps_per_chan = request->num_samps_per_chan();
      double timeout = request->timeout();
      int32 fill_mode = request->fill_mode();
      uInt32 array_size_in_samps = request->array_size_in_samps();
      uInt64 reserved = request->reserved();
      response->mutable_read_array()->Resize(array_size_in_samps, 0);
      float64* read_array = response->mutable_read_array()->mutable_data();
      int32 samps_per_chan {};
      do {
        auto status = library_->ReadAnalogF64StreamCodegen(task, num_samps_per_chan, timeout, fill_mode, read_array, array_size_in_samps, &samps_per_chan, reserved);
        response->set_status(status);
        if (status == 0) {
          response->set_samps_per_chan(samps_per_chan);
        }
      } while (writer->Write(localResponse));
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiDAQmxService::CfgSampClkTiming(::grpc::ServerContext* context, const CfgSampClkTimingRequest* request, CfgSampClkTimingResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto task_grpc_session = request->task();
      auto task = session_repository_.access_session(task_grpc_session.id(), task_grpc_session.name());
      const char* source = request->source().c_str();
      double rate = request->rate();
      int32 active_edge = request->active_edge();
      int32 sample_mode = request->sample_mode();
      uInt64 samps_per_chan = request->samps_per_chan();
      auto status = library_->CfgSampClkTiming(task, source, rate, active_edge, sample_mode, samps_per_chan);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

} // namespace nidaqmx_grpc

