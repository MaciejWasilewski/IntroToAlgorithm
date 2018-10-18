def selectionSort(array):
    l = len(array)
    for i in range(0, l - 1):
        minIndex = i
        for j in range(i+1, l):
            if array[minIndex] > array[j]:
                minIndex = j
        temp = array[minIndex]
        array[minIndex] = array[i]
        array[i] = temp
    return array


table = [0, 2, 552, 63, 73, 722, 4, 2, 4, 7, 89, -1]
table = selectionSort(table)
print(table)
