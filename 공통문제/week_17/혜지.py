from collections import deque

def solution(n, path, order):
    answer = False
    q = deque()
    visit = [0]*n
    visit[0] = 1
    w_vis= [0]*n
    # 다음 지점 방문이 가능한지 체크
    w_vis[0] = 1
    order_1 = {}
    order_2 = {}
    matrix = [[] for _ in range(n)]
    
    for a in order :
        order_1[a[0]] = a[1]
        # 해당 지점에 갔을 때 다음 순서가 존재하는지 확인
        order_2[a[1]] = a[0]
        # 해당 지점에 갔을 때 이전 순서가 있었는지 확인
        
    for a in path :
        matrix[a[0]].append(a[1])
        matrix[a[1]].append(a[0])
    
    if order_2.get(0) is None :
        q.extend(matrix[0])
        
    while q :
        now = q.popleft()
        w_vis[now] = 1
        
        if order_2.get(now) is None :
            visit[now] = 1
            for i in matrix[now] :
                if visit[i] == 0 :
                    q.append(i)
            if order_1.get(now) is not None and w_vis[order_1[now]] :
                q.append(order_1[now])
        else :
            if visit[order_2.get(now)] == 1 :
                visit[now] = 1
                for i in matrix[now] :
                    if visit[i] == 0 :
                        q.append(i)
    
    if sum(visit) == n :
        answer = True
    # 전부 방문했을 경우에만 True로 변경
        
    return answer
