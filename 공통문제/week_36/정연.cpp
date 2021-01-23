#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if (a % b == 0)
        return b;
    return gcd(b,a%b);
} // lcm = a*b / gcd 공식을 위해 gcd도 계산

int lcm(int a, int b){
    return a*b / gcd(a,b);
} // 마지막 해를 last라고 할 때, <x:y> <= last 조건이 있어야 한다. 이 때 last % M == 0, last % == N 이면서
// last가 될 수 있는 값이 2개 이상이면 안되므로, 위의 두 조건을 만족하는 가장 작은 값이 last가 된다. 즉 lcm

int main(){
    int T,M,N,x,y,j;
    cin>>T;
   
    for (int i=0; i<T; i++){
        cin >> M >> N >> x >> y;
        int last = lcm(M,N);
        
        for(j=x; j<=last; j+=M){
            int inca = (j % N == 0) ? N : j % N; 
            if (inca == y){
                cout << j << "\n";
                break;
            }
        }
        if (j > last)
            cout << -1 << "\n";
    } 
    return 0;
}
