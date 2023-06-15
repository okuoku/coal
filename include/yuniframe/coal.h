#ifndef YUNIFRAME__COAL_H
#define YUNIFRAME__COAL_H

#ifdef __cplusplus
extern "C" {
#endif
/* } */

#define COAL_API

#include <stdint.h>
#include <stddef.h>

/* Context */
struct coal_ctx_s;
typedef struct coal_ctx_s coal_ctx;

#include "coal_enums.h"
typedef enum coal_enum_e coal_enum;
typedef enum coal_ctx_enum_e coal_ctx_enum;
typedef enum coal_effect_type_e coal_effect_type;
typedef enum coal_filter_type_e coal_filter_type;
typedef enum coal_advreverb_param_e coal_advreverb_param;
typedef enum coal_reverb_param_e coal_reverb_param;
typedef enum coal_chorus_param_e coal_chorus_param;
typedef enum coal_chorus_waveform_e coal_chorus_waveform;
typedef enum coal_distortion_param_e  coal_distortion_param;
typedef enum coal_flanger_param_e coal_flanger_param;
typedef enum coal_flanger_waveform_e coal_flanger_waveform;
typedef enum coal_echo_param_e coal_echo_param;
typedef enum coal_frequency_shifter_param_e coal_frequency_shifter_param;
typedef enum coal_vocal_morpher_param_e coal_vocal_morpher;
typedef enum coal_vocal_morpher_phoneme_e coal_vocal_morpher_phoneme;
typedef enum coal_pitch_shifter_param_e coal_pitch_shifter_param;
typedef enum coal_ring_modulator_param_e coal_ring_modulator;
typedef enum coal_autowah_param_e coal_autowah_param;
typedef enum coal_compressor_param_e coal_compressor_param;
typedef enum coal_equalizer_param_e coal_equalizer_param;
typedef enum coal_filter_type_e coal_filter_type;
typedef enum coal_lowpass_param_e coal_lowpass_param;
typedef enum coal_highpass_param_e coal_highpass_param;
typedef enum coal_bandpass_param_e coal_bandpass_param;

enum coal_boolean_e {
    COAL_FALSE = 0,
    COAL_TRUE = 1
};

typedef enum coal_boolean_e coal_boolean;

enum coal_query_result_e {
    COAL_QR_SUCCESS = 0,
    COAL_QR_ALERROR = 1,
    COAL_QR_UNIMPLEMENTED = 3,
};

typedef enum coal_query_result_e coal_query_result;


/* Objects */
struct coal_string_s;
typedef struct coal_string_s coal_string;
COAL_API size_t coal_string_size(coal_ctx* ctx, coal_string* str);
COAL_API coal_query_result coal_string_read(coal_ctx* ctx, coal_string* str,
                                            char* buf, size_t buflen);
struct coal_Buffer_s;
struct coal_Source_s;
struct coal_Device_s;
typedef struct coal_Buffer_s coal_Buffer;
typedef struct coal_Source_s coal_Source;
typedef struct coal_Device_s coal_Device;

COAL_API void coal_Buffer_release(coal_ctx* ctx, coal_Buffer* buffer);
COAL_API void coal_Source_release(coal_ctx* ctx, coal_Source* source);
COAL_API void coal_Device_release(coal_ctx* ctx, coal_Device* device);

/* 2.7. AL Errors */
COAL_API coal_enum coal_getError(coal_ctx* ctx);

/* 2.8. Controlling AL Execution */
COAL_API void coal_enable(coal_ctx* ctx, coal_enum target);
COAL_API void coal_disable(coal_ctx* ctx, coal_enum target);

/* 2.12. Requesting Object Names */
COAL_API coal_Buffer* coal_createBuffer(coal_ctx* ctx);
COAL_API coal_Source* coal_createSource(coal_ctx* ctx);
/* 2.13. Releasing Object Names */
COAL_API void coal_deleteBuffer(coal_ctx* ctx, coal_Buffer* buffer);
COAL_API void coal_deleteSource(coal_ctx* ctx, coal_Source* source);

/* 3.1.1. Simple Queries */
COAL_API coal_query_result coal_getParameter_b1(coal_ctx* ctx, 
                                                coal_enum paramName,
                                                coal_boolean* b1);
COAL_API coal_query_result coal_getParameter_i1(coal_ctx* ctx,
                                                coal_enum paramName,
                                                int* i1);
COAL_API coal_query_result coal_getParameter_f1(coal_ctx* ctx,
                                                coal_enum paramName,
                                                float* f1);
COAL_API coal_query_result coal_getParameter_d1(coal_ctx* ctx,
                                                coal_enum paramName,
                                                double* d1);
COAL_API coal_query_result coal_getParameter_str(coal_ctx* ctx,
                                                 coal_enum paramName,
                                                 coal_string** str);


/* 3.4. Attenuation By Distance */
COAL_API void coal_distanceModel(coal_ctx* ctx, coal_enum modelName);

/* 3.5.2. Velocity Dependent Doppler Effect */
COAL_API void coal_dopplerFactor(coal_ctx* ctx, float dopplerFactor);
COAL_API void coal_speedOfSound(coal_ctx* ctx, float speed);

/* 4.2.2. Changing Listener Attributes */
COAL_API void coal_listenerParameter_f1(coal_ctx* ctx,
                                        coal_enum paramName,
                                        float f0);
COAL_API void coal_listenerParameter_f3(coal_ctx* ctx,
                                        coal_enum paramName,
                                        float f0, float f1, float f2);
COAL_API void coal_listenerParameter_f6(coal_ctx* ctx,
                                        coal_enum paramName,
                                        float f0, float f1, float f2, float f3,
                                        float f4, float f5);

/* 4.2.3. Querying Listener Attributes */
COAL_API coal_query_result coal_getListenerParameter_f1(coal_ctx* ctx,
                                                        coal_enum paramName,
                                                        float* f0);
COAL_API coal_query_result coal_getListenerParameter_f3(coal_ctx* ctx,
                                                        coal_enum paramName,
                                                        float* f0, float* f1, 
                                                        float* f2);
COAL_API coal_query_result coal_getListenerParameter_f6(coal_ctx* ctx,
                                                        coal_enum paramName,
                                                        float* f0, float* f1, 
                                                        float* f2, float* f3, 
                                                        float* f4, float* f5);
/* 4.3.1. Managing Source Names */
// alGenSources also here
// alDeleteSources also here

/* 4.3.3. Changing Source Attributes */
COAL_API void coal_sourceParameter_i1(coal_ctx* ctx,
                                      coal_enum paramName,
                                      int i0);
COAL_API void coal_sourceParameter_f1(coal_ctx* ctx,
                                      coal_enum paramName,
                                      float f0);
COAL_API void coal_sourceParameter_f3(coal_ctx* ctx,
                                      coal_enum paramName,
                                      float f0, float f1, float f2);

/* 4.3.4. Querying Source Attributes */
COAL_API coal_query_result coal_getSourceParameter_i1(coal_ctx* ctx,
                                                      coal_enum paramName,
                                                      int i0);
COAL_API coal_query_result coal_getSourceParameter_f1(coal_ctx* ctx,
                                                      coal_enum paramName,
                                                      float f0);
COAL_API coal_query_result coal_getSourceParameter_f3(coal_ctx* ctx,
                                                      coal_enum paramName,
                                                      float f0, float f1, 
                                                      float f2);




/* 4.3.5. Queueing Buffers with a Source */
COAL_API void coal_sourceQueueBuffer(coal_ctx* ctx, coal_Source* source,
                                     coal_Buffer* buffer);
COAL_API void coal_sourceUnqueueBuffer(coal_ctx* ctx, coal_Source* source,
                                       coal_Buffer* buffer);
/* 4.3.6. Managing Source Execution */
COAL_API void coal_sourcePlay(coal_ctx* ctx, coal_Source* source);
COAL_API void coal_sourcePause(coal_ctx* ctx, coal_Source* source);
COAL_API void coal_sourceStop(coal_ctx* ctx, coal_Source* source);
COAL_API void coal_sourceRewind(coal_ctx* ctx, coal_Source* source);
COAL_API void coal_sourcePlayv(coal_ctx* ctx, size_t n, coal_Source** sources);
COAL_API void coal_sourcePausev(coal_ctx* ctx, size_t n, coal_Source** sources);
COAL_API void coal_sourceStopv(coal_ctx* ctx, size_t n, coal_Source** sources);
COAL_API void coal_sourceRewindv(coal_ctx* ctx, size_t n, 
                                 coal_Source** sources);

/* 5.2.1. Requesting Buffers Names */
// alGenBuffers also here
/* 5.2.2. Releasing Buffer Names */
// alDeleteBUffers also here
/* 5.3.2. Changing Buffer Attributes */
COAL_API void coal_bufferParameter_i1(coal_ctx* ctx,
                                      coal_enum paramName,
                                      int i0);

/* 5.3.3. Querying Buffer Attributes */
COAL_API coal_query_result coal_getBufferParameter_i1(coal_ctx* ctx,
                                                      coal_enum paramName,
                                                      int* i0);

/* 5.3.4. Specifying Buffer Content */
COAL_API void coal_bufferData(coal_ctx* ctx, coal_Buffer* buffer,
                              coal_enum format, const void* data,
                              size_t size, int frequency);

/* 6.1.1. Connecting to a Device */
COAL_API coal_device* coal_openDevice0(const char* deviceSpecifier);
/* 6.1.2. Disconnecting from a Device */
COAL_API coal_boolean coal_closeDevice0(coal_device* deviceHandle);
/* 6.2.2. Creating a Context */
COAL_API coal_ctx* coal_createContext0(coal_device* deviceHandle,
                                       const coal_ctx_enum* attrList,
                                       int attrcount);

/* 6.2.4. Initiate Context Processing */
COAL_API void coal_processContext(coal_ctx* ctx);
/* 6.2.5. Suspend Context Processing */
COAL_API void coal_suspendContext(coal_ctx* ctx);
/* 6.2.6. Destroying a Context */
COAL_API void coal_destroyContext(coal_ctx* ctx);
/* 6.3.3. Query For Extensions */
COAL_API coal_boolean coal_isExtensionPresent0(coal_device* deviceHandle,
                                               const char* extName);
/* 6.3.6. Query for Error Conditions */
COAL_API coal_ctx_enum coal_getError_ctx0(coal_device* deviceHandle);

/* 6.3.7. String Query */
COAL_API coal_query_result coal_getParameter_ctx0_str(coal_device* deviceHandle,
                                                      coal_ctx_enum token,
                                                      coal_string** str);
/* 6.3.8. Integer Query */
COAL_API coal_query_result coal_getParameter_ctx0_i1(coal_device* deviceHandle,
                                                     coal_ctx_enum token,
                                                     int* i0);

/* Effects Extension (Standard + EAX) */
struct coal_AuxiliaryEffectSlot_s;
struct coal_Effect_s;
struct coal_Filter_s;
typedef struct coal_AuxiliaryEffectSlot_s coal_AuxiliaryEffectSlot;
typedef struct coal_Effect_s coal_Effect;
typedef struct coal_Filter_s coal_Filter;
COAL_API void coal_AuxiliaryEffectSlot_release(coal_ctx* ctx,
                                               coal_AuxiliaryEffectSlot* obj);
COAL_API void coal_Effect_release(coal_ctx* ctx, coal_Effect* effect);
COAL_API void coal_Filter_release(coal_ctx* ctx, coal_Effect* filter);

/* Auxiliary Effect Slot Object */
/* Management Functions */
COAL_API coal_AuxiliaryEffectSlot* coal_createAuxiliaryEffectSlot(coal_ctx* ctx);
COAL_API void coal_deleteAuxiliaryEffectSlot(coal_ctx* ctx,
                                             coal_AuxiliaryEffectSlot* obj);
/* Property Functions */
COAL_API void coal_auxiliaryEffectSlotParameter_b1(coal_ctx* ctx,
                                                   coal_AuxiliaryEffectSlot* obj,
                                                   coal_enum paramName,
                                                   coal_bool b0);
COAL_API void coal_auxiliaryEffectSlotParameter_f1(coal_ctx* ctx,
                                                   coal_AuxiliaryEffectSlot* obj,
                                                   coal_enum paramName,
                                                   float f0);
COAL_API void coal_auxiliaryEffectSlotParameter_effect(coal_ctx* ctx,
                                                       coal_AuxiliaryEffectSlot* obj,
                                                       coal_enum paramName,
                                                       coal_Effect* effect);

/* Query Property Functions */
COAL_API coal_query_result coal_getAuxiliaryEffectSlotParameter_b1(coal_ctx* ctx,
                                                                   coal_AuxiliaryEffectSlot* obj,
                                                                   coal_enum paramName,
                                                                   coal_bool* b0);
COAL_API coal_query_result coal_getAuxiliaryEffectSlotParameter_f1(coal_ctx* ctx,
                                                                   coal_AuxiliaryEffectSlot* obj,
                                                                   coal_enum paramName,
                                                                   float* f0);
COAL_API coal_query_result coal_getAuxiliaryEffectSlotParameter_effect(coal_ctx* ctx,
                                                                       coal_AuxiliaryEffectSlot* obj,
                                                                       coal_enum paramName,
                                                                       coal_Effect** effect);

/* Effect Object */
/* Management Functions */
COAL_API coal_Effect* coal_createEffect(coal_ctx* ctx);
COAL_API void coal_deleteEffect(coal_ctx* ctx, coal_Effect* effect);

/* Property Functions */
COAL_API void coal_effectParameter_b1(coal_ctx* ctx, coal_Effect* obj,
                                      int paramName, coal_boolean b0);
COAL_API void coal_effectParameter_i1(coal_ctx* ctx, coal_Effect* obj,
                                      int paramName, int i0);
COAL_API void coal_effectParameter_f1(coal_ctx* ctx, coal_Effect* obj,
                                      int paramName, float f0);
COAL_API void coal_effectParameter_f3(coal_ctx* ctx, coal_Effect* obj,
                                      int paramName, float f0);

/* Query Property Functions */
COAL_API coal_query_result coal_getEffectParameter_b1(coal_ctx* ctx,
                                                      coal_Effect* obj,
                                                      int paramName,
                                                      coal_boolean* b0);
COAL_API coal_query_result coal_getEffectParameter_i1(coal_ctx* ctx,
                                                      coal_Effect* obj,
                                                      int paramName,
                                                      int* i0);
COAL_API coal_query_result coal_getEffectParameter_f1(coal_ctx* ctx,
                                                      coal_Effect* obj,
                                                      int paramName,
                                                      float* f0);
COAL_API coal_query_result coal_getEffectParameter_f3(coal_ctx* ctx,
                                                      coal_Effect* obj,
                                                      int paramName,
                                                      float* f0, float* f1,
                                                      float* f2);

/* Filter Object */
/* Management Functions */
COAL_API coal_Filter* coal_createFilter(coal_ctx* ctx);
COAL_API void coal_deleteFilter(coal_ctx* ctx, coal_Filter* filter);

/* Property Functions */
COAL_API void coal_filterParameter_b1(coal_ctx* ctx, coal_Filter* obj,
                                      int paramName, coal_boolean b0);
COAL_API void coal_filterParameter_i1(coal_ctx* ctx, coal_Filter* obj,
                                      int paramName, int i0);
COAL_API void coal_filterParameter_f1(coal_ctx* ctx, coal_Filter* obj,
                                      int paramName, float f0);

/* Query Property Functions */
COAL_API coal_query_result coal_getFilterParameter_b1(coal_ctx* ctx,
                                                      coal_Filter* obj,
                                                      int paramName,
                                                      coal_boolean* b0);
COAL_API coal_query_result coal_getFilterParameter_i1(coal_ctx* ctx,
                                                      coal_Filter* obj,
                                                      int paramName,
                                                      int* b0);
COAL_API coal_query_result coal_getFilterParameter_f1(coal_ctx* ctx,
                                                      coal_Filter* obj,
                                                      int paramName,
                                                      float* b0);

/* Source Object Extensions */
COAL_API void coal_sourceParameter_filter(coal_ctx* ctx,
                                          coal_enum paramName,
                                          coal_filter* filter);
COAL_API void coal_getSourceParameter_filter(coal_ctx* ctx,
                                             coal_enum paramName,
                                             coal_filter** filter);
/* { */
#ifdef __cplusplus
};
#endif

#endif
