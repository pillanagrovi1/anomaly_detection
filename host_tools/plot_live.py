import serial
import matplotlib.pyplot as plt
from collections import deque
from decode import decode

def live_plot(port="COM3", baud=115200):
    ser = serial.Serial(port, baud)
    buf = deque(maxlen=200)

    plt.ion()
    fig, ax = plt.subplots()

    while True:
        line = ser.readline().decode().strip()
        val = decode(line)
        if val is not None:
            buf.append(val)
            ax.clear()
            ax.plot(list(buf))
            ax.set_ylim([-0.5, 1.5])
            ax.set_title("Real-Time Anomaly Detection")
            ax.set_ylabel("Anomaly")
            ax.set_xlabel("Time")
            plt.pause(0.01)

if __name__ == "__main__":
    live_plot()
