#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int,int> &a, const pair<int,int> &b){
    return a.second > b.second ? true : false;
}

int main(){
    int n, answer;
    vector<pair<int, int>> assignment;
    cin>>n;
    
    for(int i=0; i<n; i++){
        int d, w;
        cin>>d>>w;
        assignment.push_back(make_pair(d,w));
    }
    sort(assignment.begin(), assignment.end(), compare);
    
    int score[1001] = {0,};
    for(int i=0; i<n; i++){
        int idx = assignment[i].first;
        if(!score[idx])
            score[idx] = assignment[i].second;
            
        else{
            while(score[--idx]){if(idx==1) break;};
            if(idx > 0 && assignment[i].second > score[idx])
                score[idx] = assignment[i].second;
        }
    }

    for(int i=1; i<1001; i++)
        answer += score[i];
        
    cout<<answer<<endl;
    
    return 0;
}
