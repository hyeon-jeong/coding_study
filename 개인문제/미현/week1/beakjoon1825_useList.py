import sys
n = int(sys.stdin.readline())

queue = [-1 for _ in range(n+1)]

start_index = 0
end_index = 0

def func(command, start_index, end_index):    
    if command == 'pop':
        if start_index - end_index == 0:
            print(-1)
        else:
            print(queue[start_index])
            start_index += 1
    elif command == 'size':
        print(end_index - start_index)
    elif command == 'empty':
        if start_index - end_index == 0:
            print(1)
        else:
            print(0)
    elif command == 'front':
        if start_index - end_index == 0:
            print(-1)
        else:
            print(queue[start_index])
    elif command == 'back':
        if start_index - end_index == 0:
            print(-1)
        else:
            print(queue[end_index-1])
    else:
        c, num = command.split()
        queue[end_index] = int(num)
        end_index += 1
    return start_index, end_index



for i in range(n):
    cmd = sys.stdin.readline()
    start_index, end_index = func(cmd[:-1], start_index, end_index)

# memory : 94212KB
# time   : 2416ms