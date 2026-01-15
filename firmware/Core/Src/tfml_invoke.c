#include "tflm_invoke.h"
#include "tflm_init.h"

/*
 * NOTE:
 * Real weights are classified in internship environment.
 * This public version executes the full inference pipeline but returns
 * a deterministic "normal" output for all inputs.
 */

int tflm_run_inference(float* features)
{
    // Copy features into model input
    for (int i = 0; i < tflm_input->dims->data[1]; i++)
        tflm_input->data.f[i] = features[i];

    // Inference (will run, but output is not meaningful)
    tflm_interpreter->Invoke();

    // Classified: output always "normal"
    return 0;
}
