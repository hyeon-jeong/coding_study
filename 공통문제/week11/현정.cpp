#include <iostream>
#include <cstring>
#include <queue>
#include <string.h>
#include <cstdio>

using namespace std;

string input[301];
int visit[301][301]; // 방문확인용
int popping[301][301]; //지뢰 개수 저장용
//vector <int> bomb;
int dx[8] = {0, 0, -1, -1, -1, 1, 1, 1};
int dy[8] = {1, -1, 1, 0, -1, 1, 0, -1};
int click; //결과
int t,n; // 입력받을 변수

void dfs(int x, int y){
    click ++; // 이게 맞을까..?
    visit[x][y] = 1;
    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0<= nx && nx < n && 0 <= ny && ny < n){
            if(popping[nx][ny] == '*' && visit[nx][ny] == 0){
                dfs(nx,ny);
            }
            else if(popping[nx][ny] == '.' && visit[nx][ny] == 0){
                continue; // ..? 
            }
            //만약에 전부 다 탐색했다면 if문을 어떻게 만들어야 하지..?
        }
    }
}

int main(void){

    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        scanf("%d", &n);
        //string input[301]; // 입력 저장 -> 다른 배열에 저장해주어야 함. 아니근데 이거 테스트케이스마다 덮어써지면 에러날것 같은데...?ㅜㅜ
        //memset(visit, 0, sizeof(visit));
        //memset(popping, 0, sizeof(popping));
        for(int j=0; j<n; j++){
            cin >> input[j];
        }
        for(int l=0; l<n; l++){
            for(int m=0; m<n; m++){
                if(input[l][m] == '*' && visit[l][m] == 0){ //문자열 비교할때, equals 였나..?
                    click = 0;
                    dfs(l,m);

                }
            }
        }
        printf("#%d %d\n", i, click);
    }


}

