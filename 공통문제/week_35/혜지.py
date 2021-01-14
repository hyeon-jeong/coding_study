import sys
input = sys.stdin.readline

N = int(input())
M = int(input())
a = set(input().split())

answer = abs(100 - N)
# 초기 값을 단순히 +, -만 조작해서 얻을 수 있는 값으로 해준다.

for i in range(1000001) :
# 주어진 채널로 가는 최대치의 경우의 수의 채널
    check = True
    for j in str(i) :
        if j in a :
            check = False
            # 만약 해당 버튼이 누를 수 없는 버튼이라면 false
    if check :
        answer = min( answer, abs(N - i)+len(str(i)) )
        # 저장된 answer 값 or +,-로 이동하는 값+버튼 누르는 값 중에서 작은 것이 answer에 새롭게 저장

print(answer)
