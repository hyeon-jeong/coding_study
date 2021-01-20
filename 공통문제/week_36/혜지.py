import sys
from math import gcd
input = sys.stdin.readline

def lcm(x, y) :
    return x*y // gcd(x, y)

if __name__ == '__main__' :
    T = int(input())
    for _ in range(T) :
        M, N, x, y = map(int, input().split())
        ch = False
        for i in range(x, lcm(M, N), M) :
            # 정답이 M으로 나누었을 때 x인 것을 이용하여 범위 선정
            if (i-y)%N == 0 :
                # 정답이 N으로 나누었을 때 y인 것을 이용
                ch = True
                answer = i
                break
        if ch == False :
            print(-1)
        else :
            print(answer)
