from collections import deque

def func(num, A):
    q = deque(A)
    max_list = sorted(A)
    i = -1
    cnt = num+1
    while q:
        cnt -= 1
        a = q.popleft()
        if a == max_list[i]:
            if cnt == 0:
                return abs(i)
            i -= 1
        else:
            if cnt == 0:
                cnt = len(q) +1
            q.append(a)


T = int(input())

for _ in range(T):
    N, num = map(int, input().split())
    A = list(map(int, input().split()))
    sol = func(num, A)
    print(sol)
