#include <nifpga/nifpga_service.h>

namespace nifpga_grpc {

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::ReadArrayI16(::grpc::ServerContext* context, const ReadArrayI16Request* request, ReadArrayI16Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t indicator = request->indicator();
      size_t size = request->size();
      auto array = const_cast<int16_t*>(reinterpret_cast<const int16_t*>(response->array().data()));
      // NiFpga_Status NiFpgaLibrary::ReadArrayI16(NiFpga_Session session,
      //                                           uint32_t indicator, 
      //                                           int16_t* array, 
      //                                           size_t size)

      auto status = library_->ReadArrayI16(session, indicator, array, size);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::ReadArrayU16(::grpc::ServerContext* context, const ReadArrayU16Request* request, ReadArrayU16Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t indicator = request->indicator();
      size_t size = request->size();
      auto array = const_cast<uint16_t*>(reinterpret_cast<const uint16_t*>(response->array().data()));
      auto status = library_->ReadArrayU16(session, indicator, array, size);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::ReadArrayI64(::grpc::ServerContext* context, const ReadArrayI64Request* request, ReadArrayI64Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t indicator = request->indicator();
      size_t size = request->size();
      auto array = const_cast<int64_t*>(reinterpret_cast<const int64_t*>(response->array().data()));
      auto status = library_->ReadArrayI64(session, indicator, array, size);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::ReadArrayU64(::grpc::ServerContext* context, const ReadArrayU64Request* request, ReadArrayU64Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t indicator = request->indicator();
      size_t size = request->size();
      auto array = const_cast<uint64_t*>(reinterpret_cast<const uint64_t*>(response->array().data()));
      auto status = library_->ReadArrayU64(session, indicator, array, size);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }
}  // namespace nifpga_grpc
