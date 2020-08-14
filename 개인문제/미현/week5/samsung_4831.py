T = int(input())

def fun(K,N,M):
    A = list(map(int,input().split()))
    now = K
    result = 0
    while True:
        if now < N:
            if now in A:
                now += K
                result += 1
            else:
                for j in range(K-1):
                    now -= 1
                    if now in A:
                        now += K
                        result +=1
                        break
                    if j == K-2:
                        return 0
        else:
            break
    return result
t = [0]*T
for i in range(T):
    K, N, M = map(int,input().split())
    t[i] = fun(K, N, M)
for k in range(len(t)):
    print("#"+str(k+1)+" "+str(t[k]))