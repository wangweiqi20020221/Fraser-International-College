"""
Copyright: Weiqi Wang, WANW7D1903
           Fraser International College
           Instructor: Koopa H.
"""
import random


def question1():
    """
    Write a Python program that reads a positive integer user input value n and then reads n user input float values
    and finally prints both the minimum and maximum among the n user input float values.
    :return: None
    """
    num = int(input("How many numbers you want to enter:"))
    while num < 0:
        num = int(input("It should be positive. How many numbers you want to enter:"))
    maximum = None
    minimum = None
    for i in range(num):
        number = float(input("input a number:"))
        if maximum:
            if number > maximum:
                maximum = number
            elif number < minimum:
                minimum = number
        else:
            maximum = number
            minimum = number
    print("maximum:", maximum, "minimum", minimum)


def question2():
    """
    Repeat Q1 above but this time do not read user input value for n; instead assign n a random integer value in the
    range [5, 8]
    :return: None
    """
    # Return random integer in range [a, b], including both end points.
    num = random.randint(5, 8)
    maximum = None
    minimum = None
    for i in range(num):
        number = float(input("input a number:"))
        if maximum:
            if number > maximum:
                maximum = number
            elif number < minimum:
                minimum = number
        else:
            maximum = number
            minimum = number
    print("maximum:", maximum, "minimum", minimum)


def question3():
    """
    Write a program that reads in an integer n, reads n integer numbers from the user, and finally prints the sum of
    all even numbers, the average of all even numbers, the sum of all odd numbers, the average of all odd numbers,
    the sum of all the numbers, and the average of all numbers entered. Every negative integer number entry should be
    skipped and not used in any of the computations.
    :return: None
    """
    n = int(input("How many numbers do you want to enter:"))
    while n < 0:
        n = int(input("You should enter a positive number. Try again:"))
    even_number_sum = 0
    even_numbers = 0
    odd_number_sum = 0
    odd_numbers = 0
    for i in range(n):
        number = int(input("Input a number:"))
        while number < 0:
            number = int(input("The number should be positive. Try again:"))
        if number % 2 == 0:
            even_number_sum += number
            even_numbers += 1
        else:
            odd_number_sum += number
            odd_numbers += 1
    print("the sum of all even numbers:", even_number_sum)
    print("the average of all even numbers:", even_number_sum/even_numbers)
    print("the sum of all odd numbers:", odd_number_sum)
    print("the average of all odd numbers:", odd_number_sum/odd_numbers)
    print("the sum of all the numbers:", even_number_sum+odd_number_sum)
    print("the average of all numbers entered:", (even_number_sum+odd_number_sum)/n)


def question4():
    """
    Repeat Q3 above but this time assign n a random integer in the range [-5, 5] instead of reading user input value.
    :return: None
    """
    n = int(input("How many numbers do you want to enter:"))
    while n < 0:
        n = int(input("You should enter a positive number. Try again:"))
    even_number_sum = 0
    even_numbers = 0
    odd_number_sum = 0
    odd_numbers = 0
    for i in range(n):
        number = random.randint(-5, 5)
        if number % 2 == 0:
            even_number_sum += number
            even_numbers += 1
        else:
            odd_number_sum += number
            odd_numbers += 1
    print("the sum of all even numbers:", even_number_sum)
    print("the average of all even numbers:", even_number_sum / even_numbers)
    print("the sum of all odd numbers:", odd_number_sum)
    print("the average of all odd numbers:", odd_number_sum / odd_numbers)
    print("the sum of all the numbers:", even_number_sum + odd_number_sum)
    print("the average of all numbers entered:", (even_number_sum + odd_number_sum) / n)


def question5():
    """
    Write a program that reads in an integer n, reads n integers numbers from the user, and finally prints the
    minimum even integer, the maximum even integer, the minimum odd integer, and the maximum odd integer among the
    inputs. Every negative number entry should be skipped and not used in any of the computations.
    :return: None
    """
    n = int(input("How many numbers do you want to enter:"))
    while n < 0:
        n = int(input("You should enter a positive number. Try again:"))
    minimum_even_integer = 0
    maximum_even_integer = 0
    minimum_odd_integer = 0
    maximum_odd_integer = 0
    for i in range(n):
        num = int(input("Please input a Number:"))
        while num < 0:
            num = int(input("You should enter a positive number. Try again:"))
        if num % 2 == 0:
            if num < minimum_even_integer:
                minimum_even_integer = num
            elif num > maximum_even_integer:
                maximum_even_integer = num
        else:
            if num < minimum_odd_integer:
                minimum_odd_integer = num
            elif num > maximum_odd_integer:
                maximum_odd_integer = num
    print("minimum even integer", minimum_even_integer)
    print("maximum even integer", maximum_even_integer)
    print("minimum odd integer", minimum_odd_integer)
    print("maximum odd integer", maximum_odd_integer)


