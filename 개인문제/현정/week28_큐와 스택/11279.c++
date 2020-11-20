//우선순위 큐 - 최대 힙
#include <iostream>
#include <queue> 
using namespace std;
priority_queue<int, vector<int> > pq;

int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false); //시간초과 해결~
    int N, x;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x;
        if(x==0){
            if(pq.empty()) cout << "0\n";
            else{
                int result = pq.top();
                cout << result << "\n";
                pq.pop();

            }
        }
        else pq.push(x);
    }
}