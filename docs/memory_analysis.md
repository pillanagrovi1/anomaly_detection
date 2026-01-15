# Memory Analysis

Target MCU: STM32F446RE
- Flash: 512 KB
- SRAM: 128 KB
- Core: ARM Cortex-M4F

## 1. DSP Buffers

ADC buffer = 512 × 2 bytes = 1024 B
time buffer = 512 × 4 bytes = 2048 B
magnitude buffer = 256 × 4 bytes = 1024 B
feature buffer = 5 × 4 bytes = 20 B

Total DSP RAM ≈ 4.1 KB

## 2. Tensor Arena (TinyML)

Arena allocated: 20 KB (static)

## 3. Interpreter + Metadata

≈ 6–10 KB depending on ops included.

## 4. Overall

Total RAM usage ≈ 32–40 KB < 128 KB limit.

Project fits comfortably within device memory envelope without dynamic allocation.





