#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>

using namespace std;
int n,m, a, b;
vector <int> problems[32010];
int cnt[100001]; //호출되는 횟수(b) -> 이중에서 a값이 제일 작은 것 부터 방문!
priority_queue <int> pq;

 int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        problems[a].push_back(b); //입력받은대로 문제쌍 넣어줌
        cnt[b]++; //(a,b) 중 b 의 개수 세기
    }
    for(int i=1; i<=n; i++){
        if(cnt[i] == 0) pq.push(i); //참조되지 않는 것부터 먼저 pq에...?
    }
    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        printf("%d\n", cur);//pq 순서대로 출력(=top 부터)
        //cur 와 연결된 문제들 전부 탐색
        for(int i=0; i<problems[cur].size(); i++){
        cnt[problems[cur][i]]--; //솔직히 이 부분 이해 못하겠음.왜?
        if(cnt[problems[cur][i]] == 0) pq.push(problems[cur][i]); 
        //왜 b 가 제일 적게 참조되는것의 문제쌍(a,b) 부터 우선순위큐에 넣을까?
        }
    }
    return 0;
 }