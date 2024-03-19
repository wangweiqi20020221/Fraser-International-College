"""
先输入一个正整数n，再随机生成n个整数
"""
import random


def find_odds(l):
    """
    传入一个列表，返回所有的奇数，返回值应是一个列表
    :param l: List()，就是num_list
    :return: List()，odd_list
    """
    ods_list = []
    # element就是数列的每一项
    for element in l:
        if element % 2 == 1:
            # 奇数，追加到odd_list中
            ods_list.append(element)
    return ods_list


def find_evens(l):
    """
    传入一个列表，返回所有的偶数，返回值应是一个列表
    :param l: List()，就是num_list
    :return: List()，odd_list
    """
    ods_list = []
    # element就是数列的每一项
    for element in l:
        if element % 2 == 0:
            # 奇数，追加到odd_list中
            ods_list.append(element)
    return ods_list


def sum_list(l):
    """
    对数列求和
    :param l: List()
    :return: Float()或Int()
    """
    # 初始x
    x = 0
    for element in l:
        x += element
    return x


def average_list(l):
    """
    求数列的平均值，使用sum_list函数
    :param l: List()
    :return: List()
    """
    return sum_list(l)/len(l)


# 程序从这里运行
# 注意一下
# input()是字符串，其括号内的内容是提示性字符，如这里的"请输入n："，这个提示性字符会显示在命令行中
# int(input())的作用是把input的内容从字符串变为数字
# 等同于num = input("请输入n:")
#      num = int(num)
# 还写反的话就背下来
num = int(input("请输入n："))
# 新建一个list，用于存储所有的随机生成的整数
num_list = []
for i in range(num):
    # random.randint(0, 255)的作用是生成一个0到255之间的数
    # append()追加到列表中
    num_list.append(random.randint(0, 255))

# 用num充当计数器
# 建议再自己写一个counter的版本
while num > 0:
    num_list.append(random.randint(0, 255))
    num -= 1

print(num_list)
odds_list = find_odds(num_list)
print(odds_list)
print(sum_list(odds_list))
print(average_list(odds_list))

# 星星问题
# *
# **
# ***
# ****
# *****
for i in range(1, 6):
    # 字符串乘以数字的意思是循环打出字符串
    print("*"*i)

print("-----------------------------------")

#    *     -- 3个空格+1个*+3个空格
#   ***    -- 2个空格+3个*+2个空格
#  *****   -- 1个空格+5个*+1个空格
# *******  -- 0个空格+7个*+0个空格
#  *****   -- 下半部分通过if语句分开找关系
#   ***
#    *
for i in range(1, 5):
    # 4-i是i和每行空格数量的对应关系
    # i=1, 空格=3
    # i=2, 空格=2
    # i=3, 空格=1
    # i=4, 空格=0
    print(" "*(4-i), end="")
    # (i-1)*2+1)是i和每行*数量的对应关系
    # i=1, *=1
    # i=2, *=3
    # i=3, *=5
    # i=4, *=7
    print("*"*((i-1)*2+1))

# 可以把range()理解为生成一个数列
# 但是range是一个独立于列表或者元组的类（简单理解为数据类型）
# for循环的作用就是遍历列表（或元组、字典的key）
for i in range(1, 6):
    pass
# 两者的作用相等
for i in [1, 2, 3, 4, 5]:
    pass
