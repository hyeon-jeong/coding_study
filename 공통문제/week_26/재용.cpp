// 월간 코드 첼린지 시즌 1 : 삼각달팽이.cpp
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> arr(n, vector<int>(n, 0));
    vector<int> answer;
    int x = 0, y = 0; // 좌표
    int num = 1; // 채워넣을 숫자
    int state = 0; // 아래(0), 오른쪽(1), 위(2)
    
    for(int i = 0; i < n; i++){
        switch(state){
            case 0: // 아래
                for(int j = i; j < n; j++){
                    arr[x++][y] = num++;
                }
                x--;
                y++;
                state = 1;
                break;
            case 1: // 오른쪽
                for(int j = i; j < n; j++){
                    arr[x][y++] = num++;
                }
                y -= 2;
                x--;
                state = 2;
                break;
            case 2: // 위
                for(int j = i; j < n; j++){
                    arr[x--][y--] = num++;
                }
                x += 2;
                y++;
                state = 0;
                break;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] != 0){
                answer.push_back(arr[i][j]);
            }
        }
    }
    return answer;
}
