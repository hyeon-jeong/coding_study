#include <string>
#include <vector>
#include <stack>

using namespace std;

int curPos;
int n,k;
stack <int> deleted;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int data):data(data), prev(NULL), next(NULL){};
};

vector<Node*> table;

void command(vector<string>& cmd){    
    for(string s : cmd){
        if(s[0] == 'U' || s[0] == 'D'){
            int move = stoi(s.substr(2)); //단순히 s[2] 로 하면 오류가 난다.
            if(s[0] == 'D'){
                while(move--){ // move = 몇 칸 떨어져 있는 행인가?
                    curPos = table[curPos] -> next -> data; // move 개수 = next node로 이동하는 횟수
                }
            }
            else{
                while(move--){
                    curPos = table[curPos] -> prev -> data; // move 개수 = prev node로 이동하는 횟수
                }
            }
        }
        
        else if(s[0] == 'C'){
            deleted.push(curPos); // 삭제해야 하므로 deleted stack에 저장
         
            if(table[curPos] -> prev != NULL) // 첫 번째 노드가 아닌 경우
                table[curPos] -> prev -> next = table[curPos] -> next; // prev의 next = 현재의 next
            
            if(table[curPos] -> next != NULL){ // 마지막 노드가 아닌 경우
                table[curPos] -> next -> prev = table[curPos] -> next; // next 의 prev = 현재의 prev
                curPos = table[curPos] -> next -> data; // 마지막 노드 x or 첫 번째 노드 => 다음 행으로
            }
            
            else
                curPos = table[curPos] -> prev -> data; // 마지막 노드 => 이전 행으로
            
        }
        
        else if(s[0] == 'Z'){
            int insert = deleted.top(); deleted.pop(); //deleted.top()으로 먼저 기준점을 잡아준다.
            
            if(table[insert] -> prev != NULL)
                table[insert] -> prev -> next = table[insert];
            
            if(table[insert] -> next != NULL)
                table[insert] -> next -> prev = table[insert];
        }
        
        else
            return;
    }
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    curPos = k;
    table = vector<Node*>(n);
    
    for(int i=0; i<n; i++)
        table[i] = new Node(i);
    
    table[0] -> next = table[1];
    table[n-1] -> prev = table[n-2];
        
    for(int i=1; i<n-1; i++){
        table[i] -> next = table[i+1];
        table[i-1] -> prev = table[i-2];
    }
    
    command(cmd);

    return answer;
}
