//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Mock of LibraryInterface for NI-DAQMX
//---------------------------------------------------------------------
#ifndef NIDAQMX_GRPC_MOCK_LIBRARY_H
#define NIDAQMX_GRPC_MOCK_LIBRARY_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "nidaqmx_library_interface.h"

namespace ni {
namespace tests {
namespace unit {

class NiDAQmxMockLibrary : public nidaqmx_grpc::NiDAQmxLibraryInterface {
 public:
  MOCK_METHOD(int32, CreateTask, (const char* taskName, TaskHandle* task), (override));
  MOCK_METHOD(int32, ClearTask, (TaskHandle task), (override));
  MOCK_METHOD(int32, StartTask, (TaskHandle task), (override));
  MOCK_METHOD(int32, StopTask, (TaskHandle task), (override));
  MOCK_METHOD(int32, CreateAIVoltageChan, (TaskHandle task, const char* physical_channel, const char* name_to_assign_to_channel, int32 terminal_config, double min_val, double max_val, int32 units, const char* custom_scale_name), (override));
  MOCK_METHOD(int32, GetChanAttributeU32, (TaskHandle task, const char* channel, int32 attribute, uInt32* value), (override));
  MOCK_METHOD(int32, SetChanAttributeU32, (TaskHandle task, const char* channel, int32 attribute, uInt32 value), (override));
  MOCK_METHOD(int32, GetChanAttributeF64, (TaskHandle task, const char* channel, int32 attribute, double* value), (override));
  MOCK_METHOD(int32, SetChanAttributeF64, (TaskHandle task, const char* channel, int32 attribute, double value), (override));
  MOCK_METHOD(int32, GetChanAttributeStr, (TaskHandle task, const char* channel, int32 attribute, char value[], int32 size), (override));
  MOCK_METHOD(int32, SetChanAttributeStr, (TaskHandle task, const char* channel, int32 attribute, const char* value), (override));
  MOCK_METHOD(int32, ReadAnalogF64, (TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, float64 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved), (override));
  MOCK_METHOD(int32, ReadAnalogF64StreamCodegen, (TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, float64 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved), (override));
  MOCK_METHOD(int32, ReadAnalogF64StreamCustom, (TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, float64 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved), (override));
  MOCK_METHOD(int32, CfgSampClkTiming, (TaskHandle task, const char* source, double rate, int32 active_edge, int32 sample_mode, uInt64 samps_per_chan), (override));
};

}  // namespace unit
}  // namespace tests
}  // namespace ni
#endif  // NIDAQMX_GRPC_MOCK_LIBRARY_H
