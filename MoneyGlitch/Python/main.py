import ctypes
import os

class cstr (ctypes.Structure):
    _fields_ = [("str", ctypes.POINTER(ctypes.c_byte)), 
                ("length", ctypes.c_int)]


text = "LOL".encode('utf-8')

path = os.getcwd() #Get Current Path

path = path[:len(path) - 18] + "x64\\Debug\\MoneyGlitch.dll" #Set Dll Path

test = ctypes.CDLL(path) #Load DLL

# making a char array
arr = ctypes.c_byte * len(text)

str = cstr(arr(*text), len(text))

test.print.argtypes = (ctypes.POINTER(ctypes.c_byte), ctypes.c_int)
test.print(str.str, str.length) #Call DLL Function

test.cPrint.argtypes = (ctypes.POINTER(ctypes.c_byte), ctypes.c_int)
test.cPrint.restype = ctypes.c_void_p

l = cstr.from_address(test.cPrint(str.str, str.length))
print(l.length)

test.free_cstr(ctypes.byref(l))
del l