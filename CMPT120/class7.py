"""
Copyright: Weiqi Wang, WANW7D1903
           Fraser International College
           Instructor: Koopa H.
"""


def doubleList(l):
    """
    Implement the function named doubleList that takes a list argument and modifies the list so that each element in
    the list is doubled. The statement print(a) in the main program will then have to print [10,4,18,12,6]

    :param l: List().
    :return: List().
    """
    for index in range(len(l)):
        l[index] *= 2
    return l


def reversedList(l):
    """
    Implement the function named reversedList that takes a list argument and returns a list that contains the
    elements in the list argument in reverse order. The statement print(b) in the main program will then have to
    print [3,6,9,2,5]. The statement print(a) must print the original list [5,2,9,6,3] unaffected. This means your
    function should not modify the list argument.

    :param l: List().
    :return: List().
    """
    list_return = []
    for index in range(len(l), 0, -1):
        list_return.append(l[index])
    return list_return


def evenElements(l):
    """
    Implement the function named evenElements that takes a list argument and returns a list that contains the
    elements in the list argument that are even integers. The statement print(b) in the main program will then have
    to print [2,6]. Your function should not modify the list argument; that is the statement print(a) in the main
    program must print [5,2,9,6,3]

    :param l: List().
    :return: List().
    """
    list_return = []
    for element in l:
        if element % 2 == 0:
            list_return.append(element)
    return list_return


def removeOddElements(l):
    """
    Implement the function named removeOddElements that takes a list argument and modifies the list so that all odd
    integers in the list are removed. The statement print(a) in the main program will then have to print [2, 6, 4, 8,
    20]. You are not allowed to modify the main program. You can use either while loop or for loop for this problem.
    But using a while loop will be more interesting to learn more about looping.

    :param l: List().
    :return: List().
    """
    for element in l:
        if element % 2 == 1:
            l.remove(element)
    return l


def equal(l1, l2):
    """
    Write a function named equal that takes two list arguments and returns True if the two lists have the same length
    and elements of the two lists at the same indexes are equal; otherwise return False. For example the list [1, 2,
    4, 6] is equal to the list [1, 2, 4, 6]. But the list [1, 2, 4, 6] is not equal to [1, 2, 5, 6]. Write a main
    program to test your function.

    :param l1: List().
    :param l2: List().
    :return: List().
    """
    if l1 == l2:
        return True
    else:
        return False


def isPalindrome(l):
    """
    A given List is known as Palindrome List if the reverse of the List contains the same elements in the same order
    as the original List. For example the List of integers [2, 5, 0, 3, 3, 0, 5, 2] is a Palindrome because the
    reverse of the List which is [2, 5, 0, 3, 3, 0, 5, 2] contains the same elements in the same order as the given
    List. However, the List [1, 2, '2', 1] is not Palindrome because its reverse which is [1, '2', 2, 1] does not
    contain the same elements in the same order as the given List.

    Write a Python function named isPalindrome that takes a List as argument and returns True if the argument is a
    Palindrome List; otherwise it returns False. Write a test main program to test the correctness of your function.

    Is it possible to answer this question without having any loop in your function? Instead, making use of some of
    your functions from the questions above?

    :param l: List().
    :return: List().
    """
    if l == reversedList(l):
        return True
    else:
        return False


def readListElements():
    """
    Implement the function named readListElements that takes a list argument and modifies the list by repeatedly
    asking the user to enter integer values and then appending them to the list. The process stops when the user
    enters -1000. The stopping value -1000 should not be appended to the list. Moreover, your function must count the
    appended elements and return the count. For example, if the user enters the integers 31, -4, 9, 1,-1000 then your
    function must modify the list a to a = [31, -4, 9, 1] and return the number elements appended which is 4.

    :return: List().
    """
    l = []
    user_input = int(input("input a number:"))
    while user_input != -1000:
        l.append(user_input)
        user_input = int(input("input a number:"))
    return [l, len(l)+1]


