#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int> card;
vector<int> num;

int binary_search(int key){
    int start=0;
    int end=card.size()-1;
    int mid=(start+end)/2;
    
    while(start <= end){
        if(card[mid] == key)
            return 1;
     
        if(key < card[mid])
            end = mid-1;
        
        if(card[mid] < key)
            start = mid+1;
        
        mid=(start+end)/2;        
    }
    
    return 0;
}
int main() {  
    std::ios_base::sync_with_stdio(false);
    
    cin>>N;
    card = vector<int> (N,0);
    for(int i=0;i<N;i++)
        cin>>card[i];
    
    cin>>M;
    num = vector<int> (M,0);
    for(int i=0;i<M;i++)
        cin>>num[i];
    
    sort(card.begin(),card.end());
    
    for(int i=0;i<M;i++){
        cout<<binary_search(num[i])<<" ";
    }
    return 0;
}
