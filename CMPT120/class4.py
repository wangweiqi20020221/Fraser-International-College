"""
Copyright: Weiqi Wang, WANW7D1903
           Fraser International College
           Instructor: Koopa H.
"""
import random


class Map:
    __map = list()

    def __init__(self, columns, rows):
        """
        Create the map.
        :param Int(). rows: How many rows this map has.
        :param Int(). columns: How many columns this map has.
        :return: "The map has been successful created"
        """
        for column in range(columns):
            self.__map.append(list())
            for row in range(rows):
                self.__map[column].append(list())

    def set_cell(self, row, column, value):
        """
        Set a cell, also can use to change the cell or set a blank to delete the cell.
        :param row: Int(). The row coordinate.
        :param column: Int(). The column coordinate.
        :param value: The value of the cell.
        :return: None.
        """
        self.__map[column][row] = value
        return

    def print_map(self, placeholder=" "):
        """
        Print the map in format for read
        :param placeholder: You can change the placeholder instead of a blank. This would be easy for visualize.
        :return: None.
        """
        for column in self.__map:
            for row in column:
                if row:
                    print(row, "\t", end="")
                else:
                    print(placeholder, "\t", end="")
            print()
        return


def closest_prime_number(start):
    """
    Find the closest prime number to the start. If start is a prime number, then the program will return start itself.
    :param start: The start number
    :return: The closest prime number to the start number.
    """
    if start <= 2:
        return 2
    number = start
    while True:
        for i in range(2, number):
            if number % i == 0:
                break
            if i == number - 1:
                return number
        number += 1


def question1():
    """
    Write a Python program that generates a random integer number n1 in the range [50, 100] and
    another random integer number n2 in the range [200, 300], and finally prints all the prime numbers in
    the range [n1, n2].
    :return: None
    """
    n1 = random.randint(50, 100)
    n2 = random.randint(200, 300)
    while n1 <= n2:
        print(closest_prime_number(n1))
        n1 = closest_prime_number(n1) + 1


def question2():
    """
    Write a Python program that generates a random integer number n1 in the range [50, 100] and
    another random integer number n2 in the range [200, 300], and finally prints all the numbers in the
    range [n1, n2] that are NOT prime.
    :return: None
    """
    n1 = random.randint(50, 100)
    n2 = random.randint(200, 300)
    while n1 <= n2:
        for number in range(n1, closest_prime_number(n1)):
            print(number)
        n1 = closest_prime_number(n1) + 1


def question3():
    """
    Write a Python program that reads a user input integer value n, asserts n is positive, and finally prints the
    following multiplication table.
    :return: None.
    """
    n = int(input("a user input integer value n:"))
    map = Map(rows=n, columns=n)
    for y in range(n):
        for x in range(y, n):
            map.set_cell(row=x, column=y, value=(x+1)*(y+1))
    map.print_map()


def question4():
    """
    Write a Python program that reads a user input integer value n, asserts n is positive, and finally prints the
    following pattern that has n rows and n columns by using nested loops.
    :return: None.
    """
    n = int(input("a user input integer value n:"))
    map = Map(rows=n, columns=n)
    for y in range(n):
        for x in range(y+1):
            map.set_cell(row=n-1-x, column=y, value="*")
    map.print_map()


def question5():
    """
    Write a Python program that reads a user input integer value n, asserts n is positive, and finally prints the
    following pattern that has n rows and 2n-1 columns.
    :return: None.

      *
     ***
    *****
    """
    n = int(input("a user input integer value n:"))
    map = Map(rows=n+1, columns=2*n-1)
    middle_x = int((n+1)/2)
    for y in range(n):
        for x in range(middle_x-y, middle_x+y+1):
            print(x, y)
            map.set_cell(row=x, column=y, value="*")
    map.print_map()


question5()
# map = Map(rows=3, columns=3)
# map.set_cell(row=1, column=0, value="a")
# map.print_map(placeholder="-")
