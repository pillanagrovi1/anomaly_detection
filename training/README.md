# Training Pipeline

This directory contains the training pipeline for vibration-based anomaly detection.

## Model

A small MLP consumes a 5-D engineered feature vector:

[RMS, Spectral_Energy, Crest_Factor, Zero_Crossings, Dominant_Frequency]


## Output

Binary classification:

- `0` → normal
- `1` → anomaly

## Export

The export path is:

[PyTorch → ONNX → TFLite Micro]


Dataset, labels, evaluation metrics, and trained weights are withheld due to classified restrictions during a defense research internship in 2025.
