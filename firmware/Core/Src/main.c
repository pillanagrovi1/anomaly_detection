#include "main.h"
#include "dsp_pipeline.h"
#include "tflm_init.h"
#include "tflm_invoke.h"
#include "uart_if.h"

float features[FEATURE_DIM];

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    
    MX_GPIO_Init();
    MX_DMA_Init();
    MX_ADC1_Init();
    MX_USART2_UART_Init();

    dsp_pipeline_init();
    tflm_init();

    while (1)
    {
        if (dsp_pipeline_process(features))
        {
            int cls = tflm_run_inference(features);
            uart_send_class(cls);
        }
    }
}
