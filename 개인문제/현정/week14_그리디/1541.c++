#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main(){
    string exp; 
    bool minus = false; // 음수
    int result=0; 
    string buffer="";
    cin >> exp;

    for(int i=0; i<=exp.length(); i++){
        cout << exp[i] ;
        cout << ",";
        if(exp[i] == '+' || exp[i] == '-' || i==exp.length()){
            //마이너스일 때만 빼기.
            if(minus)
                result -= stoi(buffer);
            else
                result += stoi(buffer);
            if(exp[i] == '-')
                minus = true;
            buffer = "";
            
            continue; // 버퍼에 안들어가도록
        }
         buffer += exp[i];
    }
    cout << result ;
    return 0;
}