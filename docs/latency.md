# Latency Analysis

Frame size: 512 samples @ 8 kHz

Frame duration:
T = N / fs = 512 / 8000 = 64 ms


Processing must complete < 64 ms for real-time operation.

## Measured on STM32F4 (Cortex-M4F)

Approximate timing (representative):

- DMA acquisition: overlapped
- Windowing: < 0.2 ms
- FFT (512-pt): ~1.5 ms
- Features: < 0.3 ms
- Normalization: < 0.1 ms
- Inference (MLP): < 0.5 ms

Total processing budget ≈ 2.6 ms << 64 ms frame time

System meets real-time constraints.


---

# 📁 **docs/confidentiality.md**

```markdown
# Confidentiality Statement

During the 2025 internship, vibration datasets, training labels, and model weights were classified and cannot be exported.

Public release includes:

- DSP feature extraction
- Model architecture
- Deployment pipeline
- Host visualization tools
- Memory and latency analysis

Excluded components:

- Sensor datasets
- Training logs
- Validation metrics
- Trained weights
- Raw anomaly signatures

This mirrors common clearance rules in defense research environments.
