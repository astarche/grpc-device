functions = {
    # NiFpga_Status NiFpga_Open(const char*     bitfile,
    #                           const char*     signature,
    #                           const char*     resource,
    #                           uint32_t        attribute,
    #                           NiFpga_Session* session);
    'Initialize': {
        'parameters': [],
        'returns': 'NiFpga_Status',
    },
    'Finalize': {
        'parameters': [],
        'returns': 'NiFpga_Status',
    },
    'Open': {
        'init_method': True,
        'custom_close_method': True,
        'custom_close': 'Close(id, 0)',
        'parameters': [
            {
                'direction': 'in',
                'name': 'bitfile',
                'type': 'const char*',
                'pointer': True,
            },
            {
                'direction': 'in',
                'name': 'signature',
                'type': 'const char*',
                'pointer': True,
            },
            {
                'direction': 'in',
                'name': 'resource',
                'type': 'const char*',
                'pointer': True,
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'enum': 'OpenAttribute',
                'type': 'uint32_t',
            },
            {
                'direction': 'out',
                'name': 'session',
                'type': 'NiFpga_Session',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'Close': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'uint32_t',
            }
        ],
        'returns': 'NiFpga_Status',
    }
}

