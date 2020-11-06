from itertools import chain
# 2차원 배열을 1차원으로 만들기 위한 작업

def solution(n):
    ans = [[0 for _ in range(n)] for _ in range(n)]
    m = 1
    x = -1
    # for 문에서 +1을 하고 시작하기 때문에 초기화 값이 -1
    y = 0
    for i in range(n) :
        for j in range(i, n) :
            if i%3 == 0 :
                x = x+1
            elif i%3 == 1 :
                y = y+1
            else :
                x = x-1
                y = y-1
            ans[x][y] = m
            m = m+1
    answer = list(i for i in chain(*ans) if i != 0)
    # 0이 아닌 부분만 2차원 배열에서 1차원 배열으로 옮긴다.
    return answer
