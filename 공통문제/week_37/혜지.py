import sys
input = sys.stdin.readline

N = int(input())
answer = [0]*N
# 정답이 들어갈 배열
s = input()
S = [[0 for _ in range(N)] for _ in range(N)]
# 문제에서 원하는 수열로 변경해준다.
k = 0

for i in range(N):
    for j in range(i, N) :
        if s[k] == '+' :
            S[i][j] = 1
        elif s[k] == '-' :
            S[i][j] = -1
        k = k+1
# 문제에서 제시한 모양으로 행렬을 채워주는데, -는 -1로, +는 1로 변경한다.

def cul(x) :
# 규현이가 계산한 대로 계산하는 함수 
    a = 0
    for i in range(x, -1, -1) :
       a = a + answer[i]
       if S[i][x] < 0 :
           if a >= 0 :
               return False
       elif S[i][x] > 0 :
            if a <= 0 :
                return False
       elif S[i][x] == 0 :
            if a != 0 :
                return False
    return True
       

def choose(x) :
# answer에 들어갈 값을 정하는 함수
    if x == N :
        return True
    if S[x][x] == 0 :
        answer[x] = 0
        return cul(x) and choose(x+1)
    for i in range(1, 11) :
        answer[x] = i*S[x][x]
        if cul(x) and choose(x+1) :
            return True
    return False

choose(0)
print(' '.join(map(str, answer)))
