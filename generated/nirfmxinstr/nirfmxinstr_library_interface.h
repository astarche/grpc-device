//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Library wrapper for implementing interactions with NI-RFMXINSTR
//---------------------------------------------------------------------
#ifndef NIRFMXINSTR_GRPC_LIBRARY_WRAPPER_H
#define NIRFMXINSTR_GRPC_LIBRARY_WRAPPER_H

#include <grpcpp/grpcpp.h>
#include <niRFmxInstr.h>

namespace nirfmxinstr_grpc {

class NiRFmxInstrLibraryInterface {
 public:
  virtual ~NiRFmxInstrLibraryInterface() {}

  virtual int32 BuildCalibrationPlaneString(char calibrationPlaneName[], int32 selectorStringLength, char selectorString[]) = 0;
  virtual int32 BuildInstrumentString(char selectorString[], int32 instrumentNumber, int32 selectorStringOutLength, char selectorStringOut[]) = 0;
  virtual int32 BuildLOString(char selectorString[], int32 loIndex, int32 selectorStringOutLength, char selectorStringOut[]) = 0;
  virtual int32 BuildModuleString(char selectorString[], char moduleName[], int32 selectorStringOutLength, char selectorStringOut[]) = 0;
  virtual int32 BuildPortString(char selectorString[], char portName[], char deviceName[], int32 channelNumber, int32 selectorStringOutLength, char selectorStringOut[]) = 0;
  virtual int32 CfgExternalAttenuationInterpolationLinear(niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[], int32 format) = 0;
  virtual int32 CfgExternalAttenuationInterpolationNearest(niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[]) = 0;
  virtual int32 CfgExternalAttenuationInterpolationSpline(niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[]) = 0;
  virtual int32 CfgExternalAttenuationTable(niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[], float64 frequency[], float64 externalAttenuation[], int32 arraySize) = 0;
  virtual int32 CfgFrequencyReference(niRFmxInstrHandle instrumentHandle, char channelName[], char frequencyReferenceSource[], float64 frequencyReferenceFrequency) = 0;
  virtual int32 CfgMechanicalAttenuation(niRFmxInstrHandle instrumentHandle, char channelName[], int32 mechanicalAttenuationAuto, float64 mechanicalAttenuationValue) = 0;
  virtual int32 CfgRFAttenuation(niRFmxInstrHandle instrumentHandle, char channelName[], int32 rfAttenuationAuto, float64 rfAttenuationValue) = 0;
  virtual int32 CfgSParameterExternalAttenuationTable(niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[], float64 frequency[], int32 frequencyArraySize, NIComplexDouble sParameters[], int32 sParameterTableSize, int32 numberOfPorts, int32 sParameterOrientation) = 0;
  virtual int32 CfgSParameterExternalAttenuationType(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 sParameterType) = 0;
  virtual int32 CheckAcquisitionStatus(niRFmxInstrHandle instrumentHandle, int32* acquisitionDone) = 0;
  virtual int32 CheckIfListExists(niRFmxInstrHandle instrumentHandle, char listName[], int32* listExists, int32* personality) = 0;
  virtual int32 CheckIfSignalConfigurationExists(niRFmxInstrHandle instrumentHandle, char signalName[], int32* signalConfigurationExists, int32* personality) = 0;
  virtual int32 Close(niRFmxInstrHandle instrumentHandle, int32 forceDestroy) = 0;
  virtual int32 DeleteAllExternalAttenuationTables(niRFmxInstrHandle instrumentHandle, char selectorString[]) = 0;
  virtual int32 DeleteExternalAttenuationTable(niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[]) = 0;
  virtual int32 DisableCalibrationPlane(niRFmxInstrHandle instrumentHandle, char selectorString[]) = 0;
  virtual int32 EnableCalibrationPlane(niRFmxInstrHandle instrumentHandle, char selectorString[]) = 0;
  virtual int32 ExportSignal(niRFmxInstrHandle instrumentHandle, int32 exportSignalSource, char exportSignalOutputTerminal[]) = 0;
  virtual int32 GetAttributeF32(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float32* attrVal) = 0;
  virtual int32 GetAttributeF32Array(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float32 attrVal[], int32 arraySize, int32* actualArraySize) = 0;
  virtual int32 GetAttributeF64(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float64* attrVal) = 0;
  virtual int32 GetAttributeF64Array(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float64 attrVal[], int32 arraySize, int32* actualArraySize) = 0;
  virtual int32 GetAttributeI16(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int16* attrVal) = 0;
  virtual int32 GetAttributeI32(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int32* attrVal) = 0;
  virtual int32 GetAttributeI32Array(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int32 attrVal[], int32 arraySize, int32* actualArraySize) = 0;
  virtual int32 GetAttributeI64(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int64* attrVal) = 0;
  virtual int32 GetAttributeI64Array(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int64 attrVal[], int32 arraySize, int32* actualArraySize) = 0;
  virtual int32 GetAttributeI8(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int8* attrVal) = 0;
  virtual int32 GetAttributeI8Array(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int8 attrVal[], int32 arraySize, int32* actualArraySize) = 0;
  virtual int32 GetAttributeNIComplexDoubleArray(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, NIComplexDouble attrVal[], int32 arraySize, int32* actualArraySize) = 0;
  virtual int32 GetAttributeNIComplexSingleArray(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, NIComplexSingle attrVal[], int32 arraySize, int32* actualArraySize) = 0;
  virtual int32 GetAttributeString(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int32 arraySize, char attrVal[]) = 0;
  virtual int32 GetAttributeU16(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt16* attrVal) = 0;
  virtual int32 GetAttributeU32(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt32* attrVal) = 0;
  virtual int32 GetAttributeU32Array(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt32 attrVal[], int32 arraySize, int32* actualArraySize) = 0;
  virtual int32 GetAttributeU64Array(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt64 attrVal[], int32 arraySize, int32* actualArraySize) = 0;
  virtual int32 GetAttributeU8(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt8* attrVal) = 0;
  virtual int32 GetAttributeU8Array(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt8 attrVal[], int32 arraySize, int32* actualArraySize) = 0;
  virtual int32 GetAvailablePorts(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char availablePorts[]) = 0;
  virtual int32 GetError(niRFmxInstrHandle instrumentHandle, int32* errorCode, int32 errorDescriptionBufferSize, char errorDescription[]) = 0;
  virtual int32 GetErrorString(niRFmxInstrHandle instrumentHandle, int32 errorCode, int32 errorDescriptionBufferSize, char errorDescription[]) = 0;
  virtual int32 GetExternalAttenuationTableActualValue(niRFmxInstrHandle instrumentHandle, char selectorString[], float64* externalAttenuation) = 0;
  virtual int32 GetNIRFSASession(niRFmxInstrHandle instrumentHandle, uInt32* niRfsaSession) = 0;
  virtual int32 GetNIRFSASessionArray(niRFmxInstrHandle instrumentHandle, uInt32 nirfsaSessions[], int32 arraySize, int32* actualArraySize) = 0;
  virtual int32 GetSelfCalibrateLastDateAndTime(niRFmxInstrHandle instrumentHandle, char selectorString[], int64 selfCalibrateStep, CVIAbsoluteTime* timestamp) = 0;
  virtual int32 GetSelfCalibrateLastTemperature(niRFmxInstrHandle instrumentHandle, char selectorString[], int64 selfCalibrateStep, float64* temperature) = 0;
  virtual int32 Initialize(char resourceName[], char optionString[], niRFmxInstrHandle* handleOut, int32* isNewSession) = 0;
  virtual int32 InitializeFromNIRFSASession(uInt32 nirfsaSession, niRFmxInstrHandle* handleOut) = 0;
  virtual int32 InitializeFromNIRFSASessionArray(uInt32 nirfsaSessions[], int32 numberOfNIRFSASessions, niRFmxInstrHandle* handleOut) = 0;
  virtual int32 IsSelfCalibrateValid(niRFmxInstrHandle instrumentHandle, char selectorString[], int32* selfCalibrateValid, int32* validSteps) = 0;
  virtual int32 LoadAllConfigurations(niRFmxInstrHandle instrumentHandle, char filePath[], int32 loadRFInstrConfiguration) = 0;
  virtual int32 LoadSParameterExternalAttenuationTableFromS2PFile(niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[], char s2PFilePath[], int32 sParameterOrientation) = 0;
  virtual int32 ResetAttribute(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID) = 0;
  virtual int32 ResetDriver(niRFmxInstrHandle instrumentHandle) = 0;
  virtual int32 ResetEntireSession(niRFmxInstrHandle instrumentHandle) = 0;
  virtual int32 ResetToDefault(niRFmxInstrHandle instrumentHandle) = 0;
  virtual int32 SaveAllConfigurations(niRFmxInstrHandle instrumentHandle, char filePath[]) = 0;
  virtual int32 SelectActiveExternalAttenuationTable(niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[]) = 0;
  virtual int32 SelfCalibrate(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 stepsToOmit) = 0;
  virtual int32 SelfCalibrateRange(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 stepsToOmit, float64 minimumFrequency, float64 maximumFrequency, float64 minimumReferenceLevel, float64 maximumReferenceLevel) = 0;
  virtual int32 SendSoftwareEdgeAdvanceTrigger(niRFmxInstrHandle instrumentHandle) = 0;
  virtual int32 SendSoftwareEdgeStartTrigger(niRFmxInstrHandle instrumentHandle) = 0;
  virtual int32 SetAttributeF32(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float32 attrVal) = 0;
  virtual int32 SetAttributeF32Array(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float32 attrVal[], int32 arraySize) = 0;
  virtual int32 SetAttributeF64(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float64 attrVal) = 0;
  virtual int32 SetAttributeF64Array(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float64 attrVal[], int32 arraySize) = 0;
  virtual int32 SetAttributeI16(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int16 attrVal) = 0;
  virtual int32 SetAttributeI32(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int32 attrVal) = 0;
  virtual int32 SetAttributeI32Array(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int32 attrVal[], int32 arraySize) = 0;
  virtual int32 SetAttributeI64(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int64 attrVal) = 0;
  virtual int32 SetAttributeI64Array(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int64 attrVal[], int32 arraySize) = 0;
  virtual int32 SetAttributeI8(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int8 attrVal) = 0;
  virtual int32 SetAttributeI8Array(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int8 attrVal[], int32 arraySize) = 0;
  virtual int32 SetAttributeNIComplexDoubleArray(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, NIComplexDouble attrVal[], int32 arraySize) = 0;
  virtual int32 SetAttributeNIComplexSingleArray(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, NIComplexSingle attrVal[], int32 arraySize) = 0;
  virtual int32 SetAttributeString(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, char attrVal[]) = 0;
  virtual int32 SetAttributeU16(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt16 attrVal) = 0;
  virtual int32 SetAttributeU32(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt32 attrVal) = 0;
  virtual int32 SetAttributeU32Array(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt32 attrVal[], int32 arraySize) = 0;
  virtual int32 SetAttributeU64Array(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt64 attrVal[], int32 arraySize) = 0;
  virtual int32 SetAttributeU8(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt8 attrVal) = 0;
  virtual int32 SetAttributeU8Array(niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt8 attrVal[], int32 arraySize) = 0;
  virtual int32 TimestampFromValues(int64 secondsSince1970, float64 fractionalSeconds, CVIAbsoluteTime* timestamp) = 0;
  virtual int32 ValuesFromTimestamp(CVIAbsoluteTime timestamp, int64* secondsSince1970, float64* fractionalSeconds) = 0;
  virtual int32 WaitForAcquisitionComplete(niRFmxInstrHandle instrumentHandle, float64 timeout) = 0;
};

}  // namespace nirfmxinstr_grpc
#endif  // NIRFMXINSTR_GRPC_LIBRARY_WRAPPER_H
