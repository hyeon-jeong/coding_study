#include <iostream>

using namespace std;

int n,m;
int numbers[9]={};
int visited[9]={};

//dfs_backtracking
void backtracking(int i){
    //조건 만족시 출력
    if (i==m){
        for(int j=0; j<m ; j++){
            cout << numbers[j] << " ";
        }
        cout << "\n";
        return;
    }

    //재귀 들어가는 부분
    //1부터 N까지의 수 대입
    for(int j=i+1; j<=n; j++){ // 이거 말구 1~N까지 해도 되지 않을까?
        if(visited[j]==0 && numbers[i-1] < j) // 구글링하면 이걸 빼는경우가 많았음. 대체 왜..?
        {
            visited[j] = 1;
            numbers[i] = j; //numbers[i-1] < numbers[i]
            backtracking(i+1);
            visited[j] = 0;
        }
    }
}

int main(){
    cin >> n >> m;
    backtracking(0);
    return 0;
}