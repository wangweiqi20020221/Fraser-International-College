"""
Copyright: Weiqi Wang, WANW7D1903
           Fraser International College
           Instructor: Koopa H.
"""


def halfMulTable(n):
    for column in range(1, n+1):
        print(" \t"*(column-1), end="")
        for num in range(column, n+1):
            print(str(num*column)+"\t", end="")
        print()
    return


def rightHalfTriangle(n):
    for i in range(n):
        print(" \t"*(n-i), end="")
        print("*\t"*(i+1))
    return


def successiveSum(n):
    if n < 1:
        return "n should greater or equal than 1"
    num = 0
    for i in range(1, n+1):
        num += i
    return i


def successiveProduct(n):
    if n < 1:
        return "n should greater or equal than 1"
    num = 0
    for i in range(1, n+1):
        num *= i
    return i