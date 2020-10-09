'''
인성이는 인싸가 되기 위해서 인싸트 특별과정에 참가했다. 
훈련 첫날 인성이는 험난한 미로에서 목적지에 도달해야 하는 훈련을 받고 있다. 
제한 시간 안에 미로를 통과하지 못하면 명기 교관 님에게 욕을 듣기에 인성이는 최선을 다해 미로를 통과하려고 한다.
미로는 가로 길이 W, 세로 길이 H의 격자 형태를 가지며, 인성이는 한 번에 격자 상의 상, 하, 좌, 우로 한칸 씩 움직일 수 있다.  
매 이동이 완료될 시에 인성이의 남은 힘은 1씩 감소하고, 남은 힘이 0이하인 경우에는 더 이상 움직이지 못하게 된다.
미로의 각 격자에는 장애물이 있는데, 각각의 장애물은 높이 정보를 가지고 있다. 
장애물이 없는 위치는 전부 높이가 0 이다. 
인성이가 이동할 때, 현재 위치보다 이동할 위치의 높이가 더 낮으면 아무런 제약을 갖지 않고 이동할 수 있다. 
더 높은 곳으로 이동할 때는 점프를 할 수 있는데, 점프해야 하는 높이는 (이동할 곳의 높이 - 현재 위치한 곳의 높이) 이다. 
이때 남아있는 힘이 점프해야 하는 높이보다 크거나 같으면 이동할 수 있고, 그렇지 않으면 이동하지 못한다.
인성이는 신체적 한계를 극복하고 무사히 목적지에 도달해서 명기 교관님의 욕설을 듣지 않을 수 있을까?
'''
'''
첫째 줄에 테스트 케이스 T가 주어진다. 각 테스트 케이스는 다음과 같이 주어진다.
첫째 줄에 미로의 세로길이 H, 가로길이 W, 장애물의 개수 O, 초기 힘 F, 출발지의 좌표 정보 Xs(행), Ys(열)목적지의 좌표정보 Xe(행), Ye(열) 가 주어진다.
둘째 줄부터 O개의 줄에 장애물의 좌표 정보 X(행), Y(열) 와 높이 정보 L이 주어진다. 모든 장애물은 서로 다른 위치에 존재한다.
'''
'''
T개의 줄에 인성이가 목적지에 도착할 수 있을 때 "잘했어!!", 목적지에 도착할 수 없을 때 "인성 문제있어??" 를 출력한다.
'''
'''
1 ≤ T ≤ 10
2 ≤ H, W ≤ 100
0 ≤ O ≤ H x W
0 ≤ F ≤ 10,000, F 는 정수이다.
1 ≤ L ≤ 50, L은 정수이다.
1 ≤ X, Xs, Xe ≤ H
1 ≤ Y, Ys, Ye ≤ W
시작 위치와 목적지에는 장애물이 존재하지 않는다.
'''

from collections import deque
import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T) :
    H, W, O, F, Xs, Ys, Xe, Ye = map(int, input().rstrip().split())
    m = [[0 for _ in range(W)] for _ in range(H)]
    for _ in range(O) :
        X, Y, L = map(int, input().rstrip().split())
        m[X-1][Y-1] = L
    
    def BFS(m, Xs, Ys, F, Xe, Ye) :
        dx = [1, 0, -1, 0]
        dy = [0, 1 , 0, -1]
        q = deque()
        q.append([Xs-1, Ys-1, F])
        visit = [[0 for _ in range(W)] for _ in range(H)]
        ans = False

        while q :
            x, y, f = q.popleft()
            visit[x][y] = 1

            if x == Xe-1 and y == Ye-1 :
                ans = True
                break
            
            if f == 0 :
                continue

            for i in range(4) :
                nx = x + dx[i]
                ny = y + dy[i]

                if 0 <= nx < H and 0 <= ny < W and visit[nx][ny] == 0 :
                    if f >= (m[nx][ny] - m[x][y]) :
                        visit[nx][ny] = 1
                        q.append([nx, ny, f-1])                        
        return ans

    if (BFS(m, Xs, Ys, F, Xe, Ye)) :
        print("잘했어!!")
    else :
        print("인성 문제있어??")
