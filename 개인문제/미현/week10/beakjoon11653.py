n = int(input())

now = 2

while True:
    if now**2 > n:
        break
    if n % now == 0:
        n = n//now
        print(now)
    else:
        now += 1
         
