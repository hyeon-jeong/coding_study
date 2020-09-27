#include <iostream>
#include <stack>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N, h;
    cin>>N;
    stack<pair<int, int>> s;
    
    for (int i=0; i<N; i++){
        cin>>h;
        
        while (!s.empty()){
            if (s.top().second > h){
                cout << s.top().first << " ";
                break;
            }
            s.pop();
        }
        
        if (s.empty())
            cout << 0 << " ";
        
        s.push(make_pair(i+1, h));
    }
    return 0;
}
