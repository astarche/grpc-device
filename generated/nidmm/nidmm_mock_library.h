//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Mock of LibraryInterface for NI-DMM
//---------------------------------------------------------------------
#ifndef NIDMM_GRPC_MOCK_LIBRARY_H
#define NIDMM_GRPC_MOCK_LIBRARY_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "nidmm_library_interface.h"

namespace ni {
namespace tests {
namespace unit {

class NiDMMMockLibrary : public nidmm_grpc::NiDMMLibraryInterface {
 public:
  MOCK_METHOD(ViStatus, Abort, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, ConfigureMeasurementAbsolute, (ViSession vi, ViInt32 measurementFunction, ViReal64 range, ViReal64 resolutionAbsolute), (override));
  MOCK_METHOD(ViStatus, ConfigureMeasurementDigits, (ViSession vi, ViInt32 measurementFunction, ViReal64 range, ViReal64 resolutionDigits), (override));
  MOCK_METHOD(ViStatus, ConfigureMultiPoint, (ViSession vi, ViInt32 triggerCount, ViInt32 sampleCount, ViInt32 sampleTrigger, ViReal64 sampleInterval), (override));
  MOCK_METHOD(ViStatus, ConfigureRTDCustom, (ViSession vi, ViReal64 rtdA, ViReal64 rtdB, ViReal64 rtdC), (override));
  MOCK_METHOD(ViStatus, ConfigureRTDType, (ViSession vi, ViInt32 rtdType, ViReal64 rtdResistance), (override));
  MOCK_METHOD(ViStatus, ConfigureThermistorCustom, (ViSession vi, ViReal64 thermistorA, ViReal64 thermistorB, ViReal64 thermistorC), (override));
  MOCK_METHOD(ViStatus, ConfigureThermocouple, (ViSession vi, ViInt32 thermocoupleType, ViInt32 referenceJunctionType), (override));
  MOCK_METHOD(ViStatus, ConfigureTrigger, (ViSession vi, ViInt32 triggerSource, ViReal64 triggerDelay), (override));
  MOCK_METHOD(ViStatus, ConfigureWaveformAcquisition, (ViSession vi, ViInt32 measurementFunction, ViReal64 range, ViReal64 rate, ViInt32 waveformPoints), (override));
  MOCK_METHOD(ViStatus, Disable, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, ExportAttributeConfigurationBuffer, (ViSession vi, ViInt32 size, ViInt8 configuration[]), (override));
  MOCK_METHOD(ViStatus, ExportAttributeConfigurationFile, (ViSession vi, ViConstString filePath), (override));
  MOCK_METHOD(ViStatus, Fetch, (ViSession vi, ViInt32 maximumTime, ViReal64* reading), (override));
  MOCK_METHOD(ViStatus, FetchMultiPoint, (ViSession vi, ViInt32 maximumTime, ViInt32 arraySize, ViReal64 readingArray[], ViInt32* actualNumberOfPoints), (override));
  MOCK_METHOD(ViStatus, FetchWaveform, (ViSession vi, ViInt32 maximumTime, ViInt32 arraySize, ViReal64 waveformArray[], ViInt32* actualNumberOfPoints), (override));
  MOCK_METHOD(ViStatus, GetAttributeViBoolean, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean* attributeValue), (override));
  MOCK_METHOD(ViStatus, GetAttributeViInt32, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32* attributeValue), (override));
  MOCK_METHOD(ViStatus, GetAttributeViReal64, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64* attributeValue), (override));
  MOCK_METHOD(ViStatus, GetAttributeViString, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 bufferSize, ViChar attributeValue[]), (override));
  MOCK_METHOD(ViStatus, GetCalDateAndTime, (ViSession vi, ViInt32 calType, ViInt32* month, ViInt32* day, ViInt32* year, ViInt32* hour, ViInt32* minute), (override));
  MOCK_METHOD(ViStatus, GetDevTemp, (ViSession vi, ViString options, ViReal64* temperature), (override));
  MOCK_METHOD(ViStatus, GetError, (ViSession vi, ViStatus* errorCode, ViInt32 bufferSize, ViChar description[]), (override));
  MOCK_METHOD(ViStatus, GetExtCalRecommendedInterval, (ViSession vi, ViInt32* months), (override));
  MOCK_METHOD(ViStatus, GetLastCalTemp, (ViSession vi, ViInt32 calType, ViReal64* temperature), (override));
  MOCK_METHOD(ViStatus, GetSelfCalSupported, (ViSession vi, ViBoolean* selfCalSupported), (override));
  MOCK_METHOD(ViStatus, ImportAttributeConfigurationBuffer, (ViSession vi, ViInt32 size, ViInt8 configuration[]), (override));
  MOCK_METHOD(ViStatus, ImportAttributeConfigurationFile, (ViSession vi, ViConstString filePath), (override));
  MOCK_METHOD(ViStatus, InitWithOptions, (ViString resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViString optionString, ViSession* vi), (override));
  MOCK_METHOD(ViStatus, Initiate, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, LockSession, (ViSession vi, ViBoolean* callerHasLock), (override));
  MOCK_METHOD(ViStatus, PerformOpenCableComp, (ViSession vi, ViReal64* conductance, ViReal64* susceptance), (override));
  MOCK_METHOD(ViStatus, PerformShortCableComp, (ViSession vi, ViReal64* resistance, ViReal64* reactance), (override));
  MOCK_METHOD(ViStatus, Read, (ViSession vi, ViInt32 maximumTime, ViReal64* reading), (override));
  MOCK_METHOD(ViStatus, ReadMultiPoint, (ViSession vi, ViInt32 maximumTime, ViInt32 arraySize, ViReal64 readingArray[], ViInt32* actualNumberOfPoints), (override));
  MOCK_METHOD(ViStatus, ReadStatus, (ViSession vi, ViInt32* acquisitionBacklog, ViInt16* acquisitionStatus), (override));
  MOCK_METHOD(ViStatus, ReadWaveform, (ViSession vi, ViInt32 maximumTime, ViInt32 arraySize, ViReal64 waveformArray[], ViInt32* actualNumberOfPoints), (override));
  MOCK_METHOD(ViStatus, ResetWithDefaults, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, SelfCal, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, SendSoftwareTrigger, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, SetAttributeViBoolean, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean attributeValue), (override));
  MOCK_METHOD(ViStatus, SetAttributeViInt32, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 attributeValue), (override));
  MOCK_METHOD(ViStatus, SetAttributeViReal64, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 attributeValue), (override));
  MOCK_METHOD(ViStatus, SetAttributeViString, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViString attributeValue), (override));
  MOCK_METHOD(ViStatus, UnlockSession, (ViSession vi, ViBoolean* callerHasLock), (override));
  MOCK_METHOD(ViStatus, close, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, error_message, (ViSession vi, ViStatus errorCode, ViChar errorMessage[256]), (override));
  MOCK_METHOD(ViStatus, reset, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, self_test, (ViSession vi, ViInt16* selfTestResult, ViChar selfTestMessage[256]), (override));
};

}  // namespace unit
}  // namespace tests
}  // namespace ni
#endif  // NIDMM_GRPC_MOCK_LIBRARY_H
