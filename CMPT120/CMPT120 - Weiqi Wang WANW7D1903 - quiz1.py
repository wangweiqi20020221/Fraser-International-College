"""
Copyright: Weiqi Wang, WANW7D1903
           Fraser International College
           Instructor: Koopa H.
           March, 9, 2023
"""


def makeLower(string):
    return_string = ""
    for character in string:
        if 64 < ord(character) < 91:
            return_string += chr(ord(character) + (97 - 65))
        else:
            return_string += character
    return return_string


def lastNameFirst(string):
    comma_final_index = 0
    for index in range(len(string)):
        if string[index] == ",":
            comma_final_index = index
    return string[comma_final_index + 1:] + "," + string[:comma_final_index]


if __name__ == '__main__':
    print(makeLower("Ab a cDe#?"))
    print(lastNameFirst("John,Doe"))
