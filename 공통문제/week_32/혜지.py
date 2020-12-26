import sys
import heapq

input = sys.stdin.readline
inf = sys.maxsize

N, P, K = map(int, input().split())
graph = [[] for _ in range(N+1)]
heap = []
   
def Dijkstra(mid) :
    dp = [inf for _ in range(N+1)]
    dp[1] = 0
    heapq.heappush(heap, [0, 1])

    while heap :
        cost, now = heapq.heappop(heap)

        if dp[now] < cost :
            continue
        
        for next_node, c in graph[now] :
            if c > mid :
                next_cost = cost+1
            else :
                next_cost = cost

            if next_cost < dp[next_node] :
                dp[next_node] = next_cost
                heapq.heappush(heap, [next_cost, next_node])

    return dp[N] <= K
            
for _ in range(P) :
    u, v, w = map(int, input().split())
    graph[u].append([v, w])
    graph[v].append([u, w])

answer = -1
m = 0
M = 1000000

while (m <= M) :
    mid = (m+M)//2
    if Dijkstra(mid) :
        answer = mid
        M = mid - 1
    else :
        m = mid + 1

print(answer)
