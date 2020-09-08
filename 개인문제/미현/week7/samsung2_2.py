import itertools

T = int(input())
for test_case in range(1, T + 1):
    n = int(input())
    cost_Arr = [ [] for _ in range(n) ]
    for i in range(n):
        cost_Arr[i] = list(map(int, input().split()))
    path = [i for i in range(1, n)] # n-1개, 0은 출발 지점
    path_list = itertools.permutations(path)
    min_cost = float("inf")
    for p in path_list:
        start_index = 0
        cost = 0
        for p1 in p:
            cost += cost_Arr[start_index][p1]
            start_index = p1
            if min_cost < cost:
                break
        if min_cost > cost + cost_Arr[start_index][0]:
            min_cost = cost + cost_Arr[start_index][0]
    print("#{} {}".format(test_case, min_cost))
            
            
            
            
	        
