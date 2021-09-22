
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// EXPERIMENTAL Client convenience wrapper for NI-RFSA.
//---------------------------------------------------------------------
#ifndef NIRFSA_GRPC_CLIENT_H
#define NIRFSA_GRPC_CLIENT_H

#include <grpcpp/grpcpp.h>

#include <nirfsa.grpc.pb.h>
#include <tests/utilities/client_helpers.h>

#include <memory>
#include <vector>

namespace nirfsa_grpc::experimental::client {

namespace pb = ::google::protobuf;
using StubPtr = std::unique_ptr<NiRFSA::Stub>;
using namespace nidevice_grpc::experimental::client;


AbortResponse abort(const StubPtr& stub, const nidevice_grpc::Session& vi);
CalAdjustCalTonePowerResponse cal_adjust_cal_tone_power(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list, const double& measurement);
CalAdjustDeviceGainResponse cal_adjust_device_gain(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list, const double& frequency, const double& gain);
CalAdjustDownconverterGainResponse cal_adjust_downconverter_gain(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list, const double& frequency, const double& gain);
CalAdjustIFAttenuationCalibrationResponse cal_adjust_if_attenuation_calibration(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list, const simple_variant<IfFilterTable, pb::int32>& if_filter, const std::vector<double>& attenuator_settings, const double& measurement);
CalAdjustIFResponseCalibrationResponse cal_adjust_if_response_calibration(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list, const simple_variant<IfFilterTable, pb::int32>& if_filter, const double& rf_frequency, const double& band_width, const std::vector<double>& measurements);
CalSetTemperatureResponse cal_set_temperature(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list, const double& temperature);
ChangeExtCalPasswordResponse change_ext_cal_password(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& old_password, const pb::string& new_password);
CheckAcquisitionStatusResponse check_acquisition_status(const StubPtr& stub, const nidevice_grpc::Session& vi);
ClearErrorResponse clear_error(const StubPtr& stub, const nidevice_grpc::Session& vi);
ClearSelfCalibrateRangeResponse clear_self_calibrate_range(const StubPtr& stub, const nidevice_grpc::Session& vi);
CloseResponse close(const StubPtr& stub, const nidevice_grpc::Session& vi);
CloseCalibrationStepResponse close_calibration_step(const StubPtr& stub, const nidevice_grpc::Session& vi);
CloseExternalAlignmentStepResponse close_external_alignment_step(const StubPtr& stub, const nidevice_grpc::Session& vi);
CommitResponse commit(const StubPtr& stub, const nidevice_grpc::Session& vi);
ConfigureAcquisitionTypeResponse configure_acquisition_type(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<AcquisitionTypeRangeTable, pb::int32>& acquisition_type);
ConfigureDeembeddingTableInterpolationLinearResponse configure_deembedding_table_interpolation_linear(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& port, const pb::string& table_name, const simple_variant<LinearInterpolationFormat, pb::int32>& format);
ConfigureDeembeddingTableInterpolationNearestResponse configure_deembedding_table_interpolation_nearest(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& port, const pb::string& table_name);
ConfigureDeembeddingTableInterpolationSplineResponse configure_deembedding_table_interpolation_spline(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& port, const pb::string& table_name);
ConfigureDigitalEdgeAdvanceTriggerResponse configure_digital_edge_advance_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<DigitalEdgeTriggerSource, std::string>& source, const simple_variant<DigitalEdgeRangeTable, pb::int32>& edge);
ConfigureDigitalEdgeRefTriggerResponse configure_digital_edge_ref_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<DigitalEdgeTriggerSource, std::string>& source, const simple_variant<DigitalEdgeRangeTable, pb::int32>& edge, const pb::int64& pretrigger_samples);
ConfigureDigitalEdgeStartTriggerResponse configure_digital_edge_start_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<DigitalEdgeTriggerSource, std::string>& source, const simple_variant<DigitalEdgeRangeTable, pb::int32>& edge);
ConfigureIQCarrierFrequencyResponse configure_iq_carrier_frequency(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list, const double& carrier_frequency);
ConfigureIQPowerEdgeRefTriggerResponse configure_iq_power_edge_ref_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& source, const double& level, const simple_variant<AnalogSlopeRangeTable, pb::int32>& slope, const pb::int64& pretrigger_samples);
ConfigureIQRateResponse configure_iq_rate(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list, const double& iq_rate);
ConfigureNumberOfRecordsResponse configure_number_of_records(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list, const bool& number_of_records_is_finite, const pb::int64& number_of_records);
ConfigureNumberOfSamplesResponse configure_number_of_samples(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list, const bool& number_of_samples_is_finite, const pb::int64& samples_per_record);
ConfigurePXIChassisClk10Response configure_pxi_chassis_clk10(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<PxiChassisClk10SourceRangeTable, std::string>& pxi_clk10_source);
ConfigureRefClockResponse configure_ref_clock(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<RefClockSourceRangeTable, std::string>& clock_source, const double& ref_clock_rate);
ConfigureReferenceLevelResponse configure_reference_level(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list, const double& reference_level);
ConfigureResolutionBandwidthResponse configure_resolution_bandwidth(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list, const double& resolution_bandwidth);
ConfigureSoftwareEdgeAdvanceTriggerResponse configure_software_edge_advance_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi);
ConfigureSoftwareEdgeRefTriggerResponse configure_software_edge_ref_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int64& pretrigger_samples);
ConfigureSoftwareEdgeStartTriggerResponse configure_software_edge_start_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi);
ConfigureSpectrumFrequencyCenterSpanResponse configure_spectrum_frequency_center_span(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list, const double& center_frequency, const double& span);
ConfigureSpectrumFrequencyStartStopResponse configure_spectrum_frequency_start_stop(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list, const double& start_frequency, const double& stop_frequency);
CreateConfigurationListResponse create_configuration_list(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& list_name, const std::vector<NiRFSAAttributes>& list_attribute_i_ds, const bool& set_as_active_list);
CreateConfigurationListStepResponse create_configuration_list_step(const StubPtr& stub, const nidevice_grpc::Session& vi, const bool& set_as_active_step);
CreateDeembeddingSparameterTableS2PFileResponse create_deembedding_sparameter_table_s2p_file(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& port, const pb::string& table_name, const pb::string& s2p_file_path, const simple_variant<SparameterOrientation, pb::int32>& sparameter_orientation);
DeleteAllDeembeddingTablesResponse delete_all_deembedding_tables(const StubPtr& stub, const nidevice_grpc::Session& vi);
DeleteConfigurationListResponse delete_configuration_list(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& list_name);
DeleteDeembeddingTableResponse delete_deembedding_table(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& port, const pb::string& table_name);
DisableResponse disable(const StubPtr& stub, const nidevice_grpc::Session& vi);
DisableAdvanceTriggerResponse disable_advance_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi);
DisableRefTriggerResponse disable_ref_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi);
DisableStartTriggerResponse disable_start_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi);
EnableSessionAccessResponse enable_session_access(const StubPtr& stub, const nidevice_grpc::Session& vi, const bool& enable);
ErrorMessageResponse error_message(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& status_code);
ErrorQueryResponse error_query(const StubPtr& stub, const nidevice_grpc::Session& vi);
ExportSignalResponse export_signal(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<Signal, pb::int32>& signal, const pb::string& signal_identifier, const simple_variant<ExportTerminalRangeTable, std::string>& output_terminal);
ExtCalStoreBaselineForSelfCalibrationResponse ext_cal_store_baseline_for_self_calibration(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& password, const pb::int64& self_calibration_step);
ExternalAlignmentAdjustPreselectorResponse external_alignment_adjust_preselector(const StubPtr& stub, const nidevice_grpc::Session& vi, const std::vector<double>& coefficients);
GetAttributeViBooleanResponse get_attribute_vi_boolean(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiRFSAAttributes& attribute_id);
GetAttributeViInt32Response get_attribute_vi_int32(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiRFSAAttributes& attribute_id);
GetAttributeViInt64Response get_attribute_vi_int64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiRFSAAttributes& attribute_id);
GetAttributeViReal64Response get_attribute_vi_real64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiRFSAAttributes& attribute_id);
GetAttributeViSessionResponse get_attribute_vi_session(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiRFSAAttributes& attribute_id);
GetAttributeViStringResponse get_attribute_vi_string(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiRFSAAttributes& attribute_id);
GetCalUserDefinedInfoResponse get_cal_user_defined_info(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetCalUserDefinedInfoMaxSizeResponse get_cal_user_defined_info_max_size(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetDeviceResponseResponse get_device_response(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list, const simple_variant<DeviceResponse, pb::int32>& response_type);
GetErrorResponse get_error(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& error_description_buffer_size);
GetExtCalLastDateAndTimeResponse get_ext_cal_last_date_and_time(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetExtCalLastTempResponse get_ext_cal_last_temp(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetExtCalRecommendedIntervalResponse get_ext_cal_recommended_interval(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetFetchBacklogResponse get_fetch_backlog(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list, const pb::int64& record_number);
GetFrequencyResponseResponse get_frequency_response(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list);
GetGainReferenceCalBaselineResponse get_gain_reference_cal_baseline(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetNumberOfSpectralLinesResponse get_number_of_spectral_lines(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list);
GetRelayNameResponse get_relay_name(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list, const pb::int32& index);
GetRelayOperationsCountResponse get_relay_operations_count(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_list);
GetSelfCalLastDateAndTimeResponse get_self_cal_last_date_and_time(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int64& self_calibration_step);
GetSelfCalLastTempResponse get_self_cal_last_temp(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int64& self_calibration_step);
GetStreamEndpointHandleResponse get_stream_endpoint_handle(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& stream_endpoint);
GetTerminalNameResponse get_terminal_name(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<Signal, pb::int32>& signal, const pb::string& signal_identifier, const pb::int32& buffer_size);
GetUserDataResponse get_user_data(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& identifier);
InitResponse init(const StubPtr& stub, const pb::string& resource_name, const bool& id_query, const bool& reset);
InitExtCalResponse init_ext_cal(const StubPtr& stub, const pb::string& resource_name, const pb::string& password, const pb::string& option_string);
InitWithOptionsResponse init_with_options(const StubPtr& stub, const pb::string& resource_name, const bool& id_query, const bool& reset, const pb::string& option_string);
InitializeExternalAlignmentResponse initialize_external_alignment(const StubPtr& stub, const pb::string& resource_name, const pb::string& option_string);
InitiateResponse initiate(const StubPtr& stub, const nidevice_grpc::Session& vi);
InvalidateAllAttributesResponse invalidate_all_attributes(const StubPtr& stub, const nidevice_grpc::Session& vi);
IsSelfCalValidResponse is_self_cal_valid(const StubPtr& stub, const nidevice_grpc::Session& vi);
LockSessionResponse lock_session(const StubPtr& stub, const nidevice_grpc::Session& vi);
PerformThermalCorrectionResponse perform_thermal_correction(const StubPtr& stub, const nidevice_grpc::Session& vi);
ResetResponse reset(const StubPtr& stub, const nidevice_grpc::Session& vi);
ResetAttributeResponse reset_attribute(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiRFSAAttributes& attribute_id);
ResetDeviceResponse reset_device(const StubPtr& stub, const nidevice_grpc::Session& vi);
ResetWithDefaultsResponse reset_with_defaults(const StubPtr& stub, const nidevice_grpc::Session& vi);
ResetWithOptionsResponse reset_with_options(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::uint64& steps_to_omit);
RevisionQueryResponse revision_query(const StubPtr& stub, const nidevice_grpc::Session& vi);
SelfCalResponse self_cal(const StubPtr& stub, const nidevice_grpc::Session& vi);
SelfCalibrateResponse self_calibrate(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int64& steps_to_omit);
SelfCalibrateRangeResponse self_calibrate_range(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int64& steps_to_omit, const double& min_frequency, const double& max_frequency, const double& min_reference_level, const double& max_reference_level);
SelfTestResponse self_test(const StubPtr& stub, const nidevice_grpc::Session& vi);
SendSoftwareEdgeTriggerResponse send_software_edge_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<Signal, pb::int32>& trigger, const pb::string& trigger_identifier);
SetAttributeViBooleanResponse set_attribute_vi_boolean(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiRFSAAttributes& attribute_id, const bool& value);
SetAttributeViInt32Response set_attribute_vi_int32(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiRFSAAttributes& attribute_id, const simple_variant<NiRFSAInt32AttributeValues, pb::int32>& value);
SetAttributeViInt64Response set_attribute_vi_int64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiRFSAAttributes& attribute_id, const pb::int64& value_raw);
SetAttributeViReal64Response set_attribute_vi_real64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiRFSAAttributes& attribute_id, const simple_variant<NiRFSAReal64AttributeValues, double>& value);
SetAttributeViSessionResponse set_attribute_vi_session(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiRFSAAttributes& attribute_id, const nidevice_grpc::Session& value);
SetAttributeViStringResponse set_attribute_vi_string(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiRFSAAttributes& attribute_id, const simple_variant<NiRFSAStringAttributeValuesMapped, std::string>& value);
SetCalUserDefinedInfoResponse set_cal_user_defined_info(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& info);
SetUserDataResponse set_user_data(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& identifier, const pb::int32& buffer_size);
UnlockSessionResponse unlock_session(const StubPtr& stub, const nidevice_grpc::Session& vi);

} // namespace nirfsa_grpc::experimental::client

#endif /* NIRFSA_GRPC_CLIENT_H */
