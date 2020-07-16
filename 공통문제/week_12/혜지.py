def solution(gems):
    answer = [0, 0]
    length = []
    leng = len(gems)
    gems_s = list(set(gems))
    
    for i in range(len(gems)) :
        jw = []
        answer_s = []
        for j in range(i, len(gems)):
            if gems[j] in jw :
                continue
            else :
                jw.append(gems[j])
                answer_s.append(j+1)
        if len(jw) != len(gems_s) :
            continue
        length.append([answer_s[0], answer_s[-1], answer_s[-1]-answer_s[0]])
        
    for i in range(len(length)) :
        if length[i][2] < leng :
            leng = length[i][2]
            answer[0] = length[i][0]
            answer[1] = length[i][1]
    return answer
    
    #정확성은 다 맞았으나 모두 시간 초과로 효율성은 실패
