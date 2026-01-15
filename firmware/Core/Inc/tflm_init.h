#ifndef TFLM_INIT_H
#define TFLM_INIT_H

#include "main.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"

extern tflite::MicroInterpreter* tflm_interpreter;
extern TfLiteTensor* tflm_input;
extern TfLiteTensor* tflm_output;

void tflm_init(void);

#endif
