#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s,ans;
    cin>>s;
    
    stack<char>str;
    
    for(int i=0; i<s.length(); i++){
        if ('A'<=s[i] && s[i]<='Z')
            ans += s[i];
        
        else{
            switch(s[i]){
                case '(':
                    str.push(s[i]);
                    break;
                case '*':
                case '/':
                    while (!str.empty() && (str.top() == '*' || str.top() == '/')){
                        ans += str.top();
                        str.pop();
                    }
                    str.push(s[i]);
                    break;
                case '+':
                case '-':
                    while (!str.empty() && str.top() != '('){
                        ans += str.top();
                        str.pop();
                    }
                    str.push(s[i]);
                    break;
                case ')':
                    while (!str.empty() && str.top() != '('){
                        ans += str.top();
                        str.pop();
                    }
                    str.pop();
                    break;
            }
        }
    }

    while (!str.empty()){
        ans += str.top();
        str.pop();
    }

    cout << ans << "\n";
    return 0;

}
