T = int(input())

def search(Arr1, Arr2):
    Arr1 = sorted(Arr1)
    c = 0
    for i in range(len(Arr2)):
        start = 0
        end = len(Arr1)-1
        flag = 0
        while True:
            if end < start:
                break
            if len(Arr1)-1 >= (start+end)//2 >= 0:
                if Arr1[(start+end)//2] < Arr2[i]:
                    start = (start+end)//2 + 1
                    if flag == 1:
                        break
                    else:
                        flag = 1
                elif Arr1[(start+end)//2] > Arr2[i]:
                    end = (start+end)//2 - 1
                    if flag == 2:
                        break
                    else:
                        flag = 2
                else:
                    c += 1
                    break
    return c


for test_case in range(1, T + 1):
    n1, n2 = map(int, input().split())
    Arr1 = list(map(int, input().split()))
    Arr2 = list(map(int, input().split()))
    result = search(Arr1, Arr2)
    print("#{} {}".format(test_case, result))
            
            