def mergeSort(array):
    l = len(array)
    print(l)
    if l > 1:
        p = l // 2
        print(p)
        array1 = mergeSort(array[0:p])
        array2 = mergeSort(array[p:])
        array = merge(array1, array2)
    return array


def merge(a1, a2):
    print("Merging two arrays: ")
    print(a1)
    print(a2)
    a = [0] * (len(a1) + len(a2))
    i = 0
    k = 0
    while i <len(a1) or k < len(a2):
        if i == len(a1):
            a[i + k] = a2[k]
            k += 1
            continue
        if k == len(a2):
            a[i + k] = a1[i]
            i += 1
            continue
        if a1[i] < a2[k]:
            a[i + k] = a1[i]
            i += 1
        else:
            a[i + k] = a2[k]
            k += 1
    print(a)
    return a


array = [0, 5, 2, 6, -1, 5, 7, 4]

print(mergeSort(array))