def question6():
    """
    Repeat Q5 above but this time assign n a random integer in the range [-5, 5] instead of reading user input value.
    :return: None
    """
    n = int(input("How many numbers do you want to enter:"))
    while n < 0:
        n = int(input("You should enter a positive number. Try again:"))
    minimum_even_integer = 0
    maximum_even_integer = 0
    minimum_odd_integer = 0
    maximum_odd_integer = 0
    for i in range(n):
        num = random.randint(-5, 5)
        if num % 2 == 0:
            if num < minimum_even_integer:
                minimum_even_integer = num
            elif num > maximum_even_integer:
                maximum_even_integer = num
        else:
            if num < minimum_odd_integer:
                minimum_odd_integer = num
            elif num > maximum_odd_integer:
                maximum_odd_integer = num
    print("minimum even integer", minimum_even_integer)
    print("maximum even integer", maximum_even_integer)
    print("minimum odd integer", minimum_odd_integer)
    print("maximum odd integer", maximum_odd_integer)


def question7():
    """
    Repeat Q5 above but this time generate n random integer values in the range [-10, 10] instead of reading user
    input values.
    :return: None.
    """
    n = int(input("How many numbers do you want to enter:"))
    while n < 0:
        n = int(input("You should enter a positive number. Try again:"))
    minimum_even_integer = 0
    maximum_even_integer = 0
    minimum_odd_integer = 0
    maximum_odd_integer = 0
    for i in range(n):
        num = random.randint(-10, 10)
        if num % 2 == 0:
            if num < minimum_even_integer:
                minimum_even_integer = num
            elif num > maximum_even_integer:
                maximum_even_integer = num
        else:
            if num < minimum_odd_integer:
                minimum_odd_integer = num
            elif num > maximum_odd_integer:
                maximum_odd_integer = num
    print("minimum even integer", minimum_even_integer)
    print("maximum even integer", maximum_even_integer)
    print("minimum odd integer", minimum_odd_integer)
    print("maximum odd integer", maximum_odd_integer)


def question8():
    """
    Repeat Q5 above but this time don't read any user input instead assign n a random integer in the range [-5,
    5] and generate random integer values in the range [-10, 10] n times.
    :return: None.
    """
    n = random.randint(-5, 5)
    while n < 0:
        n = random.randint(-5, 5)
    minimum_even_integer = 0
    maximum_even_integer = 0
    minimum_odd_integer = 0
    maximum_odd_integer = 0
    for i in range(n):
        num = random.randint(-10, 10)
        if num % 2 == 0:
            if num < minimum_even_integer:
                minimum_even_integer = num
            elif num > maximum_even_integer:
                maximum_even_integer = num
        else:
            if num < minimum_odd_integer:
                minimum_odd_integer = num
            elif num > maximum_odd_integer:
                maximum_odd_integer = num
    print("minimum even integer", minimum_even_integer)
    print("maximum even integer", maximum_even_integer)
    print("minimum odd integer", minimum_odd_integer)
    print("maximum odd integer", maximum_odd_integer)


def question9():
    """
    Write a Python program that asks user to enter a positive integer n and then prints the product of 1*2*3*4*...*n.
    Assume the user input n is positive.
    :return: None.
    """
    num = int(input("Input a positive number:"))
    number = 1
    for i in range(1, num+1):
        number *= i
    print(number)


def question10():
    """
    Write a Python program that that reads a positive integer value n from the user and then prints the following
    pattern using a while loop.
    * * * * *
    * * * * *
    * * * * *
    ...
    * * * * *
    There should be n lines of output with each line having five asterisks.
    :return: None
    """
    n = int(input("How many numbers do you want to enter:"))
    while n < 0:
        n = int(input("You should enter a positive number. Try again:"))
    i = 0
    while i < n:
        print("* * * * *")
        i += 1


