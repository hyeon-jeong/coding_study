from heapq import heappop, heappush
import sys
input = sys.stdin.readline
inf = 100000000

def function(start) :
    heap = []
    heappush(heap, [0, start])
    dp = [inf for _ in range(n+1)]
    dp[start] = 0

    while heap :
        hs, hb = heappop(heap)
        for ha, ks in k[hb] :
            n_hs = hs + ks
            if dp[ha] > n_hs :
                dp[ha] = n_hs
                heappush(heap, [n_hs, ha])
    return dp

T = int(input())
for i in range(T) :
    n, d, c = map(int, input().rstrip().split())
    time = 0
    num = 0
    k = [[] for _ in range(n+1)]

    for j in range(d) :
        a, b, s = map(int, input().split())
        k[b].append([a, s])

    dp = function(c)
    for j in dp :
        if j != inf :
            if time < j :
                time = j
            num = num+1
    print("%d %d" %(num, time))
