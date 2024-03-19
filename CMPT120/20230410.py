import random


# def monkey_jump(n):
#     if n == 1:
#         return 1
#     elif n == 2:
#         return 2
#     else:
#         return monkey_jump(n-1)+monkey_jump(n-2)
#
#
# print(monkey_jump(5))


def merge_ordered_list(list1, list2):
    """
    合并两个有序列表
    :param list1: List. 第一个列表
    :param list2: List. 第二个列表
    :return: List. 返回的列表
    """
    # 新建一个返回的空列表
    list_return = list()
    i = 0
    j = 0
    # 只有i和j同时小于它们对应的列表长度时循环才会结束
    # 换句话说，如果i等于len(list1)或者j等于len(list2)，两个条件中有一个成立时就会结束while循环
    while i < len(list1) and j < len(list2):
        if list1[i] <= list2[j]:
            list_return.append(list1[i])
            i += 1
        else:
            list_return.append(list2[j])
            j += 1
    # 如果i先到了list1的末尾，那么while循环就会结束，但是此时j并没有到达list2的末尾，需要把list2没有加进来的数追加到列表的末尾
    # 两个列表用+进行合并
    list_return += list1[i:]
    list_return += list2[j:]
    return list_return


def merge_sort(lst):
    if len(lst) == 1:
        # 如果列表只剩下一个元素，那么开始return
        return lst
    else:
        # 如果列表还有多个元素，那么继续拆分
        # 这里的left_list是一个列表，而不是index，而Yonas用的是index没有拆分成列表
        left_list = lst[0:len(lst) // 2]
        # 注意是左闭右开，所以len(lst)//2并没有包含在left_list里面
        right_list = lst[len(lst) // 2:len(lst)]
        # 对左右两个列表进行合并
        return merge_ordered_list(merge_sort(left_list), merge_sort(right_list))


def quick_sort(lst):
    """
    快速排序
    :param lst: List. 待排序的列表。
    :return: List. 排序好的列表。
    """
    # 边界条件，lst只有一项
    if len(lst) <= 1:
        return lst
    print("此时的列表是：", lst)
    # 在列表里随机挑选一个索引
    random_index = random.randint(0, len(lst) - 1)
    # 对列表的两个数进行交换位置
    lst[0], lst[random_index] = lst[random_index], lst[0]
    random_number = lst[0]
    print("随机数是：", random_number, "交换完位置的列表是", lst)
    # 遍历lst，如果数比随机数小或者相等放在left_list，大则放在right_list
    left_list = list()
    right_list = list()
    for num in lst[1:]:
        if num <= random_number:
            left_list.append(num)
        else:
            right_list.append(num)
    print("left_list:", left_list, "right_list:", right_list)
    return quick_sort(left_list) + [random_number] + quick_sort(right_list)


def quick_sort2(lst):
    """
    快速排序
    :param lst: List. 待排序的列表。
    :return: List. 排序好的列表。
    """
    # 边界条件，lst只有一项
    if len(lst) <= 1:
        return lst
    print("此时的列表是：", lst)
    # 在列表里随机挑选一个索引
    random_index = random.randint(0, len(lst) - 1)
    # 对列表的两个数进行交换位置
    lst[0], lst[random_index] = lst[random_index], lst[0]
    random_number = lst[0]
    print("随机数是：", random_number, "交换完位置的列表是", lst)
    i = 1
    # counter是有几个数比随机数要大
    end = len(lst)
    while i < end:
        if lst[i] > random_number:
            # 把lst[i]追加到列表的末尾
            lst.append(lst[i])
            # 删除原来第i项的数
            lst = lst[:i] + lst[i+1:]
            end -= 1
            print(lst)
        else:
            i += 1
    # 随机数(列表的第0项)和i-1交换顺序
    lst[0], lst[i-1] = lst[i-1], lst[0]
    return quick_sort2(lst[:i-1]) + [random_number] + quick_sort2(lst[i:])


# print(merge_ordered_list([1, 5, 9, 23], [-5, 0, 8, 11]))
# print(merge_sort([5, 11, 1, -5, 23, 0, 9, 8]))
print(quick_sort2([5, 11, 1, -5, 23, 0, 9, 8]))
