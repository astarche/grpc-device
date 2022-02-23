config = {
    'api_version': '21.5.0',
    'c_header': 'NiFpga.h',
    'c_function_prefix': 'NiFpga_',
    'service_class_prefix': 'NiFpga',
    'java_package': 'com.ni.grpc.nifpga',
    'csharp_namespace': 'NationalInstruments.Grpc.NiFpga',
    'namespace_component': 'nifpga',
    'close_function': 'Close ',
    'custom_types': [],
    'type_to_grpc_type': {
        'NiFpga_Session': 'nidevice_grpc.Session',
        'const char*': 'string',
        'char*': 'string',
        'uint32_t': 'uint32',
    },
    'driver_name': 'NI-FPGA',
    'extra_errors_used': [],
    'init_function': 'Open',
    'resource_handle_type': 'NiFpga_Session',
    'status_ok': 'status >= 0',
    'no_libs': True,
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'NiFpga',
                'type': 'cdll',
                'abi_version' : 13
            }
        },
        'Windows': {
            '32bit': {
                'name': 'NiFpga.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'NiFpga.dll',
                'type': 'cdll'
            }
        }
    },
    'metadata_version': '0.1',
    'module_name': 'nifpga',
    'session_class_description': 'An NI-FPGA session',
    'session_handle_parameter_name': 'session'
}
