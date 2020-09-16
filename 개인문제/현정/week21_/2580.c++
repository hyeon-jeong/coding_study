//백트래킹 - 스도쿠
#include <iostream>
#include <vector>

using namespace std;
int sdoku[9][9]; //input
bool rows[9][10]; 
bool cols[9][10];
bool box[9][10]; //box id, num value

//backtracking
void dfs(int cnt){
    //cnt to point
    int x = cnt%9; 
    int y = cnt/9;

    //break when the movement is over.
    if(cnt == 81){
        cout << "\n";
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << sdoku[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }

    //recursive
    if(sdoku[y][x]!=0){
        dfs(cnt+1);
    }
    else{
        for(int k=1; k<=9; k++){
            //각 행, 열, 3x3 박스 안에 0~9 중 k 가 없을때
            if(!rows[y][k] && !cols[x][k] && !box[(y/3)*3+x/3][k]){
                //일단 넣어보고 dfs 돌림
                sdoku[y][x] = k;
                rows[y][k] = true; //y 행에 k 값이 존재함
                cols[x][k] = true; //x 열에 k 값이 존재함.
                box[(y/3)*3+x/3][k] = true; //박스 i 에 k 값이 존재함
                dfs(cnt+1);
                //k가 아닐 수도 있기 때문에 (스도쿠 해봤으면 알겠지만, 후보 여러개 있음)
                sdoku[y][x] = 0;
                rows[y][k] = false;
                cols[x][k] = false;
                box[(y/3)*3+x/3][k] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> sdoku[i][j]; // sdoku[i][j] 를 value 라 하자.
            if(sdoku[i][j]!=0){
                rows[i][sdoku[i][j]] = true; //i 행에 value 가 들어있음!
                cols[j][sdoku[i][j]] = true; //j 열에 value 가 들어있음!
                box[(i/3)*3 + j/3][sdoku[i][j]] = true;
            }
        }
    }

    dfs(0);

    return 0;
}