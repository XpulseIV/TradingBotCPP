import ctypes
import os

text = "LOL"

path = os.getcwd() #Get Current Path

path = path[:len(path) - 18] + "x64\\Debug\\MoneyGlitch.dll" #Set Dll Path

test = ctypes.CDLL(path) #Load DLL

# making a char array
arr = ctypes.c_byte * len(text)
lst = []
for i in text:
    lst.append(i)

test.print.argtypes = (ctypes.POINTER(ctypes.c_byte), ctypes.c_int)
test.print(arr(*lst), len(text)) #Call DLL Function