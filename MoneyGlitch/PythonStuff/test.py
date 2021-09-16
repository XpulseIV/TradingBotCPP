class dataStruct:
    dates = []
    closePrices = []
    openPrices = []
    highest = []
    lowest = []

def getData(fileName):
    f = open(fileName, "r")

    t = dataStruct()

    f.readline()

    for line in f:
        firstComma = line[15:].find(',', 0) + len(line[:15])
        secondComma = line.find(',', firstComma+1)
        thirdComma = line.find(',', secondComma+1)

        t.dates.append(line[4:14])
        t.closePrices.append(line[15:firstComma])
        t.openPrices.append(line[firstComma+1:secondComma])
        t.highest.append(line[secondComma+1:thirdComma])
        t.lowest.append(line[thirdComma+1:-1])

    f.close()

    return t