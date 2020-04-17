#include <iostream>

using namespace std;

int n,m;
int numbers[7] = {};
//bool visited[7] = {};

void backtracking(int i){

    //출력부분
    if(i==m){
        for(int j=0; j<m; j++){
            cout << numbers[j] << " ";
        }
        cout << "\n";
        return;
    }

    //재기함수
    for(int j=1; j<=n; j++){
        numbers[i]=j;
        backtracking(i+1);
    }
}

int main(){
    cin >> n >> m;
    backtracking(0);
}

