//트리순회
#include <iostream>
using namespace std;

// 노드 구조체 정의
struct node{
    char left;
    char right;
};
// 구조체 배열
struct node arr[27];

//전위 순회
void pre(char root){
    if(root == '.') return;
    cout << root; //처음에 출력
    pre(arr[root].left);
    pre(arr[root].right);
}

//중위 순회
void in(char root){
    if(root == '.') return;
    in(arr[root].left);
    cout << root; //중간에 출력
    in(arr[root].right);
}

//후위 순회
void post(char root){
    if(root == '.') return;
    post(arr[root].left);
    post(arr[root].right);
    cout << root; //마지막에 출력
}

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        char a, b, c;
        //scanf("%c %c %c",&a,&b,&c);
        cin >> a >> b >> c;
        arr[a].left = b;
        arr[a].right = c;
    }
    //항상 A 가 루트노드
    pre('A'); cout << "\n";
    in('A'); cout << "\n";
    post('A'); cout << "\n";
    return 0;
}