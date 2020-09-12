#include <iostream>
#include <vector>
#include <cstring> //memset 때문에...

using namespace std;
int stocks[1000001]; // 설마 이게 문제일까...?
int T, N;

long long dfs(int start){
    //재귀적 함수이기때문에, 초기화 꼭 해주자...(오류 방지)
    long long result=0;
    int MAX = 0; int point=0;
    for(int i=start; i<N; i++){ //주가가 최대일때 탐색
        if(stocks[i] >= MAX){
            MAX = stocks[i];
            point = i; // 최대값일때의 날짜 저장
        }
    }
    //주가가 최대일때 팔기 - MAX 일때 가치.
    for(int i=start; i<point; i++){ //start 부터 파는게 시작. 잊지 말아줘유~~~ -> DFS 진행할때 중요한 부분.
        result += (MAX-stocks[i]);
    }

    //팔고 난 이후, 남은 날 중 최대값 찾고 더해야 함.(DFS)
    if(point<N-1) result += dfs(point+1); //point+1 인 이유는, point 일때는 팔아야 하기 때문. 그 이후에 행동가능.

    return result;
}

int main(){
    ios_base :: sync_with_stdio(false); //시간단축.    
    scanf("%d", &T);
    while(T--){
        memset(stocks, 0, sizeof(stocks));
        scanf("%d", &N);
        for(int i=0; i<N; i++){
            scanf("%d", &stocks[i]);
        }
        long long answer = dfs(0);
        printf("%lld\n", answer);
    }
}


















/* 시간초과 발생 - Greedy...
//사지는 않음..!
long long greedy(int n){
    int result=0, profit=0;
    MAX = 0;
    for(int i=n-1; i>=0; i--){
        if(stocks[i] > MAX) MAX=stocks[i]; //주가 감소할때. 시간순 : stocks[i], MAX -> 따라서 가만히 있는 것이 좋음.
        else {
            profit = MAX - stocks[i]; // 주가 증가할때. 따라서, 파는 것이 좋음.
            result += profit;
        }
    }
    return result; 
}

int main(){
    int T;
    scanf("%d", &T);

    for(int i=0; i<T; i++){
        int N;
        scanf("%d", &N);
        memset(stocks, 0, sizeof(stocks));
        for(int j=0; j<N; j++){
            scanf("%d", &stocks[j]);
        }
        long long result = greedy(N);
        printf("%d\n", result);
    }

}
*/