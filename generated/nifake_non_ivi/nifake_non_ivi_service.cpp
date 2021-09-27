
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service implementation for the NI-FAKE-NON-IVI Metadata
//---------------------------------------------------------------------
#include "nifake_non_ivi_service.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include <atomic>
#include <vector>
#include "custom/nidaqmx_conversions.h"
#include <server/converters.h>
#include <server/callback_router.h>
#include <server/server_reactor.h>

namespace nifake_non_ivi_grpc {

  using nidevice_grpc::converters::convert_from_grpc;
  using nidevice_grpc::converters::convert_to_grpc;

  NiFakeNonIviService::NiFakeNonIviService(
      NiFakeNonIviLibraryInterface* library,
      ResourceRepositorySharedPtr session_repository, 
      const nidevice_grpc::FeatureToggles& feature_toggles)
      : library_(library), session_repository_(session_repository), feature_toggles_(feature_toggles)
  {
  }

  NiFakeNonIviService::~NiFakeNonIviService()
  {
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::Close(::grpc::ServerContext* context, const CloseRequest* request, CloseResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto handle_grpc_session = request->handle();
      FakeHandle handle = session_repository_->access_session(handle_grpc_session.id(), handle_grpc_session.name());
      session_repository_->remove_session(handle);
      auto status = library_->Close(handle);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::GetMarbleAttributeDouble(::grpc::ServerContext* context, const GetMarbleAttributeDoubleRequest* request, GetMarbleAttributeDoubleResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto handle_grpc_session = request->handle();
      FakeHandle handle = session_repository_->access_session(handle_grpc_session.id(), handle_grpc_session.name());
      int32 attribute;
      switch (request->attribute_enum_case()) {
        case nifake_non_ivi_grpc::GetMarbleAttributeDoubleRequest::AttributeEnumCase::kAttribute: {
          attribute = static_cast<int32>(request->attribute());
          attribute = nifake_non_ivi_grpc::MarbleDoubleAttributes_IsValid(attribute) ? attribute : 0;
          break;
        }
        case nifake_non_ivi_grpc::GetMarbleAttributeDoubleRequest::AttributeEnumCase::kAttributeRaw: {
          attribute = static_cast<int32>(request->attribute_raw());
          auto attribute_is_valid = nifake_non_ivi_grpc::MarbleDoubleAttributes_IsValid(attribute) || feature_toggles_.is_allow_undefined_attributes_enabled;
          attribute = attribute_is_valid ? attribute : 0;
          break;
        }
        case nifake_non_ivi_grpc::GetMarbleAttributeDoubleRequest::AttributeEnumCase::ATTRIBUTE_ENUM_NOT_SET: {
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for attribute was not specified or out of range");
          break;
        }
      }

      double value {};
      auto status = library_->GetMarbleAttributeDouble(handle, attribute, &value);
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
  ::grpc::Status NiFakeNonIviService::GetMarbleAttributeInt32(::grpc::ServerContext* context, const GetMarbleAttributeInt32Request* request, GetMarbleAttributeInt32Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto handle_grpc_session = request->handle();
      FakeHandle handle = session_repository_->access_session(handle_grpc_session.id(), handle_grpc_session.name());
      int32 attribute;
      switch (request->attribute_enum_case()) {
        case nifake_non_ivi_grpc::GetMarbleAttributeInt32Request::AttributeEnumCase::kAttribute: {
          attribute = static_cast<int32>(request->attribute());
          attribute = nifake_non_ivi_grpc::MarbleInt32Attributes_IsValid(attribute) ? attribute : 0;
          break;
        }
        case nifake_non_ivi_grpc::GetMarbleAttributeInt32Request::AttributeEnumCase::kAttributeRaw: {
          attribute = static_cast<int32>(request->attribute_raw());
          auto attribute_is_valid = nifake_non_ivi_grpc::MarbleInt32Attributes_IsValid(attribute) || feature_toggles_.is_allow_undefined_attributes_enabled;
          attribute = attribute_is_valid ? attribute : 0;
          break;
        }
        case nifake_non_ivi_grpc::GetMarbleAttributeInt32Request::AttributeEnumCase::ATTRIBUTE_ENUM_NOT_SET: {
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for attribute was not specified or out of range");
          break;
        }
      }

      int32 value {};
      auto status = library_->GetMarbleAttributeInt32(handle, attribute, &value);
      response->set_status(status);
      if (status == 0) {
        auto checked_convert_value = [](auto raw_value) {
          bool raw_value_is_valid = nifake_non_ivi_grpc::MarbleInt32AttributeValues_IsValid(raw_value);
          auto valid_enum_value = raw_value_is_valid ? raw_value : 0;
          return static_cast<nifake_non_ivi_grpc::MarbleInt32AttributeValues>(valid_enum_value);
        };
        response->set_value(checked_convert_value(value));
        response->set_value_raw(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::GetMarbleAttributeInt32Array(::grpc::ServerContext* context, const GetMarbleAttributeInt32ArrayRequest* request, GetMarbleAttributeInt32ArrayResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto handle_grpc_session = request->handle();
      FakeHandle handle = session_repository_->access_session(handle_grpc_session.id(), handle_grpc_session.name());
      int32 attribute;
      switch (request->attribute_enum_case()) {
        case nifake_non_ivi_grpc::GetMarbleAttributeInt32ArrayRequest::AttributeEnumCase::kAttribute: {
          attribute = static_cast<int32>(request->attribute());
          attribute = nifake_non_ivi_grpc::MarbleInt32ArrayAttributes_IsValid(attribute) ? attribute : 0;
          break;
        }
        case nifake_non_ivi_grpc::GetMarbleAttributeInt32ArrayRequest::AttributeEnumCase::kAttributeRaw: {
          attribute = static_cast<int32>(request->attribute_raw());
          auto attribute_is_valid = nifake_non_ivi_grpc::MarbleInt32ArrayAttributes_IsValid(attribute) || feature_toggles_.is_allow_undefined_attributes_enabled;
          attribute = attribute_is_valid ? attribute : 0;
          break;
        }
        case nifake_non_ivi_grpc::GetMarbleAttributeInt32ArrayRequest::AttributeEnumCase::ATTRIBUTE_ENUM_NOT_SET: {
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for attribute was not specified or out of range");
          break;
        }
      }

      response->mutable_value_raw()->Resize(10, 0);
      int32* value = reinterpret_cast<int32*>(response->mutable_value_raw()->mutable_data());
      auto status = library_->GetMarbleAttributeInt32Array(handle, attribute, value);
      response->set_status(status);
      if (status == 0) {
        auto checked_convert_value = [](auto raw_value) {
          bool raw_value_is_valid = nifake_non_ivi_grpc::MarbleInt32AttributeValues_IsValid(raw_value);
          auto valid_enum_value = raw_value_is_valid ? raw_value : 0;
          return static_cast<nifake_non_ivi_grpc::MarbleInt32AttributeValues>(valid_enum_value);
        };
        response->mutable_value()->Clear();
        response->mutable_value()->Reserve(10);
        std::transform(
          response->value_raw().begin(),
          response->value_raw().end(),
          google::protobuf::RepeatedFieldBackInserter(response->mutable_value()),
          [&](auto x) { 
              return checked_convert_value(x);
          });
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::Init(::grpc::ServerContext* context, const InitRequest* request, InitResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_name = request->session_name().c_str();

      auto init_lambda = [&] () {
        FakeHandle handle;
        int status = library_->Init(session_name, &handle);
        return std::make_tuple(status, handle);
      };
      uint32_t session_id = 0;
      const std::string& grpc_device_session_name = request->session_name();
      auto cleanup_lambda = [&] (FakeHandle id) { library_->Close(id); };
      int status = session_repository_->add_session(grpc_device_session_name, init_lambda, cleanup_lambda, session_id);
      response->set_status(status);
      if (status == 0) {
        response->mutable_handle()->set_id(session_id);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::InitWithHandleNameAsSessionName(::grpc::ServerContext* context, const InitWithHandleNameAsSessionNameRequest* request, InitWithHandleNameAsSessionNameResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto handle_name = request->handle_name().c_str();

      auto init_lambda = [&] () {
        FakeHandle handle;
        int status = library_->InitWithHandleNameAsSessionName(handle_name, &handle);
        return std::make_tuple(status, handle);
      };
      uint32_t session_id = 0;
      const std::string& grpc_device_session_name = request->handle_name();
      auto cleanup_lambda = [&] (FakeHandle id) { library_->Close(id); };
      int status = session_repository_->add_session(grpc_device_session_name, init_lambda, cleanup_lambda, session_id);
      response->set_status(status);
      if (status == 0) {
        response->mutable_handle()->set_id(session_id);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::InputArraysWithNarrowIntegerTypes(::grpc::ServerContext* context, const InputArraysWithNarrowIntegerTypesRequest* request, InputArraysWithNarrowIntegerTypesResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto u16_array_raw = request->u16_array();
      auto u16_array = std::vector<myUInt16>();
      u16_array.reserve(u16_array_raw.size());
      std::transform(
        u16_array_raw.begin(),
        u16_array_raw.end(),
        std::back_inserter(u16_array),
        [](auto x) { 
              if (x < std::numeric_limits<myUInt16>::min() || x > std::numeric_limits<myUInt16>::max()) {
                  std::string message("value ");
                  message.append(std::to_string(x));
                  message.append(" doesn't fit in datatype ");
                  message.append("myUInt16");
                  throw nidevice_grpc::ValueOutOfRangeException(message);
              }
              return static_cast<myUInt16>(x);
        });

      auto i16_array_raw = request->i16_array();
      auto i16_array = std::vector<myInt16>();
      i16_array.reserve(i16_array_raw.size());
      std::transform(
        i16_array_raw.begin(),
        i16_array_raw.end(),
        std::back_inserter(i16_array),
        [](auto x) { 
              if (x < std::numeric_limits<myInt16>::min() || x > std::numeric_limits<myInt16>::max()) {
                  std::string message("value ");
                  message.append(std::to_string(x));
                  message.append(" doesn't fit in datatype ");
                  message.append("myInt16");
                  throw nidevice_grpc::ValueOutOfRangeException(message);
              }
              return static_cast<myInt16>(x);
        });

      auto i8_array_raw = request->i8_array();
      auto i8_array = std::vector<myInt8>();
      i8_array.reserve(i8_array_raw.size());
      std::transform(
        i8_array_raw.begin(),
        i8_array_raw.end(),
        std::back_inserter(i8_array),
        [](auto x) { 
              if (x < std::numeric_limits<myInt8>::min() || x > std::numeric_limits<myInt8>::max()) {
                  std::string message("value ");
                  message.append(std::to_string(x));
                  message.append(" doesn't fit in datatype ");
                  message.append("myInt8");
                  throw nidevice_grpc::ValueOutOfRangeException(message);
              }
              return static_cast<myInt8>(x);
        });

      auto status = library_->InputArraysWithNarrowIntegerTypes(u16_array.data(), i16_array.data(), i8_array.data());
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
    catch (nidevice_grpc::ValueOutOfRangeException& ex) {
      return ::grpc::Status(::grpc::OUT_OF_RANGE, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::IotaWithCustomSize(::grpc::ServerContext* context, const IotaWithCustomSizeRequest* request, IotaWithCustomSizeResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      int32 size_one = request->size_one();
      int32 size_two = request->size_two();
      response->mutable_data()->Resize((size_one < 0) ? size_two : size_one + 1, 0);
      int32* data = reinterpret_cast<int32*>(response->mutable_data()->mutable_data());
      auto status = library_->IotaWithCustomSize(size_one, size_two, data);
      response->set_status(status);
      if (status == 0) {
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::OutputArraysWithNarrowIntegerTypes(::grpc::ServerContext* context, const OutputArraysWithNarrowIntegerTypesRequest* request, OutputArraysWithNarrowIntegerTypesResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      int32 number_of_u16_samples = request->number_of_u16_samples();
      int32 number_of_i16_samples = request->number_of_i16_samples();
      int32 number_of_i8_samples = request->number_of_i8_samples();
      std::vector<myUInt16> u16_data(number_of_u16_samples);
      std::vector<myInt16> i16_data(number_of_i16_samples);
      std::vector<myInt8> i8_data(number_of_i8_samples);
      auto status = library_->OutputArraysWithNarrowIntegerTypes(number_of_u16_samples, u16_data.data(), number_of_i16_samples, i16_data.data(), number_of_i8_samples, i8_data.data());
      response->set_status(status);
      if (status == 0) {
        response->mutable_u16_data()->Clear();
        response->mutable_u16_data()->Reserve(number_of_u16_samples);
        std::transform(
          u16_data.begin(),
          u16_data.end(),
          google::protobuf::RepeatedFieldBackInserter(response->mutable_u16_data()),
          [&](auto x) { 
              return x;
          });
        response->mutable_i16_data()->Clear();
        response->mutable_i16_data()->Reserve(number_of_i16_samples);
        std::transform(
          i16_data.begin(),
          i16_data.end(),
          google::protobuf::RepeatedFieldBackInserter(response->mutable_i16_data()),
          [&](auto x) { 
              return x;
          });
        response->mutable_i8_data()->Clear();
        response->mutable_i8_data()->Reserve(number_of_i8_samples);
        std::transform(
          i8_data.begin(),
          i8_data.end(),
          google::protobuf::RepeatedFieldBackInserter(response->mutable_i8_data()),
          [&](auto x) { 
              return x;
          });
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::InputArrayOfBytes(::grpc::ServerContext* context, const InputArrayOfBytesRequest* request, InputArrayOfBytesResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      const myUInt8* u8_array = (const myUInt8*)request->u8_array().c_str();
      auto status = library_->InputArrayOfBytes(u8_array);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::OutputArrayOfBytes(::grpc::ServerContext* context, const OutputArrayOfBytesRequest* request, OutputArrayOfBytesResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      int32 number_of_u8_samples = request->number_of_u8_samples();
      std::string u8_data(number_of_u8_samples, '\0');
      auto status = library_->OutputArrayOfBytes(number_of_u8_samples, (myUInt8*)u8_data.data());
      response->set_status(status);
      if (status == 0) {
        response->set_u8_data(u8_data);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::ServerWriteReactor<RegisterCallbackResponse>*
  NiFakeNonIviService::RegisterCallback(::grpc::CallbackServerContext* context, const RegisterCallbackRequest* request)
  {
    using CallbackRouter = nidevice_grpc::CallbackRouter<int32, myInt16>;
    class RegisterCallbackReactor : public nidevice_grpc::ServerWriterReactor<RegisterCallbackResponse, nidevice_grpc::CallbackRegistration> {
    public:
    RegisterCallbackReactor(const RegisterCallbackRequest& request, NiFakeNonIviLibraryInterface* library, const ResourceRepositorySharedPtr& session_repository)
    {
      auto status = start(&request, library, session_repository);
      if (!status.ok()) {
        this->Finish(status);
      }
    }

    ::grpc::Status start(const RegisterCallbackRequest* request, NiFakeNonIviLibraryInterface* library, const ResourceRepositorySharedPtr& session_repository_)
    {
      try {
        auto handler = CallbackRouter::register_handler(
          [this](myInt16 data_out) {
            RegisterCallbackResponse callback_response;
            auto response = &callback_response;
            response->set_data_out(data_out);
            queue_write(callback_response);
            return 0;
        });

        myInt16 input_data = request->input_data();

        auto status = library->RegisterCallback(input_data, CallbackRouter::handle_callback, handler->token());

        // SendInitialMetadata after the driver call so that WaitForInitialMetadata can be used to ensure that calls are serialized.
        StartSendInitialMetadata();

        if (status) {
          RegisterCallbackResponse failed_to_register_response;
          failed_to_register_response.set_status(status);
          queue_write(failed_to_register_response);
        }

        this->set_producer(std::move(handler));
      }
      catch (nidevice_grpc::LibraryLoadException& ex) {
         return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
      }

      return ::grpc::Status::OK;
    }
    };

    return new RegisterCallbackReactor(*request, library_, session_repository_);
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::InputTimestamp(::grpc::ServerContext* context, const InputTimestampRequest* request, InputTimestampResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      CVIAbsoluteTime when = convert_from_grpc<CVIAbsoluteTime>(request->when());
      auto status = library_->InputTimestamp(when);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::OutputTimestamp(::grpc::ServerContext* context, const OutputTimestampRequest* request, OutputTimestampResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      CVIAbsoluteTime when {};
      auto status = library_->OutputTimestamp(&when);
      response->set_status(status);
      if (status == 0) {
        convert_to_grpc(when, response->mutable_when());
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::InputVarArgs(::grpc::ServerContext* context, const InputVarArgsRequest* request, InputVarArgsResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto input_name = request->input_name().c_str();
      auto get_channelName_if = [](const google::protobuf::RepeatedPtrField<StringAndEnum>& vector, int n) -> const char* {
            if (vector.size() > n) {
                  return vector[n].channelname().c_str();
            }
            return nullptr;
      };
      auto get_color_if = [](const google::protobuf::RepeatedPtrField<StringAndEnum>& vector, int n) -> int32 {
            if (vector.size() > n) {
                  return vector[n].color();
            }
            return 0;
      };
      auto get_powerUpState_if = [](const google::protobuf::RepeatedPtrField<StringAndEnum>& vector, int n) -> double {
            if (vector.size() > n) {
                  return vector[n].powerupstate();
            }
            return 0;
      };
      auto string_and_enums = request->string_and_enums();
      if (string_and_enums.size() == 0) {
            return ::grpc::Status(::grpc::INVALID_ARGUMENT, "No values for stringAndEnums were specified");
      }
      if (string_and_enums.size() > 3) {
            return ::grpc::Status(::grpc::INVALID_ARGUMENT, "More than 3 values for stringAndEnums were specified");
      }

      auto status = library_->InputVarArgs(input_name, get_channelName_if(string_and_enums, 0), get_color_if(string_and_enums, 0), get_powerUpState_if(string_and_enums, 0), get_channelName_if(string_and_enums, 1), get_color_if(string_and_enums, 1), get_powerUpState_if(string_and_enums, 1), get_channelName_if(string_and_enums, 2), get_color_if(string_and_enums, 2), get_powerUpState_if(string_and_enums, 2), get_channelName_if(string_and_enums, 3), get_color_if(string_and_enums, 3), get_powerUpState_if(string_and_enums, 3));
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::OutputVarArgs(::grpc::ServerContext* context, const OutputVarArgsRequest* request, OutputVarArgsResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto input_name = request->input_name().c_str();
      auto get_channelName_if = [](const google::protobuf::RepeatedPtrField<std::string>& vector, int n) -> const char* {
            if (vector.size() > n) {
                  return vector[n].c_str();
            }
            return nullptr;
      };
      auto channel_names = request->channel_names();
      if (channel_names.size() == 0) {
            return ::grpc::Status(::grpc::INVALID_ARGUMENT, "No values for channelNames were specified");
      }
      if (channel_names.size() > 3) {
            return ::grpc::Status(::grpc::INVALID_ARGUMENT, "More than 3 values for channelNames were specified");
      }

      auto get_color_if = [](std::vector<int32>& vector, int n) -> int32* {
            if (vector.size() > n) {
                  return &(vector[n]);
            }
            return nullptr;
      };
      std::vector<int32> colorVector;
      colorVector.resize(channel_names.size());
      auto status = library_->OutputVarArgs(input_name, get_channelName_if(channel_names, 0), get_color_if(colorVector, 0), get_channelName_if(channel_names, 1), get_color_if(colorVector, 1), get_channelName_if(channel_names, 2), get_color_if(colorVector, 2), get_channelName_if(channel_names, 3), get_color_if(colorVector, 3));
      response->set_status(status);
      if (status == 0) {
        for (int i = 0; i < colorVector.size(); ++i) {
          response->add_colors(static_cast<BeautifulColor>(colorVector[i]));
        }
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::ResetMarbleAttribute(::grpc::ServerContext* context, const ResetMarbleAttributeRequest* request, ResetMarbleAttributeResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto handle_grpc_session = request->handle();
      FakeHandle handle = session_repository_->access_session(handle_grpc_session.id(), handle_grpc_session.name());
      int32 attribute;
      switch (request->attribute_enum_case()) {
        case nifake_non_ivi_grpc::ResetMarbleAttributeRequest::AttributeEnumCase::kAttribute: {
          attribute = static_cast<int32>(request->attribute());
          attribute = nifake_non_ivi_grpc::MarbleResetAttributes_IsValid(attribute) ? attribute : 0;
          break;
        }
        case nifake_non_ivi_grpc::ResetMarbleAttributeRequest::AttributeEnumCase::kAttributeRaw: {
          attribute = static_cast<int32>(request->attribute_raw());
          auto attribute_is_valid = nifake_non_ivi_grpc::MarbleResetAttributes_IsValid(attribute) || feature_toggles_.is_allow_undefined_attributes_enabled;
          attribute = attribute_is_valid ? attribute : 0;
          break;
        }
        case nifake_non_ivi_grpc::ResetMarbleAttributeRequest::AttributeEnumCase::ATTRIBUTE_ENUM_NOT_SET: {
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for attribute was not specified or out of range");
          break;
        }
      }

      auto status = library_->ResetMarbleAttribute(handle, attribute);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::SetMarbleAttributeDouble(::grpc::ServerContext* context, const SetMarbleAttributeDoubleRequest* request, SetMarbleAttributeDoubleResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto handle_grpc_session = request->handle();
      FakeHandle handle = session_repository_->access_session(handle_grpc_session.id(), handle_grpc_session.name());
      int32 attribute;
      switch (request->attribute_enum_case()) {
        case nifake_non_ivi_grpc::SetMarbleAttributeDoubleRequest::AttributeEnumCase::kAttribute: {
          attribute = static_cast<int32>(request->attribute());
          attribute = nifake_non_ivi_grpc::MarbleDoubleAttributes_IsValid(attribute) ? attribute : 0;
          break;
        }
        case nifake_non_ivi_grpc::SetMarbleAttributeDoubleRequest::AttributeEnumCase::kAttributeRaw: {
          attribute = static_cast<int32>(request->attribute_raw());
          auto attribute_is_valid = nifake_non_ivi_grpc::MarbleDoubleAttributes_IsValid(attribute) || feature_toggles_.is_allow_undefined_attributes_enabled;
          attribute = attribute_is_valid ? attribute : 0;
          break;
        }
        case nifake_non_ivi_grpc::SetMarbleAttributeDoubleRequest::AttributeEnumCase::ATTRIBUTE_ENUM_NOT_SET: {
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for attribute was not specified or out of range");
          break;
        }
      }

      double value = request->value();
      auto status = library_->SetMarbleAttributeDouble(handle, attribute, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::SetMarbleAttributeInt32(::grpc::ServerContext* context, const SetMarbleAttributeInt32Request* request, SetMarbleAttributeInt32Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto handle_grpc_session = request->handle();
      FakeHandle handle = session_repository_->access_session(handle_grpc_session.id(), handle_grpc_session.name());
      int32 attribute;
      switch (request->attribute_enum_case()) {
        case nifake_non_ivi_grpc::SetMarbleAttributeInt32Request::AttributeEnumCase::kAttribute: {
          attribute = static_cast<int32>(request->attribute());
          attribute = nifake_non_ivi_grpc::MarbleInt32Attributes_IsValid(attribute) ? attribute : 0;
          break;
        }
        case nifake_non_ivi_grpc::SetMarbleAttributeInt32Request::AttributeEnumCase::kAttributeRaw: {
          attribute = static_cast<int32>(request->attribute_raw());
          auto attribute_is_valid = nifake_non_ivi_grpc::MarbleInt32Attributes_IsValid(attribute) || feature_toggles_.is_allow_undefined_attributes_enabled;
          attribute = attribute_is_valid ? attribute : 0;
          break;
        }
        case nifake_non_ivi_grpc::SetMarbleAttributeInt32Request::AttributeEnumCase::ATTRIBUTE_ENUM_NOT_SET: {
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for attribute was not specified or out of range");
          break;
        }
      }

      int32 value;
      switch (request->value_enum_case()) {
        case nifake_non_ivi_grpc::SetMarbleAttributeInt32Request::ValueEnumCase::kValue: {
          value = static_cast<int32>(request->value());
          break;
        }
        case nifake_non_ivi_grpc::SetMarbleAttributeInt32Request::ValueEnumCase::kValueRaw: {
          value = static_cast<int32>(request->value_raw());
          break;
        }
        case nifake_non_ivi_grpc::SetMarbleAttributeInt32Request::ValueEnumCase::VALUE_ENUM_NOT_SET: {
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for value was not specified or out of range");
          break;
        }
      }

      auto status = library_->SetMarbleAttributeInt32(handle, attribute, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::SetColors(::grpc::ServerContext* context, const SetColorsRequest* request, SetColorsResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto colors_vector = std::vector<int32>();
      colors_vector.reserve(request->colors().size());
      std::transform(
        request->colors().begin(),
        request->colors().end(),
        std::back_inserter(colors_vector),
        [](auto x) { return x; });
      auto colors = colors_vector.data();

      int32 size = request->size();
      auto status = library_->SetColors(colors, size);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  bool NiFakeNonIviService::is_enabled()
  {
    return feature_toggles_.is_enabled;
  }

  NiFakeNonIviService::NiFakeNonIviFeatureToggles::NiFakeNonIviFeatureToggles(
    const nidevice_grpc::FeatureToggles& feature_toggles)
    : is_enabled(
        feature_toggles.is_feature_enabled("nifake_non_ivi", CodeReadiness::kNextRelease)),
      is_allow_undefined_attributes_enabled(
        feature_toggles.is_feature_enabled("nifake_non_ivi.allow_undefined_attributes", CodeReadiness::kPrototype))
  {
  }
} // namespace nifake_non_ivi_grpc

namespace nidevice_grpc {
namespace converters {
} // converters
} // nidevice_grpc

