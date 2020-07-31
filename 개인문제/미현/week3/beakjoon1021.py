import sys
from collections import deque

n, m = map(int, sys.stdin.readline()[:-1].split())
A = list(map(int, sys.stdin.readline()[:-1].split()))

q = deque([i for i in range(1, n+1)])
sol = 0

for i in range(len(A)):
    if q[0] == A[i]:
        q.popleft()
    else:
        j = 0
        while q[j] != A[i]:
            j = j + 1
        if j > len(q)-j:
            for k in range(len(q)-j):
                a = q.pop()
                q.appendleft(a)
                sol = sol + 1
            q.popleft()
            
        else:
            for k in range(j):
                a = q.popleft()
                q.append(a)
                sol = sol + 1
            q.popleft()

print(sol)