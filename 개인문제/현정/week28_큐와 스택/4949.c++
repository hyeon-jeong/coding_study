//균형잡힌 세상(스택)
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    
    while(1){
        string inputs = ""; //초기화...? 해야해...?
        getline(cin, inputs);
        //변수 세팅, flag 는 균형을 이루고 있는 상태(true)가 디폴트!
        bool flag=true;
        int size = inputs.length();
        stack <char> s;
        //quit 
        if(inputs == ".") break;
        //문자열의 괄호 탐색
        for(int i=0; i<size; i++){
            if(inputs[i] == '(' || inputs[i] == '[') s.push(inputs[i]);
            else if(inputs[i] == ')'){
                if(!s.empty() && s.top() =='(') s.pop();
                //쌍이 맞지 않을때
                else{
                    flag = false;
                    break;
                }
            }
            else if(inputs[i] == ']'){
                if(!s.empty() && s.top() == '[') s.pop();
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(s.empty() && flag) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}