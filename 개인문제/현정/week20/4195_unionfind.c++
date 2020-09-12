#include <iostream>
#include <map>
#include <cstring>

using namespace std;
map<string, pair<string, int> > friends; //이름, 루트이름, 경로길이

string find(string s){
    //처음보는 노드 -> 새로 트리 만들어야함.
    if(friends.count(s)==0){
        friends[s]={s, 1}; //자기자신을 루트노드로 하는 트리 생성.
        return s; //이름 반환
    }
    return s==friends[s].first? s : friends[s].first = find(friends[s].first);
}

void merge(string s1, string s2){
    //union-find 기본 향태와 유사함!
    s1 = find(s1); s2 = find(s2); //s1, s2의 루트노드를 불러냄.
    //s1과 s2 가 같은 트리에 포함되어 있다면
    if(s1 == s2){
        printf("%d\n", friends[s1].second);
        return ;
    }
    //s1쪽의 크기가 더 크도록 맞춰줌.
    if(friends[s1].second < friends[s2].second) swap(s1, s2);
    //s2의 루트가 s1이 되도록....
    friends[s1].second += friends[s2].second; //경로길이 더해주기.
    friends[s2].first = s1;
    friends[s2].second = 1;
    printf("%d\n", friends[s1].second);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int F, N;
    scanf("%d", &F);
    while(F--){
        friends.clear();
        scanf("%d", &N);
        string s1, s2;
        for(int i=0; i<N; i++){
            cin >> s1 >> s2;
            merge(s1,s2);
        }

    }
    return 0;
}