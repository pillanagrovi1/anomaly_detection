#ifndef DSP_PIPELINE_H
#define DSP_PIPELINE_H

#include "main.h"

#define FEATURE_DIM   5

void dsp_pipeline_init(void);
uint8_t dsp_pipeline_process(float* out_features);

#endif
