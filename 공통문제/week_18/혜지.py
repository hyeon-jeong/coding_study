from collections import deque
import sys

def bfs(i, j) :
    visit = [[0]*N for i in range(N)]
    visit[i][j] = 1
    eat = []
    #아기 상어가 먹을 수 있는 물고기
    dist = [[0] * N for i in range(N)]
    #아기 상어의 위치와 물고기 사이의 거리
    q = deque()
    q.append([i, j])
    while q :
        x, y = q.popleft()
        for k in range(4) :
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx < N and 0 <= ny < N and visit[nx][ny] == 0 :
                if A[nx][ny] <= A[i][j] or A[nx][ny] == 0 :
                    q.append([nx, ny])
                    visit[nx][ny] = 1
                    dist[nx][ny] = dist[x][y]+1
                if A[nx][ny] < A[i][j] and A[nx][ny] != 0 :
                    eat.append([nx, ny, dist[nx][ny]])
    if not eat :
        return -1, -1, -1

    eat.sort(key = lambda x : (x[2], x[0], x[1]))
    #물고기를 거리 -> 위 -> 왼쪽 순으로 정렬
    return eat[0][0], eat[0][1], eat[0][2]
                    

N = int(sys.stdin.readline())
A = []
answer = 0
size = 0

for i in range(N) :
    a = list(map(int, sys.stdin.readline().split()))
    A.append(a)
    for j in range(N) :
        if a[j] == 9 :
            A[i][j] = 2
            #아기 상어의 처음 크기는 2
            start = [i, j]

dx = (1, 0, -1, 0)
dy = (0, 1, 0, -1)

while True :
    i = start[0]
    j = start[1]
    x, y, dist = bfs(i, j)
    if x == -1 :
    #더 이상 먹을 물고기가 없음
        break
    A[x][y] = A[i][j]
    A[i][j] = 0
    start = [x, y]
    size = size + 1
    if size == A[x][y] :
        size = 0
        A[x][y] = A[x][y] +1
    answer = answer+dist
print(answer)
