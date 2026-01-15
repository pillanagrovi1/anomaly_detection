import serial
import csv
from decode import decode

def export_csv(port="COM3", baud=115200, outfile="log.csv"):
    ser = serial.Serial(port, baud)
    with open(outfile, "w", newline="") as f:
        writer = csv.writer(f)
        writer.writerow(["index", "anomaly"])
        idx = 0
        while True:
            line = ser.readline().decode().strip()
            val = decode(line)
            if val is not None:
                writer.writerow([idx, val])
                idx += 1

if __name__ == "__main__":
    export_csv()
