def insertion_sort(array, reversed=False):
    length = len(array)
    for i in range(1, length, 1):
        temp = array[i]
        j = i - 1
        while j >= 0 and (array[j] < temp if reversed else array[j] > temp):
            array[j + 1] = array[j]
            j = j - 1
        array[j+1] = temp
    return array


a = list(range(10, 2, -1))
print(a)
a = insertion_sort(a)
print(a)
a = insertion_sort(a, reversed=True)
print(a)