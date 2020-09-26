//스도쿠 - 같은 듯 다른 문제 + 짜증나는 문자열 처리,,,
#include <iostream>
#include <vector>
#include <cstring>
#include<cstdlib>    //C++
#include<cstdio>

using namespace std;
int sdoku[9][9];
bool rows[9][10];
bool cols[9][10];
bool box[9][10];

void dfs(int cnt){
    //cout << "cnt : " << cnt << endl;
    int x = cnt%9;
    int y = cnt/9;

    if(cnt == 81){
        cout << "\n";
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << sdoku[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }

    if(sdoku[y][x] != 0) dfs(cnt+1);
    else{
        for(int k=1; k<10; k++){
            if(!rows[y][k] && !cols[x][k] && !box[(y/3)*3 + x/3][k]){
                sdoku[y][x] = k;
                rows[y][k] = true;
                cols[x][k] = true;
                box[(y/3)*3 + x/3][k] = true;
                dfs(cnt+1);
                sdoku[y][x] = 0;
                rows[y][k] = false;
                cols[x][k] = false;
                box[(y/3)*3+x/3][k] = false;                
                //continue; //k 가 작은게 좋으니까...?!
            }
        }
    }
}

int main(){
    ios::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    string temp;
    for(int i=0; i<9; i++){
        cin >> temp;
        for(int j=0; j<9; j++){
            sdoku[i][j] = temp[j] - '0'; //ASCII 코드값이 아닌 정수 그대로 값 나와야함. 그러니까 그냥 '0' 빼면 됨
            if(sdoku[i][j]!=0){
                rows[i][sdoku[i][j]] = true;
                cols[j][sdoku[i][j]] = true;
                box[(i/3)*3+j/3][sdoku[i][j]] = true;
            }
        }
    }
    dfs(0);

    return 0;
}