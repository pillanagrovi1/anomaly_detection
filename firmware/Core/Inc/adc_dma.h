#ifndef ADC_DMA_H
#define ADC_DMA_H

#include "main.h"

#define SAMPLE_RATE_HZ  8000
#define DSP_FRAME_SIZE  512

extern uint16_t adc_buffer[DSP_FRAME_SIZE];
extern volatile uint8_t adc_half_ready;
extern volatile uint8_t adc_full_ready;

void ADC_DMA_Init(void);

#endif
