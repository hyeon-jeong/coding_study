#include <iostream>

using namespace std;

int N, cnt;
int col[15];

//퀸을 놓을 수 있는지 판단하는 함수
int promising(int i){
    int k=1;
    bool flag = true;

    while(k < i && flag){
        //같은 열 또는 대각선일 경우
        if(col[i]==col[k]||col[i]-col[k]==i-k || col[k]-col[i]==i-k)
            flag = false;
        k ++;
    }
    return flag;
}


//퀸 배치
void queens(int i){
    //끝임(완성)
    if(promising(i)){ // 배열 가능하면
        if(i== N)
            cnt ++;
        else{
            //해당 열에 배치
            for(int j=1; j<=N; j++){
                col[i+1] = j;
                queens(i+1); // 재귀적함수
            }
        }
    }

}

//main 함수
int main(){

    cin >> N;

    queens(0);

    cout << cnt << "\n";
    return 0;
}