import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T) :
    n = int(input())
    num = []
    answer = "YES"
    
    for _ in range(n) :
        num.append(input().rstrip())

    num.sort()

    for i in range(n-1) :
        if num[i] == num[i+1][:len(num[i])] :
            answer = "NO"

    print(answer)
