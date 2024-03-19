fin = open("randomnumber.txt", "r")
min_value = None
max_value = None
while True:
    try:
        num = int(fin.readline())
    except ValueError:
        break
    if min_value is None or num < min_value:
        min_value = num
    if max_value is None or num > max_value:
        max_value = num

print("Minimum value:", min_value)
print("Maximum value:", max_value)
fin.close()
