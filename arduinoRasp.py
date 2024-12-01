#!/usr/bin/env python3
import serial
import random

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
ser.reset_input_buffer()

while True:
	blink = input()
	if blink == 'd':
		print("movendo para a direita")
		ser.write(str(blink).encode('utf-8'))
	elif blink == 'a':
		print("movendo para a esquerda")
		ser.write(str(blink).encode('utf-8'))
  elif blink == 'w':
		print("movendo para cima")
		ser.write(str(blink).encode('utf-8'))
  elif blink == 's':
		print("movendo para baixo")
		ser.write(str(blink).encode('utf-8'))
