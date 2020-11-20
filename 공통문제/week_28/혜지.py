def solution(words, queries):
    answer = []
    for i in range(len(queries)) :
        ans = 0
        b = []
        c = []
        for k in range(len(queries[i])) :
            if queries[i][k] != '?' :
                b.append(queries[i][k])
                c.append(k)
        que = queries[i][c[0]:c[-1]+1]
        for j in range(len(words)) :
            if len(words[j]) != len(queries[i]) :
                continue
            else :
                w = words[j][c[0]:c[-1]+1]
                if que == w :
                    ans = ans+1
        answer.append(ans)
    return answer
