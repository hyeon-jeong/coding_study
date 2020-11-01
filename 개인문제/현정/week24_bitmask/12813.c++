#include <iostream>
#include <cstring>
#include <cstdio>

int main(){
    unsigned char A[100001] = {0,};
    unsigned char B[100001] = {0,};
    unsigned char ans[100001] = {0,};

    using namespace std;

    scanf("%s %s", A, B);
    //and
    for(int i=0; i<100000; i++){
        ans[i] = A[i] & B[i];
    }
    cout << ans << "\n";
    //or
    for(int i=0; i<100000; i++){
        ans[i] = A[i] | B[i];
    }
    cout << ans << "\n";
    //xor
    for(int i=0; i<100000; i++){
        ans[i] = A[i] != B[i] ? '1' : '0'; // == 으로 하면 안됨...?
    }
    cout << ans << "\n";
    //~A
    for(int i=0; i<100000; i++){
        ans[i] = A[i] == '1' ? '0' : '1';
    }
    cout << ans << "\n";
    //~B
    for(int i=0; i<100000; i++){
        ans[i] = B[i] == '1' ? '0' : '1';
    }
    cout << ans << "\n";

    return 0;
}