"""
Copyright: Weiqi Wang, WANW7D1903
           Fraser International College
           Instructor: Koopa H.
           March 23, 2023
"""
def toDict(lst):
    # create the dictionary
    dict = {}
    for element in lst:
        dict[element] = ord(element)
    return dict


def dialer(string):
    dial_pad = {"A": 2, "B": 2, "C": 2,
                "D": 3, "E": 3, "F": 3,
                "G": 4, "H": 4, "I": 4,
                "J": 5, "K": 5, "L": 5,
                "M": 6, "N": 6, "O": 6,
                "P": 7, "Q": 7, "R": 7, "S": 7,
                "T": 8, "U": 8, "V": 8,
                "W": 9, "X": 9, "Y": 9, "Z": 9}
    str_return = ""
    for character in string:
        if character in dial_pad.keys():
            str_return += str(dial_pad[character])
        else:
            str_return += character
    return str_return


print(toDict(["a", "b", "c"]))
print(toDict(["?"]))
print(dialer("604-EXAMPLE"))
