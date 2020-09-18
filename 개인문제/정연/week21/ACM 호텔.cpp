#include <iostream>
using namespace std;

int main(){
    int T,H,W,N;
    cin>>T;
    
    for (int i=0; i<T; i++){
        cin>>H>>W>>N;
        int acm_h = N % H;  // w=1부터 시작해서 같은 w 값을 갖는 방들에 대해 아래층부터 방이 배정되므로, 나머지 연산으로 층을 구한다.
        int acm_w = N/H + 1; 
        
        if (acm_h == 0){
            acm_h = H;
            acm_w--;
        }
        
        int ans = acm_h * 100 + acm_w;
        cout << ans << endl;
    }
    return 0;
}
