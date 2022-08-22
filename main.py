import re
import serial
import pyautogui
import time

if __name__ == "__main__":
    serialCom = serial.Serial("COM4", 9600)
    readSerial = ""
    while serialCom.isOpen():
        try:
            readSerial = str(serialCom.readline(), 'utf-8').rstrip("\r\n")
            #readSerial = serialCom.readline()
        except:
            break
            
        print("Serial> " + readSerial)
        if readSerial == "left":
            pyautogui.press('left')
            print("key pressed")
        elif readSerial == "right":
            pyautogui.press('right')
            print("key pressed")
