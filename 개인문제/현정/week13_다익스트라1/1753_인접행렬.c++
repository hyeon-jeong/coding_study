#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#define MAX 999999999

using namespace std;

int n, e, k;
int u, v;
int edge[20000][20000];

int * dijkstra(int a, int b){
    int graph[b];
    graph[a] = 0;
    memset(graph, MAX, sizeof(graph));

    for(int i=a; i<e; i++){
        for(int j=i+1; j<e; j++){
            int weight = edge[i][j];
            
            if(graph[i] < weight){
                continue;
            }

            if(graph[i+1] > weight + graph[i]){
                graph[i+1] = weight + graph[i];
            }
        }
    }
    return graph;
}

int main(){
    memset(edge, 0, sizeof(edge));
    scanf("%d %d", &n, &e);
    scanf("%d", &k);

    for(int i=0; i<n; i++){
        scanf("%d %d %d", &u, &v, &edge[u][v]);
    }

    int * dist = dijkstra(k,v);

    for(int i=1; i<n; i++){
        if(dist[i] == MAX){
            printf("INF\n");
        }
        else
        {
            printf("%d\n", dist[i]);
        }
    }

    return 0;
}