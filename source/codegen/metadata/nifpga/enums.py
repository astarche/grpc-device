enums = {
    'OpenAttribute': {
        'generate-mappings': True,
        'values': [
            {
                'name': 'NoRun',
                'value': 1
            },
            {
                'name': 'BitfilePathIsUTF8',
                'value': 2
            },
            {
                'name': 'BitfileContentsNotPath',
                'value': 1073741824 # 1u << 30
            },
            {
                'name': 'IgnoreSignatureArgument',
                'value': 2147483648 # 1u << 31
            },
        ]
    },
    'CloseAttribute': {
        'values': [
            {
                'name': 'NoResetIfLastSession',
                'value': 1
            }
        ]
    },
    'RunAttribute': {
        'values': [
            {
                'name': 'WaitUntilDone',
                'value': 1
            }
        ]
    }
}
