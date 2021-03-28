#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n; 
    cin>>n;
    
    int arr[10] = {0,};
    while(n>=10){
        arr[n%10]++;
        n /= 10;
    }
    
    int ans;
    for(int i=0; i<n; i++){
        if(i == 6 || i == 9){
            ans = max(ans, (arr[6] + arr[9] + 1)/2);
        }
        else
            ans = max(ans, arr[i]);
    }
    
    cout<<ans<<endl;
}
