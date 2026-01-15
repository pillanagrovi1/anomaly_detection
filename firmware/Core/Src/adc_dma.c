#include "adc_dma.h"

uint16_t adc_buffer[DSP_FRAME_SIZE];
volatile uint8_t adc_half_ready = 0;
volatile uint8_t adc_full_ready = 0;

void ADC_DMA_Init(void)
{
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_buffer, DSP_FRAME_SIZE);
}

void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef *hadc)
{
    adc_half_ready = 1;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    adc_full_ready = 1;
}
