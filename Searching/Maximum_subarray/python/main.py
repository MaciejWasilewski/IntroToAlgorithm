# array[start, start+1, ..., stop] - stop inclusively!
def find_maximal_subarray(array, start, stop):
    length = stop - start + 1
    # print(length)
    if length == 1:
        return (start, stop, array[start])
    else:
        mid = length // 2 + start
        # print(mid)
        temp = [find_maximal_subarray(array, start, mid-1),
                find_maximal_subarray(array, mid, stop), find_maximal_mid(array, start, stop, mid)]
        sums = [item[2] for item in temp]
        print("array:")
        print(array[start:stop+1])
        print("maximal left array:")
        print(array[temp[0][0]:temp[0][1]+1])
        print("maximal right array:")
        print(array[temp[1][0]:temp[1][1] + 1])
        print("maximal interior array:")
        print(array[temp[2][0]:temp[2][1] + 1])
        print("maximal subarray:")
        print(array[temp[sums.index(max(sums))][0]:temp[sums.index(max(sums))][1] + 1])
        print("*"*20)
        return temp[sums.index(max(sums))]


def find_maximal_mid(array, start, stop, mid):
    print(start, stop, mid)
    if (mid - 1) - start + 1 == 1:
        start2=start
    else:
        sumof = array[mid - 1]
        sum_max = sumof
        start2=mid-1
        print(list(range(mid - 2, start - 1, -1)))
        for i in range(mid - 2, start - 1, -1):
            sumof += array[i]
            print((sumof,sum_max))
            if sumof > sum_max:
                sum_max = sumof
                start2 = i
    if stop - mid + 1 == 1:
        stop2=stop
    else:
        sumof = array[mid]
        sum_max = sumof
        stop2=mid
        for i in range(mid + 1, stop + 1, 1):
            sumof += array[i]
            if sumof > sum_max:
                sum_max = sumof
                stop2 = i

    return start2, stop2, sum(array[start2:stop2+1])


array = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
print(find_maximal_subarray(array,0,15))