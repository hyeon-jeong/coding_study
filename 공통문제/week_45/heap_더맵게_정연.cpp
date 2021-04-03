#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto scov : scoville)
        pq.push(scov);
    int answer = 0;
    
    while(pq.size() > 1 && pq.top() < K){ // 2개의 원소를 pop해야 하므로 pq.size()는 2 이상이어야 한다.
        int least = pq.top();
        pq.pop();
        int second_least = pq.top();
        pq.pop();
        
        int scov = least + (second_least * 2);
        pq.push(scov);
        answer++;       
    }
    
    if(pq.top() < K)
        return -1;
    return answer;
}
