from collections import deque

def bfs(start, land, height, visited, color):
    vx = [1, -1, 0, 0]
    vy = [0, 0, 1, -1]
    l = len(land)
    q = deque([])
    q.append(start)
    visited[start[0]][start[1]] = color
    while q:
        now = q.popleft()
        h = land[now[0]][now[1]]
        for i in range(4):
            x, y = now[0]+vx[i], now[1]+vy[i]
            if 0 <= x < l and 0 <= y < l:
                if visited[x][y] == 0 and abs(h-land[x][y]) <= height:
                    visited[x][y] = color
                    q.append([x, y])
    return visited

def find_parent(D, a):
    if D[a] == a:
        return a
    else:
        p = find_parent(D, D[a])
        D[a] = p
        return p

def union(D, a, b):
    a1 = find_parent(D, a)
    b1 = find_parent(D, b)
    D[b1] = a1

def solution(land, height):
    l = len(land)
    visited = [[ 0 for _ in range(l)] for _ in range(l)]
    color = 0
    conn = {}
    for i in range(len(land)):
        for j in range(len(land)):
            if visited[i][j] == 0:
                color += 1
                visited = bfs([i, j], land, height, visited, color)
    for c1 in range(1, color+1): # 최적값 저장
        for c2 in range(1, c1):
            conn[(c1, c2)] = -1
    for i in range(l): 
        for j in range(l):
            if i < l-1: # 세로
                if visited[i][j] != visited[i+1][j]: # 경계
                    a, b = max(visited[i][j], visited[i+1][j]), min(visited[i][j], visited[i+1][j])
                    if conn[(a, b)] == -1 or abs(land[i][j]-land[i+1][j]) < conn[(a, b)]: # 처음 or 기존 높이 차보다 작음
                        conn[(a, b)] = abs(land[i][j]-land[i+1][j])
            if j < l-1: # 가로   
                if visited[i][j] != visited[i][j+1]: # 경계
                    a, b = max(visited[i][j], visited[i][j+1]), min(visited[i][j], visited[i][j+1])
                    if conn[(a, b)] == -1 or abs(land[i][j]-land[i][j+1]) < conn[(a, b)]: # 처음 or 기존 높이 차보다 작음
                        conn[(a, b)] = abs(land[i][j]-land[i][j+1])
  
    Ans = []
    check = {i : i for i in range(1, color+1)}
    for c1 in range(1, color+1): 
        for c2 in range(1, c1):
            if conn[(c1, c2)] != -1:
                Ans.append([conn[(c1, c2)], c1, c2])
    if color == 1:
        return 0
    A = sorted(Ans)
    answer = 0
    for item in A:
        a = find_parent(check, item[1])
        b = find_parent(check, item[2])
        if a != b:
            union(check, item[1], item[2])
            answer += item[0]
    return answer
            

# 시간초과 