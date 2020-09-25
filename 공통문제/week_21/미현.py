n = int(input())
area = [[0, 0, 0] for i in range (n)]
# 0 : 끝나는 부분, 1: 시작, 2 : 이득
D = {}
for i in range(n):
    a1, a2 = map(int, input().split())
    if D.get(a1+i-1) is None:
        D[a1+i-1] = [[i, a2]]
    else:
        D[a1+i-1] = D.get(a1+i-1)+[[i, a2]] # 시작 지점, 이익


table = [0 for _ in range(n)]
# max 값, 마지막으로 가져온 곳
# DP로 풀기
if D.get(0) is not None: # 주의
    for A in D[0]:
        if A[1] > table[0]:
            table[0] = A[1] 

for i in range(1, n):
    max_i = table[i-1]
    if D.get(i) is not None:
        for A in D[i]:
            if max_i < A[1] + table[A[0]-1]:
                max_i = A[1] + table[A[0]-1]
    table[i] = max_i


print(table[-1]) 




