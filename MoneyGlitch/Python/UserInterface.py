import ctypes
import main


def GetAction(): # TODO add currency changing
    price = main.GetData()

    if (main.returnedClassFromBotInC.Action == 0):
        print("Bought a BTC for: " + str(price))
    elif (main.returnedClassFromBotInC == 1):
        print("Sold a BTC for:" + str(price))
    else:
        print("Standing by")

def Import():
    price = main.GetData()
    main.lib.Import(ctypes.c_int(0), ctypes.c_float(price))