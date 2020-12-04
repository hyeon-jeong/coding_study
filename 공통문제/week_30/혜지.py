#파이썬은 시간초과가 나서 pypy로 하였다.

import sys
from collections import deque

input = sys.stdin.readline
inf = sys.maxsize

N, Q = map(int, input().rstrip().split())

visit = [0]*N
M = [[] for _ in range(N)]

def BFS(start, k, M) :
    queue = deque()
    queue.append((start, inf))
    visit = [0]*N
    visit[start] = 1
    answer = 0

    while queue :
        now, m_usa = queue.popleft()
        
        for next_node, u in M[now] :
            if visit[next_node] == 1 :
                continue
            if m_usa > u :
                queue.append((next_node, u))
                if u >= k :
                    answer = answer+1
            else :
                queue.append((next_node, m_usa))
                if m_usa >= k :
                    answer = answer+1
            visit[next_node] = 1
    return answer

for _ in range(N-1) :
    p, q, r = map(int, input().rstrip().split())
    M[p-1].append((q-1, r))
    M[q-1].append((p-1, r))


for _ in range(Q) :
    k, v = map(int, input().rstrip().split())
    print(BFS(v-1, k, M))

#처음에 다이제스트로 풀었다가 예제에서는 잘 돌아갔는데 문제는 계속 틀렸다고 해서 BFS로 바꾸어 풀었다.
