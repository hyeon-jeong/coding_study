#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, index = 0, current = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    while(!pq.empty() || index < jobs.size()){ //pq.empty() == true여도 push 하는데에는 문제가 없으므로 or 조건
        if(index < jobs.size() && current >= jobs[index][0]){ //job 요청 시간이 현재 시간보다 이전이거나 현재 시간인 경우에만 pq.push
            pq.push(jobs[index]);
            index++;
            continue;
        }
        
        if(!pq.empty()){
            current += pq.top()[1];
            answer += current - pq.top()[0];
            pq.pop();
        }
        
        else
            current = jobs[index][0];
    }
    
    return answer / jobs.size();
}
