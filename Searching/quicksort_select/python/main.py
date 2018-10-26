def quicksort_select(array, start, end, item):
    if start > item or item  >= end:
        raise ValueError('You are looking for an item of index beyond the scope of the array!')
    if start == item:
        return array[start]
    else:
        pivot = array[end - 1]
        pivot_index = start
        for i in range(start, end - 1, 1):
            if array[i] < pivot:
                temp = array[i]
                array[i] = array[pivot_index]
                array[pivot_index] = temp
                pivot_index += 1
        array[end - 1] = array[pivot_index]
        array[pivot_index] = pivot
        if item == pivot_index:
            return array[pivot_index]
        if item < pivot_index:
            return quicksort_select(array, start, pivot_index, item)
        else:
            return quicksort_select(array, pivot_index + 1, end, item)


arr = [0, 7, 2, 7, 32, 6, 2, 68, 42, 5]

print(quicksort_select(arr, 0, len(arr), 0))
print(quicksort_select(arr, 0, len(arr), 2))
print(quicksort_select(arr, 0, len(arr), 4))