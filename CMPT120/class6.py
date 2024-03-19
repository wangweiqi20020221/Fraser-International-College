"""
Copyright: Weiqi Wang, WANW7D1903
           Fraser International College
           Instructor: Koopa H.
"""


def findChar(char, char_finding):
    """
    Write a function named findChar that takes a string str, and a character and returns the index of the first
    occurrence of the character. If the character does not exist inside the string your function must return -1.

    :param char_finding: Str().
    :param char: Str().
    :return: Int().
    """
    for index in range(len(char)):
        if char[index] == char_finding:
            return index
    return -1


def isUpperCase(char):
    """
    Write a function named isUpperCase that takes a string argument and returns True if all the English letters in
    the argument string are upper case letters; otherwise it returns False. Example isUpperCase("CMPT 120") must
    return True but isUpperCase("Cmpt") must return False.

    :param char: Str().
    :return: Boolean().
    """
    for word in char:
        if 97 <= ord(word) <= 122:
            return False
    return True


def isUpperCaseOnly(char):
    """
    Write a function named isUpperCaseOnly that takes a string argument and returns True if all the characters of the
    string argument are upper case letters; otherwise it returns False. Example isUpperCaseOnly("CMPT 120") must
    return False but isUpperCaseOnly("HYTERCS") must return True.

    :param char: Str().
    :return: Boolean().
    """
    for word in char:
        if ord(word) < 41 or ord(word) > 90:
            return False
    return True


def isLowerCase(char):
    """
    Repeat questions 3 and 4 for lower case.

    :param char: Str().
    :return: Boolean().
    """
    for word in char:
        if 41 <= ord(word) <= 90:
            return False
    return True


def isLowerCaseOnly(char):
    """
    Repeat questions 3 and 4 for digit case.

    :param char: Str().
    :return: Boolean().
    """
    for word in char:
        if ord(word) < 97 or ord(word) > 122:
            return False
    return True


def containsDistinctCharacters(char):
    """
    Write a function named containsDistinctCharacters that takes a string argument and returns True if the string
    argument contains distinct (i.e. different) characters; otherwise it returns False. For example
    containsDistinctCharacters("Cmpt 120") must return True, containsDistinctCharacters("Marmon") must return True (
    remember m and different from M), but containsDistinctCharacters("Marsa") must return False.

    :param char: Str().
    :return: Boolean().
    """
    for i in range(len(char)):
        for j in range(i, len(char)):
            if ord(char[i]) == ord(char[j]):
                return False
    return True


def isContained(s1, s2):
    """
    Implement the function isContained function that takes two string arguments and returns True if and only if all
    the characters in string s2 are contained in string s1. You are not allowed to use any build in string function
    such as find or in operator.

    :param s1: Str().
    :param s2: Str().
    :return: Boolean().
    """
    # Make sure s1 is greater or equal than s2
    if len(s1) <= len(s2):
        s3 = s1
        s1 = s2
        s2 = s3
    for i in range(len(s1)-len(s2)):
        if s1[i:i+len(s2)] == s2:
            return True
    return False


def countCharacter(string, character):
    """
    Write a function named countCharacter that takes two arguments where the first argument is a string and the
    second argument is a character; so that the function counts the number of times the character appears in the
    string. Design a main program to test your function.

    :param string: Str().
    :param character: Str().
    :return: Int().
    """
    counter = 0
    for char in string:
        if char == character:
            counter += 1
    return counter


def isReverse(s1, s2):
    """
    Implement the function isReverse that takes two string arguments and returns True if the second string is the
    reverse of the first string. It returns false otherwise. Do not use any built-in function or method; instead,
    do it by looping through the characters of the strings

    :param s1: Str().
    :param s2: Str().
    :return: Boolean().
    """
    for i in range(len(s1)):
        if s2[len(s2)-1-i] != s1:
            return False
    return True


def doesContainLowerCase(string):
    """
    Write a function named doesContainLowerCase that takes one string argument and returns True if the argument
    contains at least one lower case English character; otherwise returns False. You may use the built-in islower
    string method.

    :param string: Str().
    :return: Boolean().
    """
    for char in string:
        if char.islower():
            return True
    return False


def doesContainLowerCaseAscII(string):
    """
    Re-implement the doesContainLowerCase function without using the islower method. You may use the built-in
    function ord that takes a character argument and returns its ascii value in your function. The ascii code of 'A'
    is 65 and the ascii code of 'a' is 97.

    :param string:
    :return: Boolean
    """
    for char in string:
        if 97 <= ord(char) <= 122:
            return True
    return False


def doesContainLowerCaseDoc(string):
    """
    Re-implement the doesContainLowerCase function without using the islower method and without using the ord
    built-in function. Instead, read the documentation of Python strings and find a constant that contains all
    lower-case English characters. Use this constant together with the IN operator to achieve your goal.

    :param string: Str().
    :return: Boolean().
    """
    for char in string:
        if char in string.ascii_lowercase:
            return True
    return False


def capitalizeEnglishChars(string):
    """
    Write a function named capitalizeEnglishChars that takes a string argument and returns a string constructed from
    the string argument such that all the lower-case English characters are capitalized.

    :param string: Str().
    :return: Str().
    """
    return string.upper()


def isPalindrome(string):
    """
    A string is called palindrome if it reads the same forward and backward. For example, the string "rotor" is a
    palindrome, the string "racecar" is a palindrome, but the string "cmpt" is not a palindrome. Implement a function
    named isPalindrome that takes one string argument and returns True if and only if the string is a palindrome; it
    returns False otherwise.

    :param string: Str().
    :return: Boolean().
    """
    for index in range(len(string)):
        if string[index] != string[-index-1]:
            return False
    return True


if __name__ == "__main__":
    print(countCharacter("zclvkjwoizcvhlwoeifixocvhbdskfjeiorhsbme", "c"))
