def getData(fileName):
    f = open(fileName, "r")

    dates = []
    closePrices = []
    openPrices = []
    highest = []
    lowest = []

    f.readline()

    for line in f:
        firstComma = line[15:].find(',', 0) + len(line[:15])
        secondComma = line.find(',', firstComma+1)
        thirdComma = line.find(',', secondComma+1)

        dates.append(line[4:14])
        closePrices.append(line[15:firstComma])
        openPrices.append(line[firstComma+1:secondComma])
        highest.append(line[secondComma+1:thirdComma])
        lowest.append(line[thirdComma+1:-1])

    return dates, closePrices, openPrices, highest, lowest