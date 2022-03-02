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
                'enum': 'CloseAttribute',
                'type': 'uint32_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    # NiFpga_Status NiFpga_GetBitfileSignature(NiFpga_Session session,
    #                                          uint32_t* signature,
    #                                          size_t*   signatureSize);
    # NiFpga_Status NiFpga_FindRegister(NiFpga_Session session,
    #                                   const char* registerName,
    #                                   uint32_t* registerOffset);
    # NiFpga_Status NiFpga_FindFifo(NiFpga_Session session,
    #                               const char* fifoName,
    #                               uint32_t* fifoNumber);
    'Run': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'enum': 'RunAttribute',
                'type': 'uint32_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    # NiFpga_Status NiFpga_Abort(NiFpga_Session session);
    'Reset': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'Download': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    # NiFpga_Status NiFpga_GetFpgaViState(NiFpga_Session session,
    #                                     uint32_t*      state);

    # Scalar read functions
    'ReadBool': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t',
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'NiFpga_Bool',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'ReadI8': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t',
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int8_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'ReadU8': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t',
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uint8_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'ReadI16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t',
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int16_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'ReadU16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t',
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uint16_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'ReadI32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t',
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'ReadU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t',
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uint32_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'ReadI64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t',
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int64_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'ReadU64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t',
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uint64_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    # NiFpga_Status NiFpga_ReadSgl(NiFpga_Session session,
    #                              uint32_t       indicator,
    #                              float*         value);
    # NiFpga_Status NiFpga_ReadDbl(NiFpga_Session session,
    #                              uint32_t       indicator,
    #                              double*        value);

    # Scalar write functions
    'WriteBool': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t',
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'NiFpga_Bool',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'WriteI8': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t',
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int8_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'WriteU8': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t',
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uint8_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'WriteI16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t',
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int16_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'WriteU16': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t',
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uint16_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'WriteI32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t',
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int32_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'WriteU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t',
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uint32_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'WriteI64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t',
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int64_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'WriteU64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'control',
                'type': 'uint32_t',
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uint64_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    # NiFpga_Status NiFpga_WriteSgl(NiFpga_Session session,
    #                               uint32_t       control,
    #                               float          value);
    # NiFpga_Status NiFpga_WriteDbl(NiFpga_Session session,
    #                               uint32_t       control,
    #                               double         value);
    
    # Array Read functions
    # NiFpga_Status NiFpga_ReadArrayBool(NiFpga_Session session,
    #                                    uint32_t       indicator,
    #                                    NiFpga_Bool*   array,
    #                                    size_t         size);
    # NiFpga_Status NiFpga_ReadArrayI8(NiFpga_Session session,
    #                                  uint32_t       indicator,
    #                                  int8_t*        array,
    #                                  size_t         size);
    # NiFpga_Status NiFpga_ReadArrayU8(NiFpga_Session session,
    #                                  uint32_t       indicator,
    #                                  uint8_t*       array,
    #                                  size_t         size);
    'ReadArrayI16': {
        #'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t',
            },
            {
                'coerced': True,
                'direction': 'out',
                'name': 'array',
                'type': 'int16_t[]',
                #'grpc_type': 'repeated int32',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                },
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'ReadArrayU16': {
        #'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t',
            },
            {
                'coerced': True,
                'direction': 'out',
                'name': 'array',
                'type': 'uint16_t[]',
                #'grpc_type': 'repeated uint32',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                },
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    # # NiFpga_Status NiFpga_ReadArrayI32(NiFpga_Session session,
    # #                                   uint32_t       indicator,
    # #                                   int32_t*       array,
    # #                                   size_t         size);
    # # NiFpga_Status NiFpga_ReadArrayU32(NiFpga_Session session,
    # #                                   uint32_t       indicator,
    # #                                   uint32_t*      array,
    # #                                   size_t         size);
    'ReadArrayI64': {
        #'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t',
            },
            {
                'coerced': True,
                'direction': 'out',
                'name': 'array',
                'type': 'int64_t[]',
                #'grpc_type': 'repeated int64',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                },
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
    'ReadArrayU64': {
        #'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
            },
            {
                'direction': 'in',
                'name': 'indicator',
                'type': 'uint32_t',
            },
            {
                'coerced': True,
                'direction': 'out',
                'name': 'array',
                'type': 'uint64_t[]',
                #'grpc_type': 'repeated uint64',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                },
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'size_t',
            }
        ],
        'returns': 'NiFpga_Status',
    },
}

