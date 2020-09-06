'''예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

첫째 줄부터 2×N-1번째 줄까지 차례대로 별을 출력한다.'''

import sys

N = int(sys.stdin.readline())

for i in range(1, N+1) :
    k = i
    while k != 0:
        print('*', end='')
        k = k-1
    print()

for j in range(1, N) :
    k = j
    while k != N :
        print('*', end='')
        k = k+1
    print()
