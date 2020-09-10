// Brute Force

#include <iostream>
using namespace std;

int n,cnt,tmp,flag,ans;

int main(){
    cin >> n;

    while(cnt != n){
        ans++;
        flag = 0;
        tmp = ans;
        while(tmp){
            if (tmp % 1000 == 666)flag = 1; // 체크하는 숫자를 1000으로 나눴을 때의 나머지가 666 = 666을 포함하는 숫자
            tmp /= 10; // 666으로 나누어떨어지지 않는 경우 ex. 106661 >> 10으로 나누면 10666.1이 되므로 다음번 loop에서 flag = 1이 됨
        }
        
        if (flag){cnt++;}
    }  
    cout << ans << '\n';
    return 0;
}
