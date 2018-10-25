def quicksort(array, start, end):
    # print([start, end])
    if end - start > 1:
        # print(array[start:end])
        pivot = array[end - 1]
        # print("pivot "+str(pivot))
        pivot_index = start
        for i in range(start, end - 1):
            if array[i] < pivot:
                temp = array[pivot_index]
                array[pivot_index] = array[i]
                array[i] = temp
                pivot_index += 1
        array[end - 1] = array[pivot_index]
        array[pivot_index] = pivot
        # print(array[start:end])
        array[start:pivot_index] = quicksort(array, start, pivot_index)
        array[pivot_index + 1:end] = quicksort(array, pivot_index + 1, end)
    return array[start:end]


arr = [-5, 26, 6, -3, 5, 4]

print(arr)
quicksort(arr, 0, len(arr))
print(arr)
