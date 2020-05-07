#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = ((n - stations.size()) / (1 + 2*w));
    return answer;
}
// 문제 보자마자 3분만에 막 짜본 코드. 의외로 정확성 테스트는 절반 넘게 통과한다ㅋㅋ


#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int idx = 0, answer = 0;
    
    for (int i=1; i<=n; i++){
        if (i < stations[idx] - w || i > stations[idx] + w){
            i += 2*w;
            answer++;
        }
        else{
            i = stations[idx] + w; // 처음에 이 부분을 i += w로 했는데 정확성 테스트의 일부와 효율성 테스트의 전부에서 오답이 되었다.
            // x += y 와 x = x + y의 차이인데, 실행 시간 자체는 전자가 더 짧은 것으로 알고 있는데 왜 이 문제에서는 시간초과가 되는지 모르겠다
            idx++;
        }
    }
    return answer;
}
