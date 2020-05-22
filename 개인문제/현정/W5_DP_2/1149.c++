#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b) {return a<b?a:b;}

int main(){
    int N, money;
    cin >> N;

    int input[1001][3];
    int house[1001][3];

    //input 

    for(int i=1; i<=N; i++){
        int r,g,b;
        for(int j=0;j<3; j++){
            cin >> input[i][j];
        }
    }

    //calculate - DP
    house[0][0] = house[0][1]=house[0][2] = 0;
    input[0][0] = input[0][1] = input[0][2] = 0;


    for(int i=1; i<=N; i++){
        house[i][0] = min(house[i-1][1], house[i-1][2]) + input[i][0];
        house[i][1] = min(house[i-1][0], house[i-1][2]) + input[i][1];
        house[i][2] = min(house[i-1][0], house[i-1][1]) + input[i][2];
    }

    money = min(min(house[N][0], house[N][1]), house[N][2]);

    cout << money << endl;


    return 0;

}