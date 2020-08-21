#include <iostream>
#include <algorithm>
const int MAX = 100000;
using namespace std;

int main(){
    int T,N;
    pair <int,int> candidate[MAX];
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>T;
    for (int j=0; j<T; j++){
        cin>>N;
        for (int i=0; i<N; i++)
            cin>>candidate[i].first>>candidate[i].second;
        sort(candidate, candidate+N);
        
        int ans = 1;
        int interview = candidate[0].second;
        
        for (int i=l; i<N; i++){
            if (employee[i].second < interviewRank){
                ans++;
                interview = candidate[i].second;
            }
        }
        cout<<result<<endl;
    }
    
    return 0;
}
