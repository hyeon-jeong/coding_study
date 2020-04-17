#include <iostream>

using namespace std;

int N, M;
//완성된 배열 저장
int numbers[8];
//방문기록 저장하는 배열 생성
int visited[8];

//이후에 나올 i는? 
//현재 배열에 저장된 숫자의 개수 -> 즉, 현재시점의 위치?!

//plunning - 이 문제에서는 함수 따로 뺄 필요 없음


//dfs_backtracking
void backtracking(int i){
    
    //조건을 만족했다면 출력하기(M개 쌓이면 출력!)
    if(i == M){
        for(int j=0; j<M ; j++)
            cout << numbers[j] << " ";
        cout << "\n";
        return;
    }

    //조건을 만족하지 않았을때, 재귀로 들어감
    for(int j=1; j<=N; j++){
         //이미 방문한 노드일때 생략(가지치기의 느낌,,)
        if(visited[j])
            continue;
         visited[j] = 1;
         numbers[i] = j;
         backtracking(i+1);
         //i가 바뀔 것이므로 다시 리셋해주기? -> 다시 생각해보자
         visited[j] = 0;
         cout <<"next loop\n";
     }
}

//main
int main(){
    cin >> N >> M;
    for (int i=1; i<=N; i++){
        visited[i]=0;
    }
    backtracking(0);

    return 0;
}