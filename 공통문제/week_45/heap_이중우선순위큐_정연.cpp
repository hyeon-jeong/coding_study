#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> asc;
    priority_queue<int, vector<int>> desc;
    
    for(string op : operations){   
        if(asc.empty() && !desc.empty()){
            cout<<"desc.pop"<<'\n';
            while(desc.empty() && asc.empty()){
                asc.pop();
                desc.pop();
            }
        }
        else if(!asc.empty() && desc.empty()){
            cout<<"asc.pop"<<'\n';
            while(asc.empty() && desc.empty()){
                asc.pop();
                desc.pop();
            }
        }
        
        if(op[0] == 'I'){
            asc.push(stoi(op.substr(2)));
            desc.push(stoi(op.substr(2)));
        }
        
        else if(op[0] == 'D'){
            if(asc.empty() && desc.empty()){
                continue;
            }
            else if (op[2] == '1')
                desc.pop();
            else if (op[2] == '-' && op[3] == '1')
                asc.pop();
        }
        cout<<asc.size()<<' '<<desc.size()<<endl;
        cout<<asc.top()<<' '<<desc.top()<<endl;
    }
    
    if(asc.empty() || desc.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(desc.top());
        answer.push_back(asc.top());
    }
    return answer;
}
