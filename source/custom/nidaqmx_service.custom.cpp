#include <nidaqmx/nidaqmx_library.h>
#include <nidaqmx/nidaqmx_service.h>

namespace nidaqmx_grpc {
//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiDAQmxService::ReadAnalogF64Custom(::grpc::ServerContext* context, const ReadAnalogF64CustomRequest* request, ReadAnalogF64CustomResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto task_grpc_session = request->task();
    TaskHandle task = session_repository_->access_session(task_grpc_session.id(), task_grpc_session.name());
    int32 num_samps_per_chan = request->num_samps_per_chan();
    float64 timeout = request->timeout();
    int32 fill_mode;
    switch (request->fill_mode_enum_case()) {
      case nidaqmx_grpc::ReadAnalogF64CustomRequest::FillModeEnumCase::kFillMode: {
        fill_mode = static_cast<int32>(request->fill_mode());
        break;
      }
      case nidaqmx_grpc::ReadAnalogF64CustomRequest::FillModeEnumCase::kFillModeRaw: {
        fill_mode = static_cast<int32>(request->fill_mode_raw());
        break;
      }
      case nidaqmx_grpc::ReadAnalogF64CustomRequest::FillModeEnumCase::FILL_MODE_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for fill_mode was not specified or out of range");
        break;
      }
    }

    auto status = library_->ReadAnalogF64(task, num_samps_per_chan, timeout, fill_mode);
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

}  // namespace nidaqmx_grpc
