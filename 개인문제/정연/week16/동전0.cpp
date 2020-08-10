#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    
    vector<int> value(n,0);
    
    for(int i=0; i<n; i++)
        scanf("%d", &value[i]);
    
    int ans=0;
    for(int i=n-1; i>=0; i--){
        if(k == 0)
            break;
        else if(value[i] > k)
            continue;
        
        ans += k/value[i];
        k %= value[i];
    }
    cout<<ans<<endl;
    return 0;
}
