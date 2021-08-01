#include "Fw_global_config.h"
#include "sml_output.h"
#include "kb.h"
#include "ble_pme_defs.h"
#include "iop_messages.h"
#include "Recognition.h"
#include "dbg_uart.h"
#include "kb_debug.h"

static uint8_t fv_arr[MAX_VECTOR_SIZE];
#if SML_PROFILER
#define SERIAL_OUT_CHARS_MAX 1024
float recent_fv_times[MAX_VECTOR_SIZE];
unsigned int recent_fv_cycles[MAX_VECTOR_SIZE];
#else
#define SERIAL_OUT_CHARS_MAX 512
#endif

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-function"
#endif

static ble_pme_result_t recent_result;
static ble_pme_result_w_fv_t recent_fv_result;

static char serial_out_buf[SERIAL_OUT_CHARS_MAX];
static char *p_serial_out = serial_out_buf;

void SendLastRecognition()
{
    iop_send_pme_results(&recent_result);
}

void SendLastRecognitionWithFeatures()
{
    iop_send_feature_vector_results(&recent_fv_result);
}

static void sml_output_ble(uint16_t model, uint16_t classification)
{
    int current_state = GetRecognitionCurrentState();
    switch(current_state)
    {
        default:
            break;
        case RECOG_STATE_RUN:
            SendLastRecognition();
            break;
        case RECOG_STATE_RUN_W_FV:
            SendLastRecognitionWithFeatures();
            break;
        case RECOG_STATE_RUN_W_S:
            break;
    }
}

static void sml_output_led(uint16_t model, uint16_t classification)
{
    //Unused for right now.
}

static void sml_output_serial(uint16_t model_index, uint16_t model_result)
{
    if( !(DBG_flags & DBG_FLAG_recog_result) )
    {
        return;
    }
    kb_print_model_result(model_index, model_result, serial_out_buf, 1, fv_arr);
    dbg_str(serial_out_buf);
    #if SML_PROFILER
    memset(serial_out_buf, 0, 2048);
    kb_print_model_cycles(model_index, model_result, serial_out_buf, recent_fv_cycles);
    dbg_str(serial_out_buf);
    memset(serial_out_buf, 0, 2048);
    kb_print_model_times(model_index, model_result, serial_out_buf, recent_fv_times);
    dbg_str(serial_out_buf);
    #endif
    dbg_str(serial_out_buf);
    dbg_ch('\n');
}

uint32_t sml_output_results(uint16_t model, uint16_t classification)
{
    recent_result.context = model;
    recent_result.classification = classification;
    recent_fv_result.context = model;
    recent_fv_result.classification = classification;
    kb_get_feature_vector(model, recent_fv_result.feature_vector, &recent_fv_result.fv_len);

    sml_output_serial(model, classification);
    return 0;
}

uint32_t sml_output_init(void * p_module)
{
    //unused for now
}
