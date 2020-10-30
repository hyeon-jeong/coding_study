T = int(input())

for i in range(1, T+1) :
    MG = input()
    answer = 0
    ans = [[0 for _ in range(16)] for _ in range(len(MG))]

    for a in range(len(MG)) :
        mg = 1 << (ord(MG[a]) - 65)
        # A의 아스키 코드가 65이기 때문에 그냥 65를 빼주었다.

        for b in range(1, 16) :
            if a == 0 :
                if (b&mg)!=0 and (b&1)!=0 :
                    ans[a][b] = 1
            else :
                if ans[a-1][b] != 0 :
                    for c in range(1, 16) :
                        if (b&c)!=0 and c&mg!=0 :
                            ans[a][c] = (ans[a][c] + ans[a-1][b])%1000000007

    for k in range(1, 16) :
        answer = (answer + ans[len(MG)-1][k])%1000000007
        

    print("#%d %d" %(i, answer))
