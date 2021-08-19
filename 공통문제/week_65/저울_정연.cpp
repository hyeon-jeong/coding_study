#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    vector<int> weight;
    cin>>n;
    
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        weight.push_back(tmp);
    }
    sort(weight.begin(), weight.end());
    
    if(weight[0] != 1)
        cout<<1;
        
    else{
        int sum = 0;
        for(int i=0; i<n; i++){
            if(weight[i] > sum+1)
                break;
            sum += weight[i];
        }
        cout<<sum+1;
    }
    
    return 0;
}
