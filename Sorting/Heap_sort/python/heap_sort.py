def heap_maxify(array, parent, heap_size):
    l = parent * 2 + 1
    p = parent * 2 + 2
    largest = parent
    if l < heap_size and array[l] > array[largest]:
        largest = l
    if p < heap_size and array[p] > array[largest]:
        largest = p
    if largest != parent:
        temp = array[parent]
        array[parent] = array[largest]
        array[largest] = temp
        heap_maxify(array, largest, heap_size)


def build_max_heap(array):
    for i in range(len(array) // 2 - 1, -1, -1):
        heap_maxify(array, i, len(array))


def heap_sort(array):
    build_max_heap(array)
    for heap_size in range(len(array) - 1, 0, -1):
        temp = array[0]
        array[0] = array[heap_size]
        array[heap_size] = temp
        heap_maxify(array, 0, heap_size)


array=[13.0, -3.0, -25.0, 20.0, -3.0, -16.0, -23.0, 18.0, 20.0, -7.0, 12.0, -5.0, -22.0, 15.0, -4.0, 7.0]
print(array)
heap_sort(array)
print(array)