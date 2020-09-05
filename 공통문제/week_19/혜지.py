import sys
input = sys.stdin.readline

N, M = map(int, input().split())
paper = []

dx = [[1, 2, 3], [0, 0, 0],  [1, 1, 0], [0, 0, 1], [0, 1, 2], [1, 1, 1], [0, -1, -2], [0, 0, -1], [0, 1, 2], [0, 0, 1], [1, 2, 2], [0, 1, 1], [1, 1, 2], [0, -1, -1], [1, 1, 2], [1, 2, 1], [1, 1, 1], [0, -1, 1], [0, 0, 1]]
dy = [[0, 0, 0], [-1, -2, -3], [0, 1, 1], [-1, -2, -2], [1, 1, 1], [0, -1, -2], [-1, -1, -1], [-1, -2, -2], [-1, -1, -1], [1, 2, 2], [0, 0, -1], [-1, -1, -2], [0, 1, 1], [-1, -1, -2], [0, -1, -1], [0, 0, -1], [0, 1, -1], [-1, -1, -1], [-1, -2, -1]]

answer = 0

for i in range(N) :
    paper.append(list(map(int, input().rstrip().split())))

for i in range(N) :
    for j in range(M) :
        for k in range(19) :
            paper_sum = paper[i][j]
            for l in range(3) :
                x = i + dx[k][l]
                y = j + dy[k][l]
                if 0 <= x < N and 0 <= y < M :
                    paper_sum = paper_sum + paper[x][y]
                else :
                    break
            if paper_sum > answer :
                answer = paper_sum

print(answer)
