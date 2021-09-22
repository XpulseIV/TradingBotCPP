import requests
import ctypes
import multiprocessing

if multiprocessing.cpu_count() == 16:
    path = "C:\\Users\\malte\\RiderProjects\\testStuff\\x64\\Debug\\MoneyGlitch.dll"
else:
    path = "F:\\Reps\\TradingBotCPP\\x64\\Debug\\MoneyGlitch.dll"

lib = ctypes.CDLL(path)

class toBeReturned(ctypes.Structure):
    _fields_ = [("Currency", ctypes.c_int),
    ("Action", ctypes.c_int)
    ]

response = requests.get('https://api.coindesk.com/v1/bpi/currentprice.json')
data = response.json()
currency_int = 0
price = data['bpi']['USD']['rate_float']

lib.BotEntryPointPython.argtypes = (ctypes.c_int, ctypes.c_float)
lib.BotEntryPointPython.restype = ctypes.c_void_p

returnedClassFromBotInC = toBeReturned.from_address(lib.BotEntryPointPython(ctypes.c_int(0), ctypes.c_float(price)))

if (returnedClassFromBotInC.Action == 0):
    print("Bought a BTC for: " + str(price))
elif (returnedClassFromBotInC == 1):
    print("Sold a BTC for:" + str(price))
else:
    print("Did nothing")