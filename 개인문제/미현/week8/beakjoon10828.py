from collections import deque
import sys

def cmd(stack, command):
    if command == 'size':
        print(len(stack))
    elif command == 'empty':
        if len(stack) == 0:
            print(1)
        else:
            print(0)
    elif command == 'pop':
        if len(stack) == 0:
            print(-1)
        else:
            print(stack.pop())
    elif command == 'top':
        if len(stack) == 0:
            print(-1)
        else:
            print(stack[-1])
    else:
        _, n = command.split()
        stack.append(int(n)) 


n = int(sys.stdin.readline()[:-1])
stack = deque([])
for i in range(n):
    cmd(stack, sys.stdin.readline()[:-1])