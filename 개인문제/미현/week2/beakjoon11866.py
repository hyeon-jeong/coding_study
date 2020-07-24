from collections import deque

N, K = map(int, input().split())


q = deque([])
sol = []

for i in range(1, N+1):
    q.append(i)

cnt = 0
while q:
    a = q.popleft()
    cnt += 1
    if cnt == K:
        sol.append(a)
        cnt = 0
    else:
        q.append(a)

print("<", end="")
for i in range(len(sol)-1):
    print(str(sol[i])+", ", end="")

print(str(sol[-1])+">")