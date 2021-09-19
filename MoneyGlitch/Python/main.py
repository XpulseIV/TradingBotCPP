import ctypes
import os

text = "LOL"

print(os.path.isfile('f:/reps/TradingBotCPP/MoneyGlitch/Python/MoneyGlitch.dll'))
test = ctypes.CDLL('f:/reps/TradingBotCPP/x64/Debug/MoneyGlitch.dll')
test.print(ctypes.c_char_p(text), len(text))