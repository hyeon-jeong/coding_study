import sys

t = int(input())


def div_conq(c):
    max_index = 0
    max_cost = c[0]
    for i in range(len(c)):
        if c[i] >= max_cost:
            max_index = i
            max_cost = c[i]
    if max_index == len(c)-1:
        return (c[-1]*len(c)-sum(c))
    else:
        return (c[max_index]*(max_index)-sum(c[:max_index])) + div_conq(c[max_index+1:])

for _ in range(t):
    n = int(sys.stdin.readline()[:-1])
    cost = list(map(int, sys.stdin.readline()[:-1].split()))
    print(div_conq(cost)) 