def getFreqDistribution(str):
    """
    Most data compression algorithms like winzip, gzip, lzip and etc are based on the frequency distribution of
    characters in a given string. Write a function named getFreqDistribution that takes a string argument and returns
    a list that has length 26 such that the first element of the list is the number of times the characters 'a' or
    'A' are found in the string argument, the second element is number of times the characters 'b' or 'B' are found
    in the string argument, the third element is number of times the characters 'c' or 'C' are found in the string
    argument , and so on so forth.

    :param str: Str().
    :return: List().
    """
    # create the list
    list_return = []
    for i in range(26):
        list_return.append(0)
    for character in str:
        if ord(str) >= 97:
            # lower-case character
            list_return[ord(str) - 97] += 1
        else:
            # upper-case character
            list_return[ord(str) - 65] += 1
    return list_return


def isPrime(num):
    """
    If a number is prime, returns True; otherwise False.

    :param num: Int(), must greater than 1.
    :return: Boolean().
    """
    while num < 1:
        return "The number should be greater than 1."
    is_prime = True
    for i in range(2, num // 2):
        if num % i == 0:
            is_prime = False
    print("Is prime:", is_prime)


def removePrimesDel(l):
    """
    Write a function named removePrimes that takes a list argument and removes the prime number elements from the
    list. Use only the del built-in function to remove elements. Write also a test program to test your function.

    :param l: List().
    :return: List().
    """
    for index in range(len(l)):
        if isPrime(l[index]) is True:
            del l[index]
    return l


def removePrimesRemove(l):
    """
    Write a function named removePrimes that takes a list argument and removes the prime number elements from the
    list. Use only the remove method to remove elements. Write also a test program to test your function.

    :param l: List().
    :return: List().
    """
    for element in l:
        if isPrime(element) is True:
            l.remove(element)
    return l


def removePrimesRemovePopDefault(l):
    """
    Write a function named removePrimes that takes a list argument and removes the prime number elements from the
    list. Use only the pop() method to remove elements. Write also a test program to test your function.

    :param l: List().
    :return: List().
    """
    for index in range(len(l)):
        if isPrime(l[index]) is True:
            l[0:index].pop()
    return l


def removePrimesRemovePop(l):
    """
    Write a function named removePrimes that takes a list argument and removes the prime number elements from the
    list. Use only the pop(index) method to remove elements. Write also a test program to test your function.

    :param l: List().
    :return: List().
    """
    for index in range(len(l)):
        if isPrime(l[index]) is True:
            l.pop(index)
    return l


def removeDuplicates(l):
    """
    Write a function named removeDuplicates that takes a list argument and removes the duplicate elements from the
    list. Use only the del built-in function to remove elements. Write also a test program to test your function.

    :param l: List().
    :return: List().
    """
    index = 0
    while index < len(l)-1:
        if l[index+1] in l[0:index]:
            l.remove(l[index+1])
        index += 1
    return l


def removeDuplicatesDel(l):
    """
    Write a function named removeDuplicates that takes a list argument and removes the duplicate elements from the
    list. Use only the remove method to remove elements. Write also a test program to test your function.

    :param l: List().
    :return: List().
    """
    index = 0
    while index < len(l)-1:
        if l[index+1] in l[0:index]:
            del l[index+1]
        index += 1
    return l


def removeDuplicatesPopDefault(l):
    """
    Write a function named removeDuplicates that takes a list argument and removes the duplicate elements from the
    list. Use only the pop() method to remove elements. Write also a test program to test your function.

    :param l: List().
    :return: List().
    """
    index = 0
    while index < len(l)-1:
        if l[index+1] in l[0:index]:
            l[0:index+1].pop()
        index += 1
    return l


def removeDuplicatesPop(l):
    """
    Write a function named removeDuplicates that takes a list argument and removes the duplicate elements from the
    list. Use only the pop(index) method to remove elements. Write also a test program to test your function.

    :param l: List().
    :return: List().
    """
    index = 0
    while index < len(l)-1:
        if l[index+1] in l[0:index]:
            l.pop(index+1)
        index += 1
    return l


def countWords(string):
    new_sentence = False
    counter = 0
    for i in string:
        if new_sentence is False and (65 <= ord(i) <= 90 or 97 <= ord(i) <= 122):
            new_sentence = True
            counter += 1
        elif new_sentence is True and (ord(i) < 65 or 90 < ord(i) < 97 or ord(i) > 122):
            new_sentence = False
    return counter
