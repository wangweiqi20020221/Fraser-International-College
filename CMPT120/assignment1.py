"""
Copyright: Weiqi Wang, WANW7D1903
           Fraser International College
           Instructor: Koopa H.
"""

def decimalToBinary(n1):
    """
    This function takes a positive integer n > 0 as an argument and returns a string of integers where each character
    of the string is a binary digit, 0 or 1 obtained by the conversion of the integer argument n to binary.

    :param n1: Int().
    :return: Str().
    """
    str_return = ""
    while n1 > 1:
        # can't use += here
        str_return = str(n1 % 2) + str_return
        n1 = n1 // 2
    if n1 == 1:
        str_return = "1" + str_return
    return str_return


def binaryAddition(str1, str2):
    """
    This function takes two string arguments str1 and str2 representing two binary numbers and returns a string of
    integers whose characters are obtained by the addition of the two binary numbers in binary addition format.

    :param str1: Int().
    :param str2: Int().
    :return: Str().
    """
    def binary_addition(index, carry):
        if index == 0:
            if str1[index] == "0" and str2[index] == "0":
                if carry == "0":
                    return "0"
                else:
                    return "1"
            elif str1[index] == "1" and str2[index] == "0":
                if carry == "0":
                    return "1"
                else:
                    return "10"
            elif str1[index] == "0" and str2[index] == "1":
                if carry == "0":
                    return "1"
                else:
                    return "10"
            else:
                if carry == "0":
                    return "10"
                else:
                    return "11"
        if str1[index] == "0" and str2[index] == "0":
            if carry == "0":
                return binary_addition(index-1, "0") + "0"
            else:
                return binary_addition(index-1, "0") + "1"
        elif str1[index] == "1" and str2[index] == "0":
            if carry == "0":
                return binary_addition(index-1, "0") + "1"
            else:
                return binary_addition(index-1, "1") + "0"
        elif str1[index] == "0" and str2[index] == "1":
            if carry == "0":
                return binary_addition(index-1, "0") + "1"
            else:
                return binary_addition(index-1, "1") + "0"
        else:
            if carry == "0":
                return binary_addition(index-1, "1") + "0"
            else:
                return binary_addition(index-1, "1") + "1"

    str1 = str(str1)
    str2 = str(str2)
    # add 0 in front of the shorter string, so two strings have same digits
    if len(str1) < len(str2):
        str1 = "0" * (len(str2) - len(str1)) + str1
    else:
        str2 = "0" * (len(str1) - len(str2)) + str2
    return binary_addition(len(str1)-1, "0")


def binaryToDecimal(str3):
    """
    This function takes a string binStr representing a binary number and converts it to decimal and returns the
    decimal number.

    :param str3: Int() or Str().
    :return: Int().
    """
    str3 = str(str3)
    int_return = 0
    for index in range(len(str3)):
        int_return += int(str3[index])*(2**(len(str3)-index-1))
    return int_return


# Main Program
n1 = int(input("Enter n1: "))
n2 = int(input("Enter n2: "))
ans = n1 + n2
str1 = decimalToBinary(n1)
print("The binary representation of", n1, "is", str1)
str2 = decimalToBinary(n2)
print("The binary representation of", n2, "is", str2)
str3 = binaryAddition(str1, str2)
print("The binary addition of", n1, "and", n2, "is", str3)
n3 = binaryToDecimal(str3)
print("Converting the binary to decimal gives", n3)
if ans == n3:
    print("Since", ans, "==", n3, ", it seems we did good job.")
else:
    print("Since", ans, "!=", n3, ", something went wrong.")