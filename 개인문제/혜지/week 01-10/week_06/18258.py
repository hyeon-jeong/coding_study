'''정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 여섯 가지이다.
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.'''

'''첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 2,000,000)이 주어진다. 
둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 
문제에 나와있지 않은 명령이 주어지는 경우는 없다.'''

'''출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.'''

#자꾸 시간 초과나서 백준에서 통과했다는 알고리즘을 가지고 왔는데 여전히 시간 초과라서 포기..^^

import sys

N = int(sys.stdin.readline().rstrip())
answer = []
index = 0

for i in range(N) :
    a = list(map(str, sys.stdin.readline().split()))
    if a[0] == 'push' :
        answer.append(int(a[1]))
        
    elif a[0] == 'front' :
        if len(answer) > index :
            print(answer[index])
        else :
            print('-1')
            
    elif a[0] == 'back' :
        if len(answer) > index :
            print(answer[-1])
        else :
             print('-1')
            
    elif a[0] == 'size' :
        print(len(answer)-index)
        
    elif a[0] == 'empty' :
        if len(answer) == index :
            print('1')
            answer = []
            index = 0
        else :
            print('0')
            
    elif a[0] == 'pop' :
        if len(answer) > index :
            print(answer[index])
            index = index + 1
        else :
            print('-1')
