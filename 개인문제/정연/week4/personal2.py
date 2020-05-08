class Solution(object):
    def partitionLabels(self, S):
        part = {c: i for i, c in enumerate(S)}
        start = end = 0
        answer = []
        
        for i, c in enumerate(S):
            end = max(end, last[c])
            if i == end:
                answer.append(i - start + 1)
                start = i + 1
            
        return answer
