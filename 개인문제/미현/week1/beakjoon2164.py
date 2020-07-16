from collections import deque

n = int(input())

queue = [i+1 for i in range(n)]

queue = deque(queue)

flag = 0
while queue:
    val = queue.popleft()
    if flag == 0:
        flag += 1
    else:
        flag -= 1
        queue.append(val)

print(val)

