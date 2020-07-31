import sys
from collections import deque

def command(q, cmd):
    if cmd == "pop_front":
        if len(q) == 0:
            print(-1)
        else:
            print(q.popleft())
    elif cmd == "pop_back":
        if len(q) == 0:
            print(-1)
        else:
            print(q.pop())
    elif cmd == "size":
        print(len(q))
    elif cmd == "empty":
        if len(q) == 0:
            print(1)
        else:
            print(0)
    elif cmd == "front":
        if len(q) == 0:
            print(-1)
        else:
            print(q[0])
    elif cmd == "back":
        if len(q) == 0:
            print(-1)
        else:
            print(q[-1])
    else:
        cmd1, cmd2 = cmd.split()
        if cmd1 == "push_front":
            q.appendleft(int(cmd2))
        else:
            q.append(int(cmd2))

q = deque([])

n = sys.stdin.readline()
n = int(n[:-1])

for i in range(n):
    cmd = sys.stdin.readline()[:-1]
    command(q, cmd)