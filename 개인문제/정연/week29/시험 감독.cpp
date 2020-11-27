#include<iostream>
#include<cstdio>
 
using namespace std;
 
int main(){
 
    int n, arr[100001], general, assistant;
    long long ans=0;
    
    cin >> n;
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    cin >> general >> assistant;
 
    for(int i=0; i<n; i++){
        arr[i] -= general;   
        ans++;
 
        if(arr[i] > 0) {
            if(arr[i] % assistant == 0) 
                ans += (arr[i] / assistant);
            else
                ans += (arr[i] / assistant)+1;
        }
    }
    cout << ans;
    return 0;
}
