//가운데를 말해요~~~
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, num;
priority_queue<int> Min_PQ;
priority_queue<int, vector<int>, greater<int> > Max_PQ;

int main(){
    ios::sync_with_stdio (false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    while(N--){
        cin >> num;
        if(Min_PQ.empty() || Min_PQ.top() >= num){
            Min_PQ.push(num);
            if(Min_PQ.size() > Max_PQ.size()+1){
                Max_PQ.push(Min_PQ.top());
                Min_PQ.pop();
            }
        }
        else if(Max_PQ.empty() || Max_PQ.top() <= num){
            Max_PQ.push(num);
            if(Max_PQ.size() > Min_PQ.size()){
                Min_PQ.push(Max_PQ.top());
                Max_PQ.pop();
            }
        }
        else if(Min_PQ.size() <= Max_PQ.size()){
            Min_PQ.push(num);
        }
        else if(Min_PQ.size() > Max_PQ.size()){
            Max_PQ.push(num);
        }

        cout << Min_PQ.top();
    }

    

    return 0;
}