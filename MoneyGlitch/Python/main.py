import ctypes
import os

text = "LOL"

path = os.getcwd() #Get Current Path

path = path[:len(path) - 18] + "x64\\Debug\\MoneyGlitch.dll" #Set Dll Path

test = ctypes.CDLL(path) #Load DLL


test.print(ctypes.c_char_p(text), len(text)) #Call DLL Function