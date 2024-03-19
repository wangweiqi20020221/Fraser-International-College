import random
# create the map, the map is a list to save the position of all stars in x-y coordinate
map = list()
for i in range(5):
    map.append(list())
    for j in range(5):
        map[i].append(list())

x = 0
y = 0
# create stars in the map, save their coordinates
map[x][y] = "*"
while x < 4 or y < 4:
    choice = random.choice(["right", "down"])
    if choice == "right" and x < 4:
        x += 1
    elif choice == "down" and y < 4:
        y += 1
    # The rest of elif can be omitted, because when go right is no sense, then the program will choose again until the
    # down appear
    elif x == 4:
        y += 1
    elif y == 4:
        x += 1
    map[x][y] = "*"

# print the map
for i in map:
    for j in i:
        if not j:
            print(" ", end="")
        else:
            print(j, end="")
    print("")
