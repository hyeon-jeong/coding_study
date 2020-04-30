#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){

    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    queue <int> q;
    string str;

    for (int i=0; i< n; i++){
        cin >> str;

        if(str == "push"){
            int num;
            cin >> num;
            q.push(num);
        }
        else if(str == "pop"){
            if(q.empty())
                cout << "-1" << "\n";
            else
            {
                int temp;
                temp = q.front();
                cout << temp << "\n";
                q.pop();
            }
        }
        else if (str == "size"){
            cout << q.size() <<"\n";
        }
        else if (str == "empty"){
            if(q.empty())
                cout << 1 <<"\n";
            else
                cout << 0 <<"\n";
        }
        else if (str == "front"){
            if(q.empty())
                cout << -1 <<"\n";
            else
                cout << q.front() << "\n";
        }
        else if (str == "back"){
            if(q.empty())
                cout << -1 <<"\n";
            else
                cout << q.back() << "\n";
        }
    }
    return 0;
}
