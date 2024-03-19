import random

# additional question
file = open("article.txt", "r")
content = file.read()
file.close()

l = []
counting = False
words = ""
for character in content:
    if character == "\"":
        if counting:
            l.append(words)
            counting = False
        else:
            counting = True
            words = ""
            continue
    if counting:
        words += character
print(l)
print(len(l))

# question 1
n = random.randint(50, 100)
content = ""
for i in range(n-1):
    content += str(random.randint(0, 999))
    content += "\n"
file = open("randomNumbers.txt", "w")
file.write(content)
file.close()

# question 2
file = open("randomNumbers.txt", "r")
content = file.readlines()
file.close()
for index in range(len(content)):
    content[index] = int(content[index])
print("Maximum:", max(content), "Minimum:", min(content))

# question 3
content_reverse = []
for index in range(len(content)-1, -1, -1):
    content_reverse.append(content[index])
print(content_reverse)

# question 4
content = ""
for element in content_reverse:
    content += str(element)
    content += "\n"
file = open("reversedRandomNumbers.txt", "w")
file.write(content)
file.close()

# question 6
file = open("ClassList.txt", "r")
content = file.readlines()
file.close()
l = []
for index in range(len(content)):
    l.append(content[index].split(" "))
    print(l)
    for j in range(2, len(l[index])):
        l[index][j] = int(l[index][j])
    if sum(l[index][1:]) >= 90:
        l[index].append("A")
    elif sum(l[index][1:]) >= 75:
        l[index].append("B")
    elif sum(l[index][1:]) >= 65:
        l[index].append("C")
    elif sum(l[index][1:]) >= 50:
        l[index].append("D")
    else:
        l[index].append("F")
content_write = ""
for i in content:
    for j in i:
        content_write += j
        content_write += "\t"
    content_write += "\n"
# file = open("ClassList.txt", "w")
# file.write(content_write)
# file.close()
