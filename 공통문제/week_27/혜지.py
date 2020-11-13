import sys
sys.setrecursionlimit(10**5)
# 파이썬에서 재귀함수를 사용할 때 깊이 지정 안해주면 백준에서는 런타임에러가 난다...

input = sys.stdin.readline

N, Q = map(int, input().split())
n = 2**N
dir_x = [-1, 0, 1, 0]  
dir_y = [0, 1, 0, -1]

M = [list(map(int, input().split())) for _ in range(n)]

for a in list(map(int, input().split())) :
    k = 2**a
    for x in range(0, n, k) :
        for y in range(0, n, k) :
            temp = [M[i][y : y+k] for i in range(x, x+k)]
            # 원래 배열의 가로를 임시 배열에 저장한다.
            for i in range(k) :
                for j in range(k) :
                    M[x+j][y+k-1-i] = temp[i][j]
                    # 시계 방향에 맞추어 원래 배열에 임시 배열에 저장된 값을 세로로 바꾸어 준다.

    count = [[0]*n for _ in range(n)]
    for x in range(n) :
        for y in range(n) :
            for d in range(4) :
                nx = x + dir_x[d]
                ny = y + dir_y[d]
                if 0 <= nx < n and 0 <= ny < n and M[nx][ny] != 0 :
                    count[x][y] = count[x][y]+1

    for i in range(n) :
        for j in range(n) :
            if M[i][j] > 0 and count[i][j] < 3 :
                M[i][j] = M[i][j]-1
    # 인접한 4칸 중에서 3칸 이상 얼음이 존재하지 않으면 얼음의 수를 하나 줄인다.
    # 모서리 부분은 필연적으로 하나씩 줄수 밖에 없다.

print(sum(sum(i) for i in M))

def dfs(x, y) :
    ice = 1
    M[x][y] = 0
    for d in range(4) :
        nx = x + dir_x[d]
        ny = y + dir_y[d]
            
        if 0 <= nx < n and 0 <= ny < n and M[nx][ny] != 0 :
            ice = ice+dfs(nx, ny)
    return ice
# 얼음의 덩어리를 찾아주는 부분이다. -> 풀기는 했지만 0인 구간이 없는데 어떻게 덩어리로 나누어지는지 잘 모르겠다.

big_ice = 0
for i in range(n) :
    for j in range(n) :
        if M[i][j] > 0 :
            big_ice = max(big_ice, dfs(i, j))
# 덩어리로 나누고 제일 큰 값을 찾아준다.

print(big_ice)
