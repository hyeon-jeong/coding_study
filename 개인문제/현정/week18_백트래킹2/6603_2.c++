//로또
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int K, num;
int lotto[13];
int results[6];

void dfs(int start, int depth){
    if(depth == 6){
        for(int i=0; i<6; i++){
            cout << results[i] << " ";
        }
        cout << "\n";
        return;
    }
    else{
        for(int i=start; i<=K; i++){
            results[depth]=lotto[i];
            dfs(i+1, depth+1);
        }
    }
}

int main(){
    while(true){
        cin >> K;
        if(K==0) break;
        for(int i=1; i<=K; i++){
            cin >> num;
            lotto[i] = num;
        }
        //0번째부터 탐색. 당연히 깊이도 0
        dfs(1, 0);
        cout << "\n";
    }

    return 0;
}