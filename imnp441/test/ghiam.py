import serial
import wave
import struct

PORT = "COM3"   
BAUD = 115200
RATE = 16000      
CHANNELS = 1
WIDTH = 2           

ser = serial.Serial(PORT, BAUD, timeout=1)
wav = wave.open("output.wav", "wb")
wav.setnchannels(CHANNELS)
wav.setsampwidth(WIDTH)
wav.setframerate(RATE)

print(" dang ghji am")

try:
    while True:
        data = ser.read(1024)
        if data:
            wav.writeframes(data)
except KeyboardInterrupt:
    print("Dừng ghi âm.")
finally:
    wav.close()
    ser.close()
    print("lưu")