//그리디 - 동전0 
#include <iostream>
using namespace std;
int N, K, coin;
int main(){
    cin >> N >> K;
    int coins[N];
    for(int i=0; i<N; i++){
        cin >> coin;
        coins[i] = coin;
    }
    int cnt=0;
    for(int i=N-1; i>=0 ; i--){
        if((K - coins[i]) >= 0){
            K = K-coins[i];
            cnt ++;
            i++;
        }
    }
    cout << cnt;
    return 0;
}