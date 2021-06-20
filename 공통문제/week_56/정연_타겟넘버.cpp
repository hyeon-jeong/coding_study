#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<int> numbers, int target, int& answer, int index, int sum){ // sum = 지금까지의 수들의 합
    if(index == numbers.size()-1){
        if(target == sum + numbers[index])
            answer++;
        if(target == sum - numbers[index])
            answer++;
        return;
    }
    
    dfs(numbers, target, answer, index+1, sum + numbers[index]);
    dfs(numbers, target, answer, index+1, sum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;  
    dfs(numbers, target, answer, 0, 0);
    return answer;
}
