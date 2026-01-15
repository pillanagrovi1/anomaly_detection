# Deployment Pipeline

Deployment path:

[PyTorch → ONNX → TFLite Micro → ARM Cortex-M4F]


## 1. Model Export

Model architecture exported via ONNX.

Training omitted from public repo due to confidentiality of datasets (2025).

## 2. Quantization

Post-training quantization considered for:

- Memory reduction
- Lower latency
- Deterministic inference

Quantization notes are provided in `training/quant_notes.md`.

## 3. Interpreter

TinyML inference uses:

- MicroInterpreter
- MicroMutableOpResolver
- Static tensor arena (20 KB)
- No dynamic allocation

## 4. Runtime

Firmware performs end-to-end processing:

DMA → Window → FFT → Features → Normalize → Inference → UART

This pipeline executes in bounded latency suitable for real-time diagnostics.




