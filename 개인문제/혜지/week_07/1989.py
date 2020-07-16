'''1989. 초심자의 회문 검사'''

'''level" 과 같이 거꾸로 읽어도 제대로 읽은 것과 같은 문장이나 낱말을 회문(回文, palindrome)이라 한다.
단어를 입력 받아 회문이면 1을 출력하고, 아니라면 0을 출력하는 프로그램을 작성하라.

'''각 단어의 길이는 3 이상 10 이하이다.'''

'''가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에 하나의 단어가 주어진다.'''

'''출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.'''


T = int(input())
answer_1 = []
answer_2 = []

for i in range(1, T+1) :
    word = input()
    answer_1 = []
    answer_2 = []
    for m in range(len(word)//2) :
        answer_1.append(word[m])
    if len(word)%2 != 0 :
        for m in range((len(word)//2)+1, len(word)) :
            answer_2.append(word[m])
    else :
        for m in range(len(word)//2, len(word)) :
            answer_2.append(word[m])

    answer_2.reverse()
    for k in range(len(answer_1)) :
        if answer_1[-1] == answer_2[-1] :
            answer_1.pop()
            answer_2.pop()
                
    if len(answer_1) == 0 and len(answer_2) == 0 :
        print("#%d 1" %i)
    else :
        print("#%d 0" %i)
