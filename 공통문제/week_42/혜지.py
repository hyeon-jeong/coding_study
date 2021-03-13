def solution(play_time, adv_time, logs):
    answer = ''
    adv_se = []
    ans = [0]*len(logs)
    def second(time) :
        sec = int(time[:2])*3600 + int(time[3:5])*60 + int(time[6:8])
        return sec
    
    def second_str(second) :
        s = second%60
        second //= 60
        m = second%60
        second //= 60
        second
        h = second
        return '{:02d}:{:02d}:{:02d}'.format(h, m, s)
    
    play_sec = second(play_time)
    adv_sec = second(adv_time)
    cum_played = [0 for _ in range(360001)]
    
    for log in logs :
        a, b = map(str, log.split('-'))
        cum_played[second(a)] = cum_played[second(a)] + 1
        cum_played[second(b)] = cum_played[second(b)] - 1
    
    
    for i in range(1, play_sec+1) :
        cum_played[i] = cum_played[i] + cum_played[i-1]
    for i  in range(1, play_sec+1) :
        cum_played[i] = cum_played[i] +cum_played[i-1]
    
    max_sum_time = 0
    max_sum_played = cum_played[adv_sec]
    
    for start_time in range(1, play_sec) :
        end_time = start_time + adv_sec if start_time + adv_sec < play_sec else play_sec
        sum_played = cum_played[end_time] - cum_played[start_time]
        if max_sum_played < sum_played :
            max_sum_played = sum_played
            max_sum_time = start_time +1
    print(second_str(max_sum_time))
    return second_str(max_sum_time)
