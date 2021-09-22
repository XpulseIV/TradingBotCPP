import requests
import ctypes
import multiprocessing
import UserInterface

if multiprocessing.cpu_count() == 16:
    path = "C:\\Users\\malte\\RiderProjects\\testStuff\\x64\\Debug\\MoneyGlitch.dll"
else:
    path = "F:\\Reps\\TradingBotCPP\\x64\\Debug\\MoneyGlitch.dll"

lib = ctypes.CDLL(path)

class Thought(ctypes.Structure):
    _fields_ = [("Currency", ctypes.c_int),
    ("Action", ctypes.c_int)
    ]

def GetData():
    response = requests.get('https://api.coindesk.com/v1/bpi/currentprice.json')
    data = response.json()
    currency_int = 0
    return data['bpi']['USD']['rate_float']


lib.BotEntryPoint(ctypes.c_int(0))

lib.GetThought.argtypes = (ctypes.c_int, ctypes.c_float)
lib.GetThought.restype = ctypes.c_void_p
lib.Import.argtypes = (ctypes.c_int, ctypes.c_float)


returnedClassFromBotInC = Thought.from_address(lib.GetThought(ctypes.c_int(0), ctypes.c_float(GetData)))

while not exit:
    user = str.lower(input("MoneyGlitch> "))

    if ("exit" in user):
        exit = True
        break
    elif ("action" in user):
        UserInterface.GetAction()
    elif ("set money " in user):
        lib.SetMoney(int(user[10:]))
    elif ("Import " in user):
        UserInterface.Import()