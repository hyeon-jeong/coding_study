//여행가자
#include <iostream>
#include <cstdio>
#include <cstring> //memset 사용때문~~~
using namespace std;
int cities[201][201];
int parents[201];
int N, M;

int find(int node){
    return parents[node] == node ? node : parents[node] = find(parents[node]);
}

void merge(int u, int v){
    parents[find(v)] = find(u);
}

int main(){
    memset(cities, 0, sizeof(cities));
    scanf("%d", &N);
    scanf("%d", &M);

    for(int i=0; i<M; i++){
        parents[i] = i;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &cities[i][j]);
            if(cities[i][j]) merge(i, j); // 이로써 양방향으로 트리 만들어짐.
        }
    }
    
    int root;
    scanf("%d", &root);
    int next = find(root-1); //parents 배열이 0부터 시작
    bool flag = true;
    for(int i=0; i<M-1; i++){
        scanf("%d", &root);
        if(find(root-1) != next) flag = false; //한번이라도 존재하지 않으면 false
    }
    if(flag) printf("YES\n");
    else printf("NO\n");

    return 0;
}
