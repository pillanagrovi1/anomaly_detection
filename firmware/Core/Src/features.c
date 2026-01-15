#include "features.h"
#include <math.h>

// RMS: sqrt(mean(x^2))
static float compute_rms(float* x, uint16_t n)
{
    float sum = 0.0f;
    for (uint16_t i = 0; i < n; i++)
        sum += x[i] * x[i];
    return sqrtf(sum / n);
}

// Crest Factor: peak/RMS
static float compute_crest_factor(float* x, uint16_t n, float rms)
{
    float peak = 0.0f;
    for (uint16_t i = 0; i < n; i++)
        if (fabsf(x[i]) > peak)
            peak = fabsf(x[i]);
    return rms > 0 ? (peak / rms) : 0;
}

// Zero Crossing Rate
static float compute_zcr(float* x, uint16_t n)
{
    uint16_t count = 0;
    for (uint16_t i = 1; i < n; i++)
        if ((x[i] > 0 && x[i-1] < 0) || (x[i] < 0 && x[i-1] > 0))
            count++;
    return (float)count / n;
}

// Spectral Energy: sum(mag^2)
static float compute_spectral_energy(float* mag, uint16_t n)
{
    float sum = 0.0f;
    for (uint16_t i = 0; i < n; i++)
        sum += mag[i] * mag[i];
    return sum;
}

// Dominant Frequency F0: argmax
static float compute_f0(float* mag, uint16_t n, float fs)
{
    uint16_t idx = 0;
    float peak = 0.0f;

    for (uint16_t i = 1; i < n; i++)
    {
        if (mag[i] > peak)
        {
            peak = mag[i];
            idx = i;
        }
    }
    return (fs * idx) / (2 * n);
}

// Master API
void features_compute(float* time_buf, float* mag_buf, float* out_features)
{
    float rms = compute_rms(time_buf, DSP_FRAME_SIZE);
    out_features[0] = rms;
    out_features[1] = compute_spectral_energy(mag_buf, DSP_FRAME_SIZE / 2);
    out_features[2] = compute_crest_factor(time_buf, DSP_FRAME_SIZE, rms);
    out_features[3] = compute_zcr(time_buf, DSP_FRAME_SIZE);
    out_features[4] = compute_f0(mag_buf, DSP_FRAME_SIZE / 2, SAMPLE_RATE_HZ);
}
