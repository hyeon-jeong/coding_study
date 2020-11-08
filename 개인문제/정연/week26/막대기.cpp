#include <iostream>
using namespace std;
 
int main() {
    int X;
    int len = 64;
    int bar = 0;
    
    cin>>X;
    while(X > 0){
        if(len > X)
            len = len / 2;
        else{
            X -= len;
            bar++;
        }
    }
  
    cout<<bar<<endl;
    return 0;
}
