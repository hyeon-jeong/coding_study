//해킹 - 다익스트라
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dist[10010]; //시작노드로부터 i번노드 까지의 거리값
int visit[10010]; // i번노드 에 방문했는지

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        //의존성 저장하는 인접행렬 비슷한거..(입력 & search)
        vector <pair <int, int> > computers[10001];
        //BFS용. 여기에 {소요시간(=거리), 노드번호} 넣을 예정 -> 그래야 걸리는 시간 순으로 먼저 정렬됨
        priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        //변수 선언(테스트케이스마다 변화)
        int n, d, c, a, b, s, cnt=1; // cnt 는 문제에서 요구한 감염된 컴퓨터 개수
        // 컴퓨터 개수, 의존성 개수, 해킹당한 컴퓨터 번호
        scanf("%d %d %d", &n, &d, &c);
        //N 개의 컴퓨터에 대한 행렬, 방문여부 행렬 세팅
        for(int i=1; i<=n; i++){
            dist[i] = 987654321; //시작노드로부터의 거리.일단 초기화. 최대값으로 치고
            visit[i] = 0; // 방문안한 상태
        }

        //노드 입력받기
        for(int i=0; i<d; i++){
            //cin >> a >> b >> s;
            scanf("%d %d %d", &a, &b, &s);
            //a 가 b 를 의존 == b 가 걸리면 a 가 걸림
            computers[b].push_back(make_pair(a, s));//이렇게 써야 전염된 경로를 그릴 수 있음
        }

        //BFS 하기 전에 큐에 시작노드 c 입력! - 세팅
        pq.push(make_pair(0,c));
        dist[c] = 0; 
        visit[c] = 1;

        //BFS 탐색 시작
        while(!pq.empty()){
            int now = pq.top().second; //탐색을 하는 기준노드
            int nowtime = pq.top().first; //now 노드까지 걸리는 시간
            pq.pop();//와.. 이걸 빼먹냐?

            for(int i=0; i<computers[now].size(); i++){
                int next = computers[now][i].first; //now 노드와 연결된 노드들 탐색중
                //새로운 경로에서 걸리는 시간
                int nexttime = nowtime + computers[now][i].second; // now ~ next 까지 걸리는 시간 -> 이 값이 제일 작아야 Dijkstra 만족
                if(dist[next] > nexttime){ //새로운 경로에서의 소요시간이 더 짧을 때 갱신
                    if(visit[next] == 0) cnt ++ ; //감염된 컴퓨터 +1
                    visit[next] = 1;
                    dist[next] = nexttime; //갱신
                    pq.push(make_pair(nexttime, next)); // 큐에 넣어줌 -> 경로 완성!
                }
            }
        }

        int totaltime=0; //값이 갱신된 개수. dist[i]를 이용해 알아낼 것! -> 경로가 만들어진 노드들만 값이 갱신됨
        for(int i=1; i<=n; i++){ //1번 부터 N 번까지 전체 노드 검사 -> 그 중 경로에 포함되면서 가장 값이 큰 경로비용 구하기
            if(dist[i] > totaltime && dist[i] != 987654321){
                totaltime = dist[i];
            }
        }
        //cout << cnt << totaltime << "\n";
        printf("%d %d\n", cnt, totaltime);
    }

    return 0;

}

/*매 tc 마다 시간(=거리) 구해줄 함수 - 이거 따로 빼고 싶은디... -> 이렇게 하고 싶은데 그럴려면 변수 사용시에 애매해지고 꼬일것 같다ㅠㅠ
void hacking(vector<pair <int, int> > &array){

    //총 감염되는 컴퓨터 수, 마지막 컴퓨터가 감염되기까지 걸리는 시간 출력
}
*/
