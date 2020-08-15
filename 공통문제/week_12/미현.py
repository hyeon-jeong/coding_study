def solution(gems):
    item = {}
    gems_item = list(set(gems))
    gems_len = len(gems)
    gems_item_len = len(gems_item)
    
    if gems_len == 1:
        return [1, 1]

    if gems_len == gems_item_len:
        return [1, gems_len]

    for i in range(gems_item_len):
        item[gems_item[i]] = []

    for i in range(gems_len):
        item[gems[i]].append(i)
        
    sol = [-1 for _ in range(gems_len)]
    
    # 맨 앞에서 시작하는 sol 값 설정
    for i in range(gems_item_len):
        if sol[0] < item[gems_item[i]][0]:
            sol[0] = item[gems_item[i]][0]
    
    sol_start = 0
    size = sol[0] + 1

    for i in range(1, gems_len-gems_item_len+1):
        if size > sol[i-1]-i+2 > 1:
            sol_start = i-1
            size = sol[i-1]-i+2
        if sol[i-1]+1 == gems_len:
            break
        if sol[i-1] == -1:
            break
        for t in item[gems[i-1]]:
            if i <= t <= sol[i-1]:
                sol[i] = sol[i-1]
                break
            elif sol[i-1] < t:
                sol[i] = t
                break
    
    if size > sol[i]-i+1 > 1:
            sol_start = i

    return [sol_start+1, sol[sol_start]+1]