//절댓값 힙
#include <iostream>
#include <queue>
#include <functional>

using namespace std;
//pq 사용법? data type, container type, 정렬기준 <- 여기서는 최소힙 써야해서 greater 붙여줌
priority_queue<pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > pq;
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int N, num;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> num;
        if(num){
            //{절댓값, 실제값} 쌍을 우선순위 큐에 삽입 -> 먼저 절댓값으로 정렬, 그다음에 실제값으로 정렬할 것!
            pq.push(make_pair(abs(num), num));
        }
        else{
            if(pq.empty()){
                cout << 0 << "\n";
            }
            else{
                cout << pq.top().second << "\n";
                pq.pop();
            }
        }
    }
    return 0;
}