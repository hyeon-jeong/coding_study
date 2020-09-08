from collections import deque

T = int(input())

for t in range(1, T+1):
    n = int(input())
    Area = [[] for _ in range(n)]
    visited = [[0 for _ in range(n)] for _ in range(n)]
    q = deque([])
    q.append([0,0])
    for i in range(n):
        Area[i] = list(map(int, input().split()))
    visited[0][0] = Area[0][0]
    while q:
        x, y = q.popleft()
        x1, y1 = x+1, y
        x2, y2 = x, y+1
        if n > x1 >= 0 and n > y1 >= 0:
            if visited[x1][y1] == 0 or visited[x1][y1] >= visited[x][y] + Area[x1][y1]:
                visited[x1][y1] = visited[x][y] + Area[x1][y1]
                q.append([x1, y1])
        if n > x2 >= 0 and n > y2 >= 0:
            if visited[x2][y2] == 0 or visited[x2][y2] >= visited[x][y] + Area[x2][y2]:
                visited[x2][y2] = visited[x][y] + Area[x2][y2]
                q.append([x2, y2])
    print("#{} {}".format(t, visited[-1][-1]))


    
