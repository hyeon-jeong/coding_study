#include <iostream>
#define MAX_SIZE 6
using namespace std;

int lotto[MAX_SIZE];
int candidate[13];
int k;

void dfs(int candid, int lot){
    if(lot == MAX_SIZE){
        for(int i=0; i<MAX_SIZE; i++)
            cout<<lotto[i]<<' ';
        cout<<endl;
        return;
    }
    
    for(int i=candid; i<k; i++){
        lotto[lot] = candidate[i];
        dfs(i+1, lot+1);
    }
}

int main(){
        while(1){
        cin>>k;
        if(k == 0)
            break;
    
        for(int i=0; i<k; i++)
            cin>>candidate[i];
    
        dfs(0, 0);
        cout<<endl;
    }
    return 0;
}
