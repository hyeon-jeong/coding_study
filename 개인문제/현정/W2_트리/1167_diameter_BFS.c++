#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//변수 정의
vector< pair<int, int> > arr[100001]; //인접리스트
int check[100001];
int dist[100001];

//bfs(너비우선) 함수 -> input node 에서 각 점까지의 거리를 저장
void bfs(int node){
    //큐에 채워넣고
    queue <int> q;
    q.push(node);
    check[node] = true;

    //큐가 비어있지 않을 때
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        //temp 노드와 연결된 모든 노드들을 탐색(bfs)
        for(int i=0; i< arr[temp].size();i++){
            //연결된 모든 노드들이 바로 arr[temp][i].first 들. second 는 가중치!
            int current = arr[temp][i].first;
            if(check[current]== false){ 
                //chreck[temp] 로 하면 안되는 이유? 그냥 노드임. 엣지랑 연결된 노드들이 아니라..
                //arr[temp][i].first 는 노드temp -> 노드 i 로의 엣지에서 i 의 노드.(번호)
                //new 거리 = temp 노드의 거리 + 해당 노드의 가중치
                dist[current] = dist[temp] + arr[temp][i].second;
                q.push(current);
                //지금 방문해서 거리를 계산해 넣어줬으니까 check 를 True로!!
                check[current] = true;
            }
        }
    }
}

//큐 정의, 입력받은 node를 큐에 삽입 -> check[node] 는 true
//큐가 비지 않았을 때

// 현재 큐 앞에 있는 노드 temp -> 방문했으니까 check[temp] 는 true
// 큐 pop -> temp 를 pop, 이제 큐에 이 노드 없음
// 노드 temp 가 방문하지 않은 노드라면 -> check[temp] 를 true 로 바꾸고, 큐에 삽입 -> 거리+가중치 합산


int main(){
    //초기화
    memset(dist, 0, sizeof(dist));
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
            arr[start].push_back(make_pair(dest, weight));
        }
        
    }
    //두 개 단위씩 정점노드/거리 저장

    //노드가 -1일때 braek

    //인접리스트에 (노드, 거리)쌍 저장

    //루트 1번으로 부터(랜덤임) 거리 탐색 -> bfs
    memset(check, false, sizeof(check));
    bfs(1);
    //위에서 거리 저장해놓은 걸로 가장 먼 점 탐색 -> 두 점 중 하나 찾기
    int max_distance_index = 1;
    for(int i=2; i<=n ; i++){
        if(dist[max_distance_index] < dist[i])
            max_distance_index = i;
    }
    //위의 점을 루트로, 다시 각 점의 거리 구함 -> bfs
    memset(check, false, sizeof(check));
    bfs(max_distance_index);
    //루트로부터 가장 멀리 떨어진 점 찾기 -> 두 점 중 나머지 하나 찾기
    for(int i=1; i<=n ;i++){
        if(dist[max_distance_index]<dist[i])
            max_distance_index = i;
    }
    // 거리 출력

    cout << dist[max_distance_index] <<endl;

    return 0;
}