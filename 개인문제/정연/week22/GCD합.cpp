#include <iostream>
using namespace std;

int num[100];

int gcd(int a, int b){
    if (a%b == 0)
        return b;
    return gcd(b, a%b);  //유클리드 호제법
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++){
         int N;
         cin >> N;

         for (int i = 0; i < N; i++)
             cin >> num[i];

         long long sum = 0;
         for (int i = 0; i < N; i++)
             for (int j = i + 1; j < N; j++)
                 sum += gcd(num[i], num[j]);
         cout << sum << "\n";
    }
    return 0;
}
