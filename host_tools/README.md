# Host Tools

These scripts visualize and log the output of the embedded anomaly detection firmware.

## Output Format

The STM32 firmware emits messages of the form:

[ANOMALY:<0/1>]


## Tools

- `capture.py` — print raw messages
- `decode.py` — parse messages
- `plot_live.py` — live visualization
- `export_csv.py` — save logs for reports
