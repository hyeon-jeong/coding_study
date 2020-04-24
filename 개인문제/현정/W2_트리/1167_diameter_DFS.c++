#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector < pair<int, int> > arr[100001];
int check[100001];
int cost[100001];
//int max_distance, max_index;

//DFS 가 가장 적합?? -> 가장 깊은 노드 중, 가중치가 가장 큰 노드찾기?
//찾은 노드를 기준 정점으로 고치고 -> 여기서 다시 가장 가중치+거리가 큰 노드를 찾는다

int diameter = 0;
int maxNode = 0;

void dfs(int node, int dist){

    if(check[node] == 1)
        return;
    
    check[node] = true;
    
    //cost[node] = dist;
    if(dist > diameter){
        diameter = dist;
        maxNode = node;
    }

    for(int i=0; i< arr[node].size(); i++){
        dfs(arr[node][i].first, dist + arr[node][i].second);
    }
}

int main(){
    //노드 개수 입력받기
    int n;
    cin >> n;

    //인접리스트 만들기
    for (int i=0; i<n; i++){
        int start;
        cin >> start;
        while(true){
            int dest;
            cin >> dest;
            if(dest == -1){
                break;
            }
            int weight;
            cin >> weight;
            arr[start].push_back({dest, weight});
        } 
    }
    memset(check, 0, sizeof(check));
    dfs(1,0);
    //dfs 두 번으로 트리 지름을 구하는 것이므로, 
    //dfs 할 때마다 check 배열을 리셋해줘야함. (이거때매 계속 틀렸다...)
    memset(check, 0, sizeof(check));
    dfs(maxNode, 0);
    cout << diameter << "\n";

    return 0;
}