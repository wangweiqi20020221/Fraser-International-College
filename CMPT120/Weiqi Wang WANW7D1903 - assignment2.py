import random


def createBoard(height, width, colorList):
    Board = []
    for i in range(height):
        Board.append([])
        for j in range(width):
            randomIndex = random.randint(0, len(colorList)-1)
            randomColor = colorList[randomIndex]
            Board[i].append(randomColor)
    return Board


def printBoard(Board, height, width):
    for i in range(height):
        for j in range(width):
            print(Board[i][j].ljust(12), end='')
        print()


def createPath(startRow, startColumn, height, width, pathLength):
    allowedDirection = ["forward", "backward", "upward", "downward"]
    pathList = []
    currentCellRow = startRow
    currentCellColumn = startColumn

    for k in range(pathLength):
        while (True):
            randomDirection = allowedDirection[random.randint(0, 3)]
            if randomDirection == "upward" and currentCellRow > 0:
                pathList.append(randomDirection)
                currentCellRow -= 1
                break
            elif randomDirection == "downward" and currentCellRow < height-1:
                pathList.append(randomDirection)
                currentCellRow += 1
                break
            elif randomDirection == "forward" and currentCellColumn < width-1:
                pathList.append(randomDirection)
                currentCellColumn += 1
                break
            elif randomDirection == "backward" and currentCellColumn > 0:
                pathList.append(randomDirection)
                currentCellColumn -= 1
                break
    return pathList


def sortColorList(colorList, colorRGB):
    #IMPLEMENT THIS FUNCTION.
    sortedColorList = [colorList[0]]
    for indexColorList in range(1, len(colorList)):
        for indexSortedColorList in range(len(sortedColorList)):
            if colorRGB[colorList[indexColorList]] < colorRGB[sortedColorList[indexSortedColorList]]:
                sortedColorList.insert(indexSortedColorList, colorList[indexColorList])
                break
        sortedColorList.append(colorList[indexColorList])
    return sortedColorList


def computeColorCost(colorList, colorName):
    #IMPLEMENT THIS FUNCTION.
    for i in range(len(colorList)):
        if colorList[i] == colorName:
            return i
    return -1


def computePathTotalCost(pathList, startRow, startColumn, Board, colorList):
    #IMPLEMENT THIS FUNCTION.
    totalCost = 0
    row = startRow
    column = startColumn
    for path in pathList:
        if path == "forward":
            column += 1
        elif path == "backward":
            column -= 1
        elif path == "upward":
            row -= 1
        elif path == "downward":
            row += 1
        totalCost += computeColorCost(colorList, Board[row][column])
    return totalCost

######################################################
####################Main Program######################
######################################################

# Create a list that contains color names as strings
colorList = ["Alizarin", "Apricot", "Azure", "Beige", "Black", "Blue", "Brown", "Burgundy", "Cyan", "Green", "Gray", "Lime", "Magenta", "Maroon", "Navy", "Olive", "Orchid", "Pink", "Purple", "Red", "Teal", "Violet", "White", "Yellow"]

# Dictionary: Write a Python program that reads the file color_RGBs.txt and
# and creates a dictionary named colorRGB with keys: the colors and values: the RGB values as a tuple 


colorRGB = {}
file = open("color_RGBs.txt", "r")
lines = file.readlines()
lines = lines[1:]
file.close()
for line in lines:
    line = line.split("\t")
    for lineIndex in range(len(line)):
        for index in range(len(line[lineIndex])):
            if line[lineIndex][index] == " ":
                line[lineIndex] = line[lineIndex][:index]
                break
    for element in line:
        if element == "":
            line.remove("")
    colorRGB[line[0]] = (int(line[1]), int(line[2]), int(line[3]))


# Set the Board size. That is set the height and width. The size can be as big as you want. Try 20x20 or 50x40 etc
boardHeight = int(input("Please enter the height of the board "))
boardWidth = int(input("Please enter the width of the board "))

# Create the Board. Each cell in the Board will be assigned a random color name from the list of colors.

Board = createBoard(boardHeight, boardWidth, colorList)

# Print the Board

print("\nBoard created is:")
printBoard(Board, boardHeight, boardWidth)
print("\n\n")

# Set the starting cell row index and column index
startRow = random.randint(0, boardHeight-1)
startColumn = random.randint(0, boardWidth - 1)

# Create the path to follow
pathLength = int(input("Enter the length of the path "))
pathList = createPath(startRow, startColumn, boardHeight, boardWidth, pathLength)

#Print path to see

print("\nPath created starting from cell[",startRow, "][", startColumn, "] is:")
print(pathList)
print('\n')
# Sort the colorList based on RGB value of each color in Lexicographical order (Dictionary Order)
colorList = sortColorList(colorList, colorRGB)

# Compute the total cost of the path.
# The cost is calculated as the sum of the cost of each cell along the path.
# The cost of a cell is the cost of the color in the cell.
# The cost of a color is the index of the color in the sorted colorlist containing colors.
# The total cost must include the costs of the start cell and the last cell along the path.

pathCost = computePathTotalCost(pathList, startRow, startColumn, Board, colorList)

# Print the total cost of the path
print("The cost of the path is ", pathCost)

# %%
