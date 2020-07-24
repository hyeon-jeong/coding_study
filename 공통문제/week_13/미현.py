from collections import deque

def move(x1, y1, x2, y2, direction, time, l1, l2, board):
    # direction == 0 : 위
    # direction == 1 : 아래
    # direction == 2 : 오른쪽
    # direction == 3 : 왼쪽
    if direction == 0:
        y1 += 1
        y2 += 1
    elif direction == 1:
        y1 -= 1
        y2 -= 1
    elif direction == 2:
        x1 += 1
        x2 += 1
    elif direction == 3:
        x1 -= 1
        x2 -= 1
    if x1 == l1 or x2 == l1 or y1 == l2 or y2 == l2:
        return -1, -1, -1, -1, -1
    if x1 < 0 or x2 < 0 or y1 < 0 or y2 < 0:
        return -1, -1, -1, -1, -1
    else:
        if board[y1][x1] == 1 or board[y2][x2] == 1:
            return -1, -1, -1, -1, -1
    return x1, y1, x2, y2, time+1

def rotate(x1, y1, x2, y2, direction, time, l1, l2, board):
    # direction == 0 : 아래 반시계
    # direction == 1 : 위 시계
    # direction == 2 : 아래 시계
    # direction == 3 : 위 반시계
    if direction == 0:
        if y1 == y2:
            x3, y3 = x1, y1+1 
            x1 += 1
            y1 += 1
        else:
            x3, y3 = x2+1, y2 
            x2 += 1
            y2 -= 1      
    elif direction == 1:
        if y1 == y2:
            x3, y3 = x1, y1-1 
            x1 += 1
            y1 -= 1
        else:
            x3, y3 = x1+1, y1 
            x1 += 1
            y1 += 1
    elif direction == 2:
        if y1 == y2:
            x3, y3 = x2, y2+1 
            x2 -= 1
            y2 += 1
        else:
            x3, y3 = x2-1, y2 
            x2 -= 1
            y2 -= 1
    elif direction == 3:
        if y1 == y2:
            x3, y3 = x2, y2-1 
            x2 -= 1
            y2 -= 1
        else:
            x3, y3 = x1-1, y1
            x1 -= 1
            y1 += 1

    if x1 >= l1 or x2 >= l1 or x3 >= l1 or y1 >= l2 or y2 >= l2 or y3 >= l2 :
        return -1, -1, -1, -1, -1
    if x1 < 0 or x2 < 0 or x3 < 0 or y1 < 0 or y2 < 0 or y3 < 0:
        return -1, -1, -1, -1, -1
    else:
        if board[y1][x1] == 1 or board[y2][x2] == 1 or board[y3][x3] == 1:
            return -1, -1, -1, -1, -1
    if x1 == x2:
        if y1 > y2:
            return x2, y2, x1, y1, time+1
        else:
            return x1, y1, x2, y2, time+1
    else:
        if x1 > x2:
            return x2, y2, x1, y1, time+1
        else:
            return x1, y1, x2, y2, time+1


def solution(board):
    l1 = len(board[0])
    l2 = len(board)
    x1, y1, x2, y2, time = 0, 0, 1, 0, 0
    visited = [[[-1, -1] for _ in range(l2)] for _ in range(l1)]
    visited[y1][x1][1] = 0
    q = deque([])
    q.append([x1, y1, x2, y2, time])
    while q:
        x1_, y1_, x2_, y2_, time_ = q.popleft()
        for i in range(4):
            x1, y1, x2, y2, time = move(x1_, y1_, x2_, y2_, i, time_, l1, l2, board)
            if time != -1:
                if x1 == x2: # 세로
                    if visited[y1][x1][0] == -1 or visited[y1][x1][0] > time:
                        q.append([x1, y1, x2, y2, time])
                        visited[y1][x1][0] = time
                else: # 가로
                    if visited[y1][x1][1] == -1 or visited[y1][x1][1] > time:
                        q.append([x1, y1, x2, y2, time])
                        visited[y1][x1][1] = time
        for i in range(4):
            x1, y1, x2, y2, time = rotate(x1_, y1_, x2_, y2_, i, time_, l1, l2, board)
            if time != -1:
                if x1 == x2: # 세로
                    if visited[y1][x1][0] == -1 or visited[y1][x1][0] > time:
                        q.append([x1, y1, x2, y2, time])
                        visited[y1][x1][0] = time
                else: # 가로
                    if visited[y1][x1][1] == -1 or visited[y1][x1][1] > time:
                        q.append([x1, y1, x2, y2, time])
                        visited[y1][x1][1] = time
    
    if visited[-2][-1][0] >= 0 and visited[-1][-2][1] >= 0:
        return min(visited[-2][-1][0], visited[-1][-2][1])
    elif visited[-2][-1][0] > 0:
        return visited[-2][-1][0]
    else:
        return visited[-1][-2][1]

