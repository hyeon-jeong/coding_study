//피보나치 수 3 - 피사노 주기 : 피보나치 수를 K 로 나눈 나머지는 항상 주기를 가진다.
// M = 10^K 일 때, K>2 라면 주기는 15*10^(k-1) 이다.

#include <iostream>
#include <cstring>

using namespace std;

long long arr[1500010];
int INF = 1000000; //100만으로 나눈 피보나치 수열의 반복되는 주기는 150만이다.

void fibo(){
    arr[0] = 0;
    arr[1] = 1;
    for(int i=0; i<1500000; i++){
        arr[i+2] = (arr[i+1]+arr[i])%INF;
    }
}

int main(){
    long long n;
    cin >> n;
    fibo();
    cout << arr[n%1500000] << "\n"; //입력된 수를 150만으로 나눈 나머지를 가져옴.
}
