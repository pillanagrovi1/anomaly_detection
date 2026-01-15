#include "fft.h"

static arm_rfft_fast_instance_f32 rfft;

void fft_init(void)
{
    arm_rfft_fast_init_f32(&rfft, DSP_FRAME_SIZE);
}

void fft_compute(float* time_buf, float* mag_buf)
{
    static float fft_out[DSP_FRAME_SIZE];

    arm_rfft_fast_f32(&rfft, time_buf, fft_out, 0);

    for (uint16_t i = 0; i < DSP_FRAME_SIZE / 2; i++)
    {
        float real = fft_out[2*i];
        float imag = fft_out[2*i + 1];
        mag_buf[i] = sqrtf(real*real + imag*imag);
    }
}
