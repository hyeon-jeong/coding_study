from collections import deque

def solution(new_id):
    answer = ''
    ans = deque()
    low_new_id = deque(new_id.lower())
    
    if len(low_new_id) == 0 :
        ans.append('a')
    
    for _ in range(len(new_id)) :
        if len(ans) == 15 :
            break
        a = ord(low_new_id.popleft())
        if a==46 :
            if len(ans) != 0 and ans[-1] != '.':
                ans.append(chr(a))
        elif 47<a<58 or 96<a<123 or a==45 or a==95 :
            ans.append(chr(a))
    
    while True :
        if len(ans) == 0 :
            ans.append('a')
        elif ans[-1] == '.' :
            ans.pop()
        elif len(ans) < 3 :
            ans.append(ans[-1])
        else :
            break
            
    answer = ''.join(ans)
    return answer
