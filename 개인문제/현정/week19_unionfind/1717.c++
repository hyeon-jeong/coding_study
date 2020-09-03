//집합의 표현
#include <iostream>
#include <cstdio>
using namespace std;
int parents[1000001];
int n,m;

int find(int u){
    return parents[u] == u? u : parents[u] = find(parents[u]);
}

void merge(int u, int v){
    parents[find(v)] = find(u);
}

int main(){
    int a, b, c;
    scanf("%d %d", &n, &m);
    for(int i=0; i<=n; i++){
        parents[i] = i;
    }

    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0) merge(b, c);
        else{
            if(find(b) == find(c)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}