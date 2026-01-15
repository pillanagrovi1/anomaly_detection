#ifndef FFT_H
#define FFT_H

#include "main.h"
#include "arm_math.h"

void fft_init(void);
void fft_compute(float* time_buf, float* mag_buf);

#endif
