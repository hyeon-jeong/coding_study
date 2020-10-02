import sys
from itertools import combinations

n, m = map(int, sys.stdin.readline()[:-1].split())
A = list(map(int, sys.stdin.readline()[:-1].split()))

combi = combinations(A, 3)
s = 0    
for c in combi:
    a1, a2, a3 = c
    s1 = a1+a2+a3
    if s < s1 <= m:
        s = s1
        if s == m:
            break

print(s)  

