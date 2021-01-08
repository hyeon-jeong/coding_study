import sys
input = sys.stdin.readline

def candy() :
    mx, my = 1, 1

    for i in range(N) :
        x, y = 1, 1
        for j in range(N-1) :
            # 가로 캔디 체크
            if c[i][j] == c[i][j+1] :
                x = x+1
            else :
                if mx < x :
                    mx = x
                x = 1
            # 세로 캔디 체크
            if c[j][i] == c[j+1][i] :
                y = y+1
            else :
                if my < y :
                    my = y
                y = 1

        if mx < x :
            mx = x
        if my < y :
            my = y
    # 가로와 세로 중에 제일 큰 값을 return 하여 최종 먹을 수 있는 캔디 체크
    if mx < my :
        return my
    else :
        return mx

def change(x, y) :
    a = [y, x]
    return a

if __name__ == "__main__" :
    N = int(input())
    c = []
    answer = 0
    for _ in range(N) :
        c.append(list(input().rstrip()))

    for i in range(N) :
        for j in range(N-1) :
            # 가로 체인지
            c[i][j], c[i][j+1] = map(str, change(c[i][j], c[i][j+1]))
            if answer < candy() :
                answer = candy()
            # 바꾼 후 먹을 수 있는 캔디 체크
            c[i][j], c[i][j+1] = map(str, change(c[i][j], c[i][j+1]))
            # 다시 돌려 놓는다.
            
            # 세로 체인지
            c[j][i], c[j+1][i] = map(str, change(c[j][i], c[j+1][i]))
            if answer < candy() :
                answer = candy()
            c[j][i], c[j+1][i] = map(str, change(c[j][i], c[j+1][i]))
    print(answer)