def question11():
    """
    Write a Python program that reads a positive integer user input n, reads n user input integers, and finally
    prints the maximum in absolute value among all the n user input integers. For example, if n is 4 and the user
    input are 2, -3, 6, -4 then your program must print The maximum in absolute value is 6. For Page 2 example,
    if n is 5 and the numbers are 9, -3, -7, -23, -6 then your program must print the maximum in absolute value is
    -23.
    :return: None
    """
    n = int(input("How many numbers do you want to enter:"))
    while n < 0:
        n = int(input("You should enter a positive number. Try again:"))
    abs_max = 0
    for i in range(n):
        number = int(input("Input a number:"))
        if abs(number) > abs(abs_max):
            abs_max = number
    print(abs_max)


def question12():
    """
    Write a program that reads a positive integer number n and then prints the double data type value y given by ...
    :return: None.
    """
    num = int(input("How many numbers do you want to enter:"))
    while num < 0:
        num = int(input("You should enter a positive number. Try again:"))
    number = 0
    for i in range(num):
        if i % 2 == 1:
            number += 1 / i
        else:
            number -= 1 / i
    print(number)


def question13():
    """
    The Fibonacci numbers are given as 1, 1, 2, 3, 5, 8, 13, 21, ... That is the first number is 1, the second number
    is 1 and after that each number is the sum of the previous two numbers. Write a Python program that reads a user
    input integer value n, asserts n is positive, and finally prints the first n Fibonacci numbers.
    :return: None.
    """
    def fibonacci_numbers(num1, num2, counter):
        if counter == n:
            return num1+num2
        return fibonacci_numbers(num1=num2, num2=num1+num2, counter=counter+1)

    n = int(input("How many numbers do you want to enter:"))
    while n < 0:
        n = int(input("You should enter a positive number. Try again:"))
    print(fibonacci_numbers(num1=1, num2=1, counter=3))


def question14():
    """
    Write a Python program that asks the user to enter a positive integer n, asserts n is positive, reads n user
    input integers, and finally prints the message "The numbers you entered are in increasing order" if they are in
    increasing order or the message "The numbers you entered are NOT in increasing order" if they are not.
    :return: None
    """
    num = int(input("How many numbers do you want to enter:"))
    while num < 0:
        num = int(input("You should enter a positive number. Try again:"))
    in_order = True
    last_num = None
    for i in range(num):
        current_num = int(input("Please input number:"))
        if not last_num:
            last_num = current_num
        if current_num < last_num:
            in_order = False
        else:
            last_num = current_num
    if in_order:
        print("The numbers you entered are in increasing order")
    else:
        print("The numbers you entered are NOT in increasing order")


def question15():
    """
    Write a Python program to ask the user to enter a positive integer n and prints the product of the digits of n.
    :return: None
    """
    num = input("Enter a number:")
    while int(num) < 0:
        num = input("It should be positive. Try again:")
    product = 1
    for character in num:
        product *= int(character)
    print(product)


def question16():
    """
    Write a Python program that asks the user to enter a positive integer greater than 1 and checks whether a number
    is prime or not.
    :return: None.
    """
    num = int(input("Enter a number:"))
    while num < 1:
        num = int(input("It should be greater than 1. Try again:"))
    is_prime = True
    for i in range(2, num//2):
        if num % i == 0:
            is_prime = False
    print("Is prime:", is_prime)


def question17():
    """
    Write a Python program that prints sum of even numbers and sum of odd numbers between 10 and 40.
    :return: None.
    """
    sum_even = 0
    sum_odd = 0
    for num in range(10, 41):
        if num % 2 == 0:
            sum_even += num
        else:
            sum_odd += num
    print("sum even:", sum_even)
    print("sum odd:", sum_odd)


def question18():
    """
    Write a Python program that prints all the numbers that are divisible by 7 but not by 2 between 20 and 100.
    :return: None.
    """
    for num in range(20, 101):
        if num % 7 == 0 and num % 2 != 0:
            print(num)


def question19():
    """
    Write a Python program that reads a positive integer user input value n, then reads n user input float numbers,
    and finally prints the maximum value among all the user input values. Assume the user input value for n is positive
    :return: None
    """
    num = int(input("How many numbers do you want to input:"))
    while num < 0:
        num = int(input("It should be greater than 1. Try again:"))
    maximum = 0
    for i in range(num):
        number = float(input("input a number:"))
        if number > maximum:
            maximum = number
    print(maximum)


def question20():
    """
    Enter a positive number, this program would delete 1 inside this number.
    :return: None.
    """
    num = input("How many numbers you want to enter:")
    while int(num) < 0:
        num = input("It should be positive. How many numbers you want to enter:")
    output_num = 0
    for character in num:
        if character != "1":
            output_num = output_num * 10 + int(character)
    print(output_num)


if __name__ == "__main__":
    # The entrance is here
    pass
