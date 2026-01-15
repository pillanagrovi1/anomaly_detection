# anomaly_detection

# Embedded Vibration Anomaly Detection using TinyML on STM32F446RE

This project implements a real-time anomaly detection pipeline on the STM32F446RE (ARM Cortex-M4F) using TinyML. The system extracts vibration features from raw sensor data and performs on-device binary classification.

This public repository contains the deployment architecture developed during a 2025 defense research internship. Due to confidentiality restrictions, datasets, training logs, validation results, and model weights are withheld.

---

## System Overview

The complete system consists of five stages:

[Sensor → ADC DMA → DSP → TinyML → Host Tools]


### 1. Signal Acquisition
- Sample rate: 8 kHz
- Window size: 512 samples
- DMA circular mode with half/full transfer interrupts

### 2. DSP Feature Extraction
- Hanning window
- FFT via CMSIS-DSP
- Five-dimensional feature vector:
- 
[RMS, Spectral Energy, Crest Factor, Zero Crossing Rate, Dominant Frequency]


### 3. TinyML Inference
- Model: MLP (5 → 16 → 8 → 2)
- Framework: TFLite Micro
- Deployment: Cortex-M4F
- Weights withheld (classified)

### 4. Host Tools
Python-based visualization tools parse binary anomaly outputs and support log export for analysis.

---

## Deployment Pipeline
[PyTorch → ONNX → TFLite Micro → ARM Cortex-M4F]


Interpreter and tensor arena operate without dynamic allocation.

---

## Memory & Timing Constraints

- DSP RAM: ~4 KB
- Tensor Arena: 20 KB
- Total RAM Usage: < 40 KB (of 128 KB)
- Real-time constraint: 64 ms frame window
- Processing latency: ~2.6 ms (measured on device)

---

## Confidentiality Notice

During the internship, sensor datasets and trained weights were classified. As a result:

Exposed in this repository:
- Feature extraction pipeline
- Deployment architecture
- Embedded DSP code
- Host visualization tooling
- Memory/timing analysis

Withheld:
- Raw datasets
- Model weights
- Validation metrics
- Sensor signatures
- Training infrastructure

---

## Applications

- Predictive maintenance
- Rotating machinery diagnostics
- UAV/munition vibration monitoring
- Servo health monitoring
- Industrial anomaly detection

---

## Future Work

See `docs/future_work.md` for extensions including multi-class taxonomy, CMSIS-NN optimization, adaptive thresholds, and cloud telemetry integration.

---

## Repository Structure

See `/docs` for architecture, DSP math, deployment notes, and confidentiality rationale.


