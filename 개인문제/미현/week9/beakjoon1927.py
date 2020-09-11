from queue import PriorityQueue
import sys

n = int(sys.stdin.readline()[:-1])
q = PriorityQueue()

for i in range(n):
    now = int(sys.stdin.readline()[:-1])
    if now == 0:
        if q.empty() == 0:
            print(q.get())
        else:
            print(0)
    else:
        q.put(now)
