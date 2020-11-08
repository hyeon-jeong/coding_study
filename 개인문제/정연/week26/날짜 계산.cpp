#include <iostream>
using namespace std;

int main(){
    int E,S,M;
    cin>>E>>S>>M;
    
    int year = 1;
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        if ((year-E)%15 == 0 && (year-S)%28 == 0 && (year-M)%19 == 0)
            break;
        year++;
    }
    cout<<year<<endl;
    return 0;
}
