#include "window.h"
#include <math.h>

static float w[DSP_FRAME_SIZE];

void window_init(void)
{
    for (uint16_t i = 0; i < DSP_FRAME_SIZE; i++)
    {
        w[i] = 0.5f * (1.0f - cosf((2.0f * M_PI * i) / (DSP_FRAME_SIZE - 1)));
    }
}

void apply_window(float* x)
{
    for (uint16_t i = 0; i < DSP_FRAME_SIZE; i++)
    {
        x[i] *= w[i];
    }
}
