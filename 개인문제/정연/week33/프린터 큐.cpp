#include <iostream>
#include <queue>
using namespace std;

int t;

int main(){
    int n,m,cnt;
    cin>>t;
    while(t--){
        cnt = 0;
        cin>>n>>m;
        queue<pair<int,int>> printer;
        priority_queue<int> pq;
        for (int i=0; i<n; i++){
            int val;
            cin>>val;
            printer.push({i,val});
            pq.push(val);
        }
        
        while(!printer.empty()){
            int idx = printer.front().first;
            int value = printer.front().second;
            printer.pop();
            
            if (value == pq.top()){
                pq.pop();
                cnt++;
                if (idx == m){
                    cout<<cnt<<endl;
                    break;
                }
            } 
            else
                printer.push({idx,value});
        }
    }
    return 0;
}
