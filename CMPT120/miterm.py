def foo(a, b):
    """

    :param a: 函数内的局部变量a，不是函数外的全局变量a，所以函数只是交换了局部变量a的值，没有交换全局变量a的值
    :param b:
    :return:
    """
    temp = a
    a = b
    b = temp
    print(a, b)


a = 13
b = 6
foo(a, b)
print(a, b)

# 问最后print的东西是什么
for i in range(3, 8, 2):
    print(i, " ", )
    for j in range(3, 5, 1):
        print(j, " ", )
print()

alist1 = [1, 2, 3]
alist2 = alist1  # alist2只是指向了alist1的内存地址，alist1和alist2会同时改变
alist3 = alist1[:]  # alist3是在内存中创建的新列表，不会受alist1和alist2的影响
alist3[1] = -100  # [1, -100, 3]，alist1和alist2不随之改变
alist2[1] = -200  # [1. -200, 3]，alist1随着alist2改变
alist1[0] = -300  # [-300, -200. 3]，alist2随着alist1改变
print(alist1, alist2, alist3)  # [-300, -200. 3], [-300, -200. 3], [1, -100, 3]

s = "Hello World!"
print(s[4:] + s[:4])

s = "CMPT1202023"
# 3, 正着数是10，倒着数是-1
i = 0
print("-len是：", s[-len(s)])
j = len(s) - 1  # j是第11项-1也就是最后一项（因为首项是0不是1，所以需要减1）
while i < j:
    print(s[j], "---", s[i])
    i += 1
    j -= 1


# s[-1]是3，也就是最后一项
#    a  b  c  d  e
# 正：0  1  2  3  4
# 负：-5 -4 -3 -2 -1
# 正索引，首项是0；负索引，末项是-1


def foo(a, b):
    p = 0
    for i in range(b):
        p = p + a
        return p
        print("Output =", p)


n = foo(5, 5)
print("The magic number is", n)


# sumDigits(0) = 0
# sumDigits(5) = 5
# sumDigits(123) = 1 + 2 + 3 = 6
def sumDigits(num):
    """

    :param num: 数据类型为Int()
    :return:
    """
    sum_num = 0
    # "123"
    for i in str(num):
        # i是"1"或"2"或"3"
        # 但是sum_num是一个整数
        # 所以需要把i再转换成整数进行相加
        # 如果没有int会报错
        # TypeError: unsupported operand type(s) for +=: 'int' and 'str'
        # int可以和int相加，str可以和str相加，但是int不能和str相加
        sum_num += int(i)
    return sum_num


print(sumDigits(123))


# 字符串转数字
# toDigit("123") -> 123
# toDigit("000000123") -> 123
# 不让你使用int()，比如不可以使用int("1")
def toDigit(s):
    # 大思路：遍历这个字符串，把每一项都变成数字
    # 小思路1：数字 = 原来的数字 * 10 + 新的数字
    # 比如说123 == 12 * 10 + 3，12 == 1 * 10 + 2
    #
    # 小思路2：建立一个映射，把数字和其对应的字符串映射起来，比如0 -> "0"， 1 -> "1"， 2 -> "2"， 3 -> "3"
    # num_list的index和其对应的值就是这个映射关系
    # 比如num_list的第0项是"0"，第1项是“1”，其中这个index是整数

    # koopa的方法：ord(character) - ord(0)可以把数字对应的字符串转换成数字
    num_list = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
    # 也可以用字典
    num_dic = {"0": 0, "1": 1, "2": 2, "3": 3}
    # num_dic["0"]  得到数字0
    # 变量+中括号+key+另一个中括号  dic[key]  就可以得到value
    num = 0
    for character in s:
        # 用字典转换是num_dic[character]
        # num = num * 10 + num_dic[character]
        for index in range(len(num_list)):
            # 如果num_list的第index项和字符串的某一个字符是一样的，那这个index就是这个字符所对应的数字
            if num_list[index] == character:
                num = num * 10 + index
    return num


print(toDigit("123") + 0)

"""
给你一个字符串‘123=123’，如果等式成立的话就返回True，不成立的话返回False
           ‘123=125’ False
"""


def statement(s):
    # 首先用等号进行分隔
    # 但是不让用split()
    # 先找等号的index
    # 左边是0:等号-1 右边是等号+1:len(s)
    equation_index = 0
    for index in range(len(s)):
        if s[index] == "=":
            equation_index = index
    str_left = s[0:equation_index]
    str_right = s[equation_index+1:len(s)]
    # 分隔到了一个列表里，存储在了列表的第0项和第1项
    # 如果这两项相等的话就return True
    # 不等的话return False
    # ["123", "124"]
    if len(str_left) != len(str_right):
        # 如果两个字符串的长度不相等，直接reutrn False
        return False
    for index in range(len(str_left)):
        # index为0、1、2，意思是第0项、第1项、第2项
        # 循环比较两个字符串的同一项
        if str_left[index] != str_right[index]:
            return False
    return True


print(statement("123=123"))


def my_split(s):
    # 手写split函数，用空格分隔
    # s = "to be or      not to be "
    # lst = ["to", "be", "or", "not", "to",  "be"]
    lst = []
    temp_string = ""
    # 连续空格
    multi_space = False
    for element in s:
        # 可以试着用for i in range(len(s))对这个for循环进行重写
        if element == " ":
            if multi_space is True:
                # 如果element是空格并且multi_space为True的情况下，不执行对lst的append操作
                continue
            else:
                # 如果element是空格但multi_space为False
                lst.append(temp_string)
                temp_string = ""
                multi_space = True
        else:
            temp_string += element
            multi_space = False
    if not multi_space:
        # multi_space可以用于判断是否出现过空格，如果末尾没有空格的话multi_space为False，如果有的话multi_space为True
        lst.append(temp_string)
    return lst


print(my_split("to be or      not to be"))


# [3, 2, 5, 1, 4]
# [2, 3, 5, 1, 4]
# [1, 2, 5, 3, 4]
# 交换列表里两个元素的位置
# 这个交换，让列表成为有序的

# 二分查找（binary search）要求查询的数列是有序的
# [1, 3, 5, 6, 7]
# 2
