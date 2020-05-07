#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    queue <int> q;

    int n, k;
    cin >> n >> k ;
    //cout << "입력중: "<< "\n";

    for(int i=1; i<=n ; i++){
        q.push(i);
    }
    
    cout << "<" ;

    while(!q.empty()){
        for(int i=1; i<=k-1 ; i++){
            q.push(q.front());
            q.pop();
        }

        if(q.size() == 1){
            cout << q.front() << ">" << "\n";
            q.pop();
        }
        else{
            cout << q.front() << ", ";
            q.pop();
        }

    }    

    return 0;
}