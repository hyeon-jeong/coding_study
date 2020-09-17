'''N×M크기의 배열로 표현되는 미로가 있다.
1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 
이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 
한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.'''

'''첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 
다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 
각각의 수들은 붙어서 입력으로 주어진다.'''

'''첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 
항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.'''

from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
m = []
l = [[0 for _ in range(M)] for _ in range(N)]
                                          

for i in range(N) :
    m.append(input().rstrip())

for i in range(N) :
    for j in range(M) :
        l[i][j] = int(m[i][j])

def BFS(m, start) :
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    visit = [[0 for _ in range(M)] for _ in range(N)] 

    q = deque(start)
    answer = 1

    while q :
        x = q.popleft()
        y = q.popleft()

        visit[0][0] = 1

        if x == N-1 and y == M-1 :
            answer = visit[x][y]
            break
        
        for i in range(4) :
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx and nx < N and 0 <= ny and ny < M :
                if visit[nx][ny] == 0 and l[nx][ny] == 1 :
                    q.append(nx)
                    q.append(ny)
                    visit[nx][ny] = visit[x][y] +1
                    
    return answer

answer = BFS(m, (0,0))
print(answer)
