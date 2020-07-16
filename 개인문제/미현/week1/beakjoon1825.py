import sys
from collections import deque

n = int(sys.stdin.readline())

q = deque([])

def func(command):    
    if command == 'pop':
        if len(q) == 0:
            print(-1)
        else:
            print(q.popleft())
    elif command == 'size':
        print(len(q))
    elif command == 'empty':
        if len(q) == 0:
            print(1)
        else:
            print(0)
    elif command == 'front':
        if len(q) == 0:
            print(-1)
        else:
            print(q[0])
    elif command == 'back':
        if len(q) == 0:
            print(-1)
        else:
            print(q[-1])
    else:
        c, num = command.split()
        q.append(int(num))


for i in range(n):
    cmd = sys.stdin.readline()
    func(cmd[:-1])

# memory : 92552KB
# time   : 2176ms

# input() -> sys.stdin.readline() : for time complexity