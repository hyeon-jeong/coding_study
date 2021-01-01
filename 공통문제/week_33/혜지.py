# 넘어가지를 않아엽.....어디가 틀린 건지 도와주세여ㅠㅠ
import sys
from collections import deque
input = sys.stdin.readline

N, K, R = map(int, input().split())
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
load = [[[]for _ in range(101)]for _ in range(101)]
cow = []
visit = [[0 for _ in range(101)] for _ in range(101)]


def bfs(x, y) :
    
    queue = deque()
    visit[x][y] = 1
    queue.append([x, y])

    while queue :
        x, y = map(int, queue.popleft())
    
        for i in range(4) :
            nx = x + dx[i]
            ny = y + dy[i]
            if 1 > nx or nx > N or 1 > ny or ny > N :
                continue
            if visit[nx][ny] == 0 and [nx, ny] not in load[x][y] and [x, y] not in load[nx][ny] :
                    visit[nx][ny] = 1
                    queue.append([nx, ny])

for _ in range(R) :
    r1, c1, r2, c2 = map(int, input().split())
    load[r1][c1].append([r2, c2])
    load[r2][c2].append([r1, c1])

for _ in range(K) :
    a, b = map(int, input().split())
    cow.append([a, b])

answer = 0 
for i in range(K) :
    bfs(cow[i][0], cow[i][1])
    for j in range(i+1, K) :
        if visit[cow[j][0]][cow[j][1]] != 1 :
            answer = answer +1

print(answer)
