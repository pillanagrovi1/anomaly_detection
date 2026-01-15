import serial

def capture(port="COM3", baud=115200):
    ser = serial.Serial(port, baud)
    print("[INFO] Connected. Listening...")
    while True:
        line = ser.readline().decode().strip()
        print(line)

if __name__ == "__main__":
    capture()
