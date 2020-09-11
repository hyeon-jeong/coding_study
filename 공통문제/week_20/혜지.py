from collections import deque
import sys

input = sys.stdin.readline

T = int(input())

for i in range(T) :
    N = int(input())
    num = deque(map(int, input().rstrip().split()))
    answer = 0
    M = 0

    while (len(num) != 0) :
        a = num.pop()
        if a > M :
            M = a
        else :
            answer = answer + (M - a)

    print(answer)
