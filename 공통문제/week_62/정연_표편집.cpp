#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int curPos;
int n,k;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int data):data(data), prev(NULL), next(NULL){};
};

vector<Node*> table;
stack <int> deleted;

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
            
            if(table[curPos] -> prev == NULL){
                table[curPos] -> next -> prev = NULL;
                curPos = table[curPos] -> next -> data;
            }
            
            if(table[curPos] -> next == NULL){
                table[curPos] -> prev -> next = NULL;
                curPos = table[curPos] -> prev -> data;
            }
            
            else{
                table[curPos] -> prev -> next = table[curPos] -> next;
                table[curPos] -> next -> prev = table[curPos] -> prev;
                curPos = table[curPos] -> next -> data;
            }
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
    string answer(n, 'X');
    curPos = k;
    table = vector<Node*>(n);
    
    for(int i=0; i<n; i++){
        table[i] = new Node(i);
    }
    
    table[0] -> next = table[1];
    table[n-1] -> prev = table[n-2];
        
    for(int i=1; i<n-1; i++){
        table[i] -> next = table[i+1];
        table[i] -> prev = table[i-1];
    }
    
    command(cmd);
    
    int search = 0;
    if(table[0]->data == 0)
        answer[0] = 'O';
    else
        answer[0] = 'X';
    
    while(table[search]->next != NULL){
        search = table[search]->next->data;
        answer[search] = 'O';
    }
    
    return answer;
}
