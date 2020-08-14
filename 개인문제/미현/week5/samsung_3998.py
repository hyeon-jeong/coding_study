T = int(input())

def mergesort(arr):
    l = len(arr)
    if l == 1:
        return arr, 0
    a, b = arr[:l//2], arr[l//2:]
    sorted_a, left_inversions = mergesort(a)
    sorted_b, right_inversions = mergesort(b)
    a_index, b_index = 0, 0
    total_inversions = left_inversions + right_inversions
    sorted_arr = [0 for i in range(l)]
    l_a, l_b = len(sorted_a), len(sorted_b)
    for i in range(l):
        if a_index == l_a: 
            sorted_arr[i:] = sorted_b[b_index:]
            return sorted_arr, total_inversions
        if b_index == l_b:
            sorted_arr[i:] = sorted_a[a_index:]
            return sorted_arr, total_inversions

        if sorted_a[a_index] > sorted_b[b_index]:
            sorted_arr[i] = sorted_b[b_index]
            b_index += 1
            total_inversions += (l_a-a_index)
        else:
            sorted_arr[i] = sorted_a[a_index]
            a_index += 1
    return sorted_arr, total_inversions

for testcase in range(1, T+1):
    n = int(input())
    A = list(map(int, input().split()))
    A, result = mergesort(A)
    print("#{} {}".format(testcase, result))