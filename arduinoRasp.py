#!/usr/bin/env python3
import serial

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
ser.reset_input_buffer()

while True:
    command = input("Use 'w', 'a', 's', ou 'd' para mover: ")
    
    if command == 'd':
        print("Movendo para a direita")
        ser.write(command.encode('utf-8'))
    elif command == 'a':
        print("Movendo para a esquerda")
        ser.write(command.encode('utf-8'))
    elif command == 'w':
        print("Movendo para cima")
        ser.write(command.encode('utf-8'))
    elif command == 's':
        print("Movendo para baixo")
        ser.write(command.encode('utf-8'))
    else:
        print("Comando inválido")
