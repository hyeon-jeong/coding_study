def solution(expression):
    answer = 0
    ans = []
    k = ['-', '*', '+']
    ex_m = []
    
    for i in range(len(expression)) :
        if expression[i] in k :
            ex_m.append(expression[i])
            ex_m = list(set(ex_m))
        

    if ex_m == 1 :
        ans.append(abs(eval(expression)))
    else :
        for i in range(len(ex_m)) :
            expression_2 = list(map(str, expression.split(ex_m[i])))
            ex_m2 = list(ex_m)
            del ex_m2[i]
        
            if len(ex_m2) == 1 :
                cal = str(eval(expression_2[0]))
                for j in range(1, len(expression_2)) :
                    cal = cal + ex_m[i] + str(eval(expression_2[j]))
                ans.append(abs(eval(cal)))
            else :
                for j in range(len(ex_m2)) :
                    expression_3 = []
                    for k in range(len(expression_2)) :
                        expression_3.append(expression_2[k].split(ex_m2[j]))
                
                    for k in range(len(expression_3)) :
                        if len(expression_3[k]) > 1 :
                            cal = str(eval(expression_3[k][0]))
                            for l in range(1, len(expression_3[k])) :
                                cal = cal + ex_m2[j] + str(eval(expression_3[k][l]))
                            expression_3[k] = [str(eval(cal))]
                    cal = str(eval(expression_3[0][0]))
                    for k in range(1, len(expression_3)) :
                        cal = cal + ex_m[i] + str(eval(expression_3[k][0]))
                    ans.append(abs(eval(cal)))
    answer = max(ans)
    return answer
