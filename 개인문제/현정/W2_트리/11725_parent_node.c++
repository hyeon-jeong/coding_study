//문제 : 트리의 부모 찾기
//트리의 성질을 이용한 BFS


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector< vector<int> > v;
int parent[100001]; // 최대 노드 개수가 10만
bool check[100001];

void bfs(){
    queue <int> q; // 노드들의 큐
    q.push(1); // 루트노드
    check[1] = true;

    while(!q.empty()){
        int temp = q.front();
        q.pop();

        for(int nodetemp : v[temp]){
            //범위 기반 for문

            //방문 안했을 때
            if(!check[nodetemp]){
                parent[nodetemp] = temp;
                check[nodetemp] = true;
                q.push(nodetemp);
            }
        }
    }

    for (int i=2; i<= n; i++){
        cout << parent[i] << "\n";
    }
}

int main(){
    cin >> n;
    v.resize(n+1);
    for (int i=0; i<n-1; i++){
        int node1, node2; //입력받을 노드 -> 인덱스로
        cin >> node1 >> node2;
        v[node1].push_back(node2);
        v[node2].push_back(node1);
    }

    bfs();

}

