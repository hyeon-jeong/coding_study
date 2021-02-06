#include <iostream>
using namespace std;

int board[15];
int N, ans = 0;

bool progress(int x)
{
    for(int i = 0; i < x; i++)
        if(board[i] == board[x] || abs(board[x] - board[i]) == x - i)
            return false;
    return true;
}

void nqueen(int x)
{
    if(x == N)
        ans++;
    else{
        for(int i = 0; i < N; i++){
            board[x] = i; 
            if(progress(x)) 
                nqueen(x+1);
        }
    }
}

int main() {
    cin >> N;
    nqueen(0);
    cout << ans;
}
