from collections import deque
import sys


while True:
    q1 = deque([])
    q = deque(list(sys.stdin.readline()[:-1]))
    if len(q) == 1 and q[0] == ".":
        break
    flag = 0
    while q:
        now = q.popleft()
        if now == "(":
            q1.append("(")
        elif now == ")":
            if len(q1) == 0:
                flag = 1
                break
            now1 = q1.pop()
            if now1 != "(":
                flag = 1
                break
        elif now == "[":
            q1.append("[")
        elif now == "]":
            if len(q1) == 0:
                flag = 1
                break
            now1 = q1.pop()
            if now1 != "[":
                flag = 1
                break
    if flag != 1 and len(q1) == 0: 
        print("yes")
    else:
        print("no")
        