#include <cstdio>
using namespace std;

#define MAX 1000000
int stock[MAX];

int main(){
    int T,N;
    long long ans;
    scanf("%d", &T);
    
    while(T--){
        ans = 0;
        scanf("%d", &N);
        for (int i=0; i<N; i++){
            scanf("%d", &stock[i]);
        }
        
        int max = stock[N-1];
        for (int i=N-2; i>=0; i--){
            if (max > stock[i])
                ans += max - stock[i];
            else 
                max = stock[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
