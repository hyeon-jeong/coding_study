from collections import deque
import sys

stack = deque([])
for i in range(int(sys.stdin.readline()[:-1])):
    a = int(sys.stdin.readline()[:-1])
    if a == 0:
        stack.pop()
    else:
        stack.append(a)

print(sum(stack))
