def binarySearch(l, val):
    start_index = 0
    end_index = len(l) - 1
    while start_index <= end_index:
        mid = (start_index + end_index) // 2
        if val < l[mid]:
            end_index = mid - 1
        elif val > l[mid]:
            start_index = mid + 1
        else:
            return mid
    return -1


def bubbleSort(l):
    for i in range(len(l)-1):
        for j in range(len(l)-i-1):
            if l[j] > l[j+1]:
                temp = l[j]
                l[j] = l[j+1]
                l[j+1] = temp
    return l


print(binarySearch([2, 5, 6, 9, 21, 35, 44], 21))
print(bubbleSort([10, 5, 2, 6, 1, 3]))
