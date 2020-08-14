def solution(food_times, k):
    times = {} # 시간에 순서 매칭
    for i, time in enumerate(food_times):
        if time in times:
            times[time].append(i)
        else:
            times[time] = [i]
    l = len(food_times)
    
    threshold = 0 # 최소 몇바퀴 돌 수 있는지

    for time in sorted(times):
        if k - (time - threshold)*l >= 0:
            k -= (time - threshold)*l
            l -= len(times[time])
            threshold += (time - threshold)
        else:
            k = k % l
            for i in times:
                if i >= time:
                    idex = times[i][0]
                    break

            for i in range(idex, len(food_times)):
                if food_times[i] >= time:
                    if k == 0:
                        return i+1
                    k -= 1
    return -1