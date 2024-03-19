def solve(s):
    temp_i = 0
    num = 0
    nums = 0
    for i in range(len(s)):
        if s[i] == "+":
            temp_i = i + 1
            continue
        elif temp_i != 0 and s[i] == "=":
            num = int(s[temp_i:i])
            temp_i = i + 1
            continue
        elif num != 0:
            nums = int(s[temp_i:len(s)])
            return nums - num
            
def rotate(alist):
    return [alist[len(alist)-1]] + alist[0:len(alist)-1]

def formatInt(n):
    n = str(n)
    n_return = ""
    for i in range(len(n)-1, -1, -1):
        n_return = n[i] + n_return
        if (len(n) - i) % 3 == 0 and i != 0:
            n_return = "," + n_return
    return n_return

def isAlmostPalidrome(alist):
    difference = 0
    for i in range(len(alist)//2):
        if alist[i] != alist[len(alist)-1-i]:
            difference += 1
            if difference > 1:
                return False
    if difference == 1:
        return True
    else:
        return False

def freq(s):
    return_list = []
    for i in range(26):
        return_list.append(0)
    for character in s:
        if 96 < ord(character) < 123:
            return_list[ord(character)-97] += 1
        elif 64 < ord(character) < 91:
            return_list[ord(character)-65] += 1
            
    return return_list

print(solve("x+2=5"))
print(rotate([1, 2, 3, 4, 5]))
print(formatInt(1234))
print(isAlmostPalidrome([1, 3, 2, 2, 5, 1]))
print(isAlmostPalidrome([1, 2, 3, 4]))
print(isAlmostPalidrome([1, 2, 2, 1]))
print(freq("abac?ayyz"))
