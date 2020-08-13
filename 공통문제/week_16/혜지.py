#무지의 먹방 라이브

from queue import PriorityQueue

def solution(food_times, k):
    answer = 0
    length = len(food_times)
    before = 0
    time = 0
    food = PriorityQueue()
    
    for i in range(len(food_times)) :
        food.put((food_times[i], i+1))

    if sum(food_times) < k :
        return -1
    
    while(time + ((food.queue[0][0] - before) * length) <= k) :
        a = food.get()[0]
        time = time + (a - before)*length
        length = length -1
        before = a
    food_f = sorted(food.queue, key = lambda x : x[1])
    
    answer = food_f[(k - time) % len(food.queue)][1]
    return answer
