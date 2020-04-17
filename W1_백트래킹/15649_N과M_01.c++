#include <iostream>

using namespace std;

int N, M;
//완성된 배열 저장
int numbers[8]={};
//방문기록 저장하는 배열 생성
bool visited[8] = {}; 
//여기서, NULL 로 일단 두어야 함..!
//뒤에 조건문에서 자꾸 이상하게 걸림 ㅠㅠ

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
        if(visited[j]==false){
            visited[j] = true;
            numbers[i] = j; //1부터 들어감 
            backtracking(i+1);

            //i가 바뀔 것이므로 다시 리셋해주기? -> 다시 생각해보자
            visited[j] = false;
        }
     }
}

//main
int main(){
    cin >> N >> M;

    backtracking(0);

    return 0;
}