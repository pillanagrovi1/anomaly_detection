#include "dsp_pipeline.h"
#include "adc_dma.h"
#include "window.h"
#include "fft.h"
#include "features.h"
#include "normalize.h"

static float time_buf[DSP_FRAME_SIZE];
static float mag_buf[DSP_FRAME_SIZE/2];
static float feat_temp[FEATURE_DIM];

void dsp_pipeline_init(void)
{
    window_init();
    fft_init();
    ADC_DMA_Init();
}

uint8_t dsp_pipeline_process(float* out_features)
{
    uint8_t flag = ADC_DMA_Poll();

    if (flag == 0)
        return 0; // no data

    uint16_t offset = (flag == 1) ? 0 : (DSP_FRAME_SIZE/2);

    // Convert uint16 → float centered around zero
    for (uint16_t i = 0; i < DSP_FRAME_SIZE/2; i++)
    {
        time_buf[i] = (float)adc_buffer[i + offset] - 2048.0f; // DC offset approx
    }

    apply_window(time_buf);
    fft_compute(time_buf, mag_buf);
    features_compute(time_buf, mag_buf, feat_temp);
    normalize_features(feat_temp, out_features);

    return 1;
}
