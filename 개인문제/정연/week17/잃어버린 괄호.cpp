#include <iostream>
#include <string>

using namespace std;
int main(){
    int ans = 0;
    string expr;
    string tmp = "";
    bool flag = false;
    
    cin>>expr;
    
    for (int i = 0; i <= expr.size(); i++){
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '\0'){              
            if (flag)
                ans -= stoi(tmp);
            else
                ans += stoi(tmp);
            tmp = "";
            
            if (expr[i] == '-')
                flag = true;
            continue;
        }
        tmp += expr[i];
    }
    cout<<ans<<endl;
    return 0;
}
