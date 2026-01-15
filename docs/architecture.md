# System Architecture

This project implements a TinyML-based anomaly detection pipeline for vibration signals on the STM32F446RE (ARM Cortex-M4F).

The architecture consists of five stages:

[Sensor → ADC DMA → DSP → TinyML → Host Tools]


## 1. Signal Acquisition

- Sampling Rate: 8 kHz
- Window Size: 512 samples
- Mode: DMA circular
- Double buffering via half/full transfer interrupts

This allows continuous real-time acquisition without blocking CPU.

## 2. DSP Feature Extraction

A 512-sample frame undergoes:

1. DC offset removal
2. Hanning window
3. FFT via CMSIS-DSP (arm_rfft_fast_f32)
4. Feature extraction (5-D)

Resulting feature vector:

[RMS, Spectral Energy, Crest Factor, Zero Crossing Rate, Dominant Frequency]


## 3. TinyML Inference

A TFLite Micro interpreter runs on MCU.

Model characteristics:

- Input: 5-D engineered feature vector
- Output: Binary classification
- Layers: MLP (5 → 16 → 8 → 2)

Weights are withheld due to confidentiality (2025 internship).

## 4. Host Interface

A UART interface streams classification results:

[ANOMALY:<0/1>]


## 5. Visualization Tools

Python tools parse logs, plot anomalies, and export CSV for analysis.


---

# 📁 **docs/dsp_math.md**

``` markdown
# DSP Mathematics

This appendix summarizes the signal processing used for feature extraction.

## 1. Hanning Window

Reduces spectral leakage prior to FFT:
w[n] = 0.5 * (1 - cos(2πn/(N-1)))


## 2. RMS

Measures signal power:
RMS = sqrt( (1/N) * Σ x[n]^2 )


## 3. Crest Factor

Ratio of peak amplitude to RMS:

CF = peak/RMS


Detects impulsive defects or impacts.

## 4. Zero Crossing Rate

Measures sign changes:
ZCR = (1/N) * Σ sign_change(x[n], x[n−1])


Useful for detecting mode transitions.

## 5. Spectral Energy

Computed from FFT magnitude:
E = Σ |X[k]|^2


## 6. Dominant Frequency

f0 = (fs * k_max) / N


Where `k_max` is index of maximum FFT bin.

These features are widely used in rotating machinery diagnostics and predictive maintenance.


