//집합 문제
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int M, num, bit;
string input;

int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> M; 
    while(M--){
        input.clear(); //계속 새로 받아줘야 하므로 비워줘야한다.
        cin >> input; 
        if(input == "add"){
            cin >> num;
            bit = bit | (1 << num);
        }
        else if(input == "remove"){
            cin >> num;
            bit = bit & ~(1 << num); 
        }
        else if(input == "check"){
            cin >> num;
            if(bit & (1 << num)) cout << "1 \n";
            else cout <<"0 \n";
        }
        else if(input == "toggle"){
            cin >> num;
            bit = bit ^ (1 << num); //될까용~~~~!!! 아님 if 문 쓰구~~
        }
        else if(input == "all"){ 
            bit = (1<<21) - 1; // 총 20개 있으니까... 최대는 2^21-1!
        }
        else if(input == "empty"){
            bit = 0;
        }
    }
    return 0;
}