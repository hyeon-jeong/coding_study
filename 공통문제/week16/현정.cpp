#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

queue < pair<int,int> > q;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    
    for(int i=0; i<food_times.size(); i++){
        q.push(make_pair(i+1, food_times[i]));
    }
    for(int i=0; i<k; i++){
        int time = q.front().second;
        int food = q.front().first;
        //cout << food << " " << time << endl;
        q.pop();
        if(time > 1) q.push(make_pair(food, time -1));
        
    }
    if(!q.empty()) answer = q.front().first;
    else answer = -1;
    
    return answer;
}