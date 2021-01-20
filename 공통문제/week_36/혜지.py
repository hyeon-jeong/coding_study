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
            if (i-y)%N == 0 :
                ch = True
                answer = i
                break
        if ch == False :
            print(-1)
        else :
            print(answer)
