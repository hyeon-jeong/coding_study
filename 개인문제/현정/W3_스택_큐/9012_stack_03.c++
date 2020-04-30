#include <iostream>
#include <stack>
#include <string>

using namespace std;

int check(string str){
    stack <char> s;
    for (int i=0; i<str.length(); i++){
        if(str[i] == '(')
            s.push(str[i]);
        else{
            if(s.empty())
                return 0;
            else
                s.pop();
        }
    }
    if(s.empty())
        return 1;
    else 
        return 0;
}

int main(){
    int t;
    cin >> t;
    //괄호 문자열 개수
    for(int i=0; i<t; i++){
        string str;
        cin >> str;
        if(check(str) == 0)
            cout << "NO" << "\n";
        else 
            cout << "YES" << "\n";
    }
    return 0;
}