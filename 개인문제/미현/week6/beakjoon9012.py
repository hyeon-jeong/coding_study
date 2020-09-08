from collections import deque

n = int(input())

for t in range(n):
    q = deque(list(input()))
    result = 0
    while q:
        now = q.popleft()
        if now == "(":
            result += 1
        else:
            result -= 1
        if result < 0:
            break
    if result == 0:
        print("YES")
    else:
        print("NO")


