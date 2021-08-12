#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    long long answer=0;
    cin>>n>>k;
    
    vector<pair<int,int>> jewelry;
    for(int i=0; i<n; i++){
        int m, v; cin>>m>>v;
        jewelry.push_back(make_pair(m,v));
    }
    
    int bag[k];
    for(int i=0; i<k; i++){
        cin>>bag[i];
    }
    
    sort(jewelry.begin(), jewelry.end());
    sort(bag, bag+k);
  
    int idx = 0;
    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        while(idx<n && jewelry[idx].first <= bag[i])
            pq.push(jewelry[idx++].second);
            
        if(!pq.empty()){
            answer += pq.top();
            pq.pop();
        }
    }
    
    cout<<answer<<endl;
}
