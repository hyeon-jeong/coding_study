#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;

    queue <int> q;
    for(int i=1; i<=n ;i++){
        q.push(i);
        //cout << "push" << i << "\n";

    }

    int temp;
    while(q.size() != 1){
        q.pop();
        temp = q.front();
        q.pop();
        q.push(temp);
    }

    cout << q.front() << "\n";

    return 0;
}
