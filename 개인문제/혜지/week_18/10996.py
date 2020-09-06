'''예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

첫째 줄부터 차례대로 별을 출력한다.'''

import sys

N = int(sys.stdin.readline())

if N == 1:
    print('*')

else :
    for i in range(2*N) :
        if i%2 == 0 :
            for j in range(N) :
                if j%2 == 0 :
                    print('*', end ='')
                else :
                    print(' ', end = '')
        else :
            for j in range(N) :
                if j%2 == 0 :
                    print(' ', end= '')
                else :
                    print('*', end= '')
        print()
