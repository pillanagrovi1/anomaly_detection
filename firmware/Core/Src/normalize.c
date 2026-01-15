#include "normalize.h"

// feature bounds (engineering estimates)
#define RMS_MAX            500.0f
#define ENERGY_MAX         1e6f
#define CREST_MAX          20.0f
#define ZCR_MAX            1.0f
#define FREQ_MAX           (SAMPLE_RATE_HZ / 2)

static float clamp01(float x)
{
    if (x < 0.0f) return 0.0f;
    if (x > 1.0f) return 1.0f;
    return x;
}

void normalize_features(float* f_in, float* f_out)
{
    f_out[0] = clamp01(f_in[0] / RMS_MAX);
    f_out[1] = clamp01(f_in[1] / ENERGY_MAX);
    f_out[2] = clamp01(f_in[2] / CREST_MAX);
    f_out[3] = clamp01(f_in[3] / ZCR_MAX);
    f_out[4] = clamp01(f_in[4] / FREQ_MAX);
}
