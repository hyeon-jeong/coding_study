import sys

input = sys.stdin.readline
a = []
answer = 0

for i in range(5) :
    a.append(int(input()))

for i in range(5) :
    if a[i] < 40 :
        answer = answer + 40
    else :
        answer = answer + a[i]

print(int(answer/5))
