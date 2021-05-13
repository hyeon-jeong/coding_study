def solution(m, n, puddles):
    answer = 0
    M = [[0]*(m+1) for i in range(n+1)]
    M[1][1] = 1
    
    for i in range(1, n+1) :
        for j in range(1, m+1) :
            if i == 1 and j == 1 :
                continue
            if [j, i] in puddles :
                M[i][j] = 0
            else :
                M[i][j] = M[i-1][j] + M[i][j-1]      
    answer = M[n][m]%1000000007
    return answer
