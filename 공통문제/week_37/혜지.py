import sys
input = sys.stdin.readline

N = int(input())
answer = [0]*N
s = input()
S = [[0 for _ in range(N)] for _ in range(N)]
k = 0

for i in range(N):
    for j in range(i, N) :
        if s[k] == '+' :
            S[i][j] = 1
        elif s[k] == '-' :
            S[i][j] = -1
        k = k+1

def cul(x) :
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
