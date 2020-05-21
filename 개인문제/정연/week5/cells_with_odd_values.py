class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        matrix = [[0]*m for i in range(n)]
        for ri, ci in indices:
            for column in range(m):
                matrix[ri][column] += 1
            for row in range(n):
                matrix[row][ci] += 1
        
        ans = 0
        for i in range(n):
            for j in range(m):
                if matrix[i][j]%2 == 1:
                    ans += 1
        return ans
