r"""Scan a series of channels on a module using software scanning.

The gRPC API is built from the C API. NI-SWITCH documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niSwitch\Documentation\English\SWITCH.chm

A version of this .chm is available online at:
  https://zone.ni.com/reference/en-XX/help/375472H-01/

Getting Started:

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-SWITCH Help to determine if your module supports scanning, the scan list syntax,
valid channel names and valid resource names.

Refer to the NI-SWITCH gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-SWITCH-C-Function-Reference

Running from command line:

Server machine's IP address and port numbercan be passed as separate command line arguments.
  > python software-scanning.py <server_address> <port_number>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763".
To successfully run this example, the resource name, topology, and scan list must be hard coded in
this file.
"""

import sys
import time

import grpc
import niswitch_pb2 as niswitch_types
import niswitch_pb2_grpc as grpc_niswitch

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"

# Resource name, topology string and scanlist for a simulated 2529 module. Refer to NI-SWITCH help
# to find valid values for the device being used.
# If you are using real hardware device, use the appropriate resource name and set the SIMULATION
# variable to False.
RESOURCE = ""
TOPOLOGY_STRING = "2529/2-Wire Dual 4x16 Matrix"
SCAN_LIST = "b0r1->b0c1;b0r1->b0c2;b0r2->b0c3"
SIMULATION = True

SESSION_NAME = "NI-Switch-Session-1"

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]

# Create the communcation channel for the remote host and create a connection to the NI-SWITCH
# service.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
niswitch_client = grpc_niswitch.NiSwitchStub(channel)
number_of_triggers = 5


def check_for_error(vi, status):
    """Raise an exception if the status indicates an error."""
    if status != 0:
        error_message_response = niswitch_client.ErrorMessage(
            niswitch_types.ErrorMessageRequest(vi=vi, error_code=status)
        )
        raise Exception(error_message_response.error_message)


try:
    # Open session to NI-SWITCH and set topology.
    init_with_topology_response = niswitch_client.InitWithTopology(
        niswitch_types.InitWithTopologyRequest(
            session_name=SESSION_NAME,
            resource_name=RESOURCE,
            topology=TOPOLOGY_STRING,
            simulate=SIMULATION,
            reset_device=False,
        )
    )
    vi = init_with_topology_response.vi
    check_for_error(vi, init_with_topology_response.status)
    print("Topology set to : ", TOPOLOGY_STRING)

    # Configure the scan list.
    check_for_error(
        vi,
        (
            niswitch_client.ConfigureScanList(
                niswitch_types.ConfigureScanListRequest(
                    vi=vi,
                    scanlist=SCAN_LIST,
                    scan_mode=niswitch_types.ScanMode.SCAN_MODE_NISWITCH_VAL_BREAK_BEFORE_MAKE,
                )
            )
        ).status,
    )

    # Configures the trigger to be software trigger.
    check_for_error(
        vi,
        (
            niswitch_client.ConfigureScanTrigger(
                niswitch_types.ConfigureScanTriggerRequest(
                    vi=vi,
                    trigger_input=niswitch_types.TriggerInput.TRIGGER_INPUT_NISWITCH_VAL_SOFTWARE_TRIG,
                    scan_advanced_output=niswitch_types.ScanAdvancedOutput.SCAN_ADVANCED_OUTPUT_NISWITCH_VAL_NONE,
                )
            )
        ).status,
    )
    print("Configured the trigger as Software Trigger")

    # Loop through scan list continuously
    check_for_error(
        vi,
        (
            niswitch_client.SetContinuousScan(
                niswitch_types.SetContinuousScanRequest(vi=vi, continuous_scan=True)
            )
        ).status,
    )

    # Initiate scanning
    check_for_error(
        vi, (niswitch_client.InitiateScan(niswitch_types.InitiateScanRequest(vi=vi))).status
    )
    print("Scanning initiated...")

    # Send software trigger to module in a loop
    for x in range(number_of_triggers):
        # Wait for 500 ms
        time.sleep(0.5)
        check_for_error(
            vi,
            (
                niswitch_client.SendSoftwareTrigger(
                    niswitch_types.SendSoftwareTriggerRequest(vi=vi)
                )
            ).status,
        )
        number_of_triggers = number_of_triggers - 1

    # Abort Scanning
    check_for_error(vi, (niswitch_client.AbortScan(niswitch_types.AbortScanRequest(vi=vi))).status)
    print("Scanning completed.")

# If NI-SWITCH API throws an exception, print the error message
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
        error_message = f"Failed to connect to server on {SERVER_ADDRESS}:{SERVER_PORT}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = (
            "The operation is not implemented or is not supported/enabled in this service"
        )
    print(f"{error_message}")

finally:
    if "vi" in vars() and vi.id != 0:
        # close the session.
        check_for_error(vi, (niswitch_client.Close(niswitch_types.CloseRequest(vi=vi))).status)
