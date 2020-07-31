from collections import deque, defaultdict
import math

def find(x, parent) :
    if x == parent[x] :
        return x
    else :
        p = find_parent(parent[x], parent)
        parent[x] = p
        return p

def union(x, y, parent) :
    x = find(x)
    y = find(y)
    parent[y] = x
    
def bfs(land, start, visited, height, group) :
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    queue = deque(start)
    
    while queue :
        x = queue.popleft()
        y = queue.popleft()
        visited[x][y] = group
        
        for i in range(4) :
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < len(land) and 0 <= ny < len(land[0]) and visited[nx][ny] == 0 and abs(land[nx][ny] - land[x][y]) <= height :
                visited[ny][nx] = group
                queue.append((nx, ny))
                
def find_h(visited, height, maps, table) :
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    
    for x in range(len(maps)) :
        for y in range(len(maps[0])) :
            rx = x + 1
            dy = y + 1
            
            if rx < len(maps[0]) and visited[x][y] != visited[x][dy] :
                a, b = min(visited[x][y], visited[x][dy]), max(visited[x][y], visited[x][dy])
                table[(a, b)] = min(table[(a, b)], abs(maps[x][y] - maps[x][dy]))
            
            if rx < len(maps) and visited[rx][y] != visited[x][y] :
                a, b = min(visited[rx][y], visited[x][y]), max(visited[rx][y], visited[x][y])
                table[(a, b)] = min(table[(a, b)], abs(maps[rx][y] - maps[x][y]))
                
def solution(land, height):    
    visited = [[0 for _ in range(len(land[0]))] for _ in range(len(land))]
    group = 1
    
    for x in range(len(land)) :
        for y in range(len(land[0])) :
            if visited[x][y] == 0 :
                bfs(land, (x, y), visited, height, group)
                group = group + 1
    
    table = defaultdict(lambda : math.inf)
    find_h(visited, height, land, table)
    table = sorted(table.items(), key = lambda x : x[1])
    
    answer = 0
    nodes = {i: i for i in range(1, group)}
    for (a, b), value in table :
        if find(a, nodes) != find(b, nodes) :
            union(a, b, nodes)
            answer = answer + value
    
    if len(nodes.values()) == 1 :
        return answer
    return answer
