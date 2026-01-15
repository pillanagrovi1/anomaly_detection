#include "tflm_init.h"
#include "model_data.h"  // contains model structure WITHOUT weights

constexpr int kArenaSize = 20 * 1024;  // safe for STM32F446RE
static uint8_t tensor_arena[kArenaSize];

tflite::MicroInterpreter* tflm_interpreter = nullptr;
TfLiteTensor* tflm_input = nullptr;
TfLiteTensor* tflm_output = nullptr;

void tflm_init(void)
{
    static tflite::MicroErrorReporter micro_error_reporter;
    tflite::ErrorReporter* error_reporter = &micro_error_reporter;

    const tflite::Model* model = tflite::GetModel(g_model_data);
    if (model->version() != TFLITE_SCHEMA_VERSION)
    {
        error_reporter->Report("Model schema mismatch.");
        return;
    }

    static tflite::MicroMutableOpResolver<5> resolver;
    resolver.AddFullyConnected();
    resolver.AddMul();
    resolver.AddAdd();
    resolver.AddReshape();
    resolver.AddLogistic();    // in case model uses final sigmoid

    static tflite::MicroInterpreter static_interpreter(
        model, resolver, tensor_arena, kArenaSize, error_reporter);

    tflm_interpreter = &static_interpreter;

    if (tflm_interpreter->AllocateTensors() != kTfLiteOk)
    {
        error_reporter->Report("Tensor allocation failed.");
        return;
    }

    tflm_input  = tflm_interpreter->input(0);
    tflm_output = tflm_interpreter->output(0);
}
