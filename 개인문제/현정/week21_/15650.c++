//N과 M(2) - 새로 짜보기
#include <iostream>
#include <vector>

using namespace std;
int numbers[9];
//int visited[9] = {0,};
int N, M;

void backtrack(int now){
    if(now == M){
        for(int i=0; i<M; i++){
            cout << numbers[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i= now==0?1:numbers[now-1]+1; i<=N; i++){
        numbers[now] = i;
        backtrack(now+1);
    }
}

int main(){
    cin >> N >> M;
    backtrack(0);
    return 0;
}