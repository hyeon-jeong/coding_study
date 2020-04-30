#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;

    stack <int> s;
    string str;

    for (int i=0; i< n; i++){
        cin >> str;

        if(str == "push"){
            int num;
            cin >> num;
            s.push(num);
        }
        else if(str == "pop"){
            if(s.empty())
                cout << "-1" << "\n";
            else
            {
                int temp;
                temp = s.top();
                cout << temp << "\n";
                s.pop();
            }
        }
        else if (str == "size"){
            cout << s.size() <<"\n";
        }
        else if (str == "empty"){
            if(s.empty())
                cout << 1 <<"\n";
            else
                cout << 0 <<"\n";
        }
        else if (str == "top"){
            if(s.empty())
                cout << -1 <<"\n";
            else
                cout << s.top() <<"\n";
        }
    }
    return 0;
}
