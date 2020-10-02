n = int(input())

print_num = 0

for i in range(1, n+1):
    div = list(map(int, str(i)))
    sum = i + sum(div)
    if(sum == N):
        print_num = i
        break

print(print_num)
