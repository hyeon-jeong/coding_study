#include <iostream>
using namespace std;

int main(){
    int N,ans;
    cin>>N;
    
   while (N>0){
       if (N % 5 == 0){
           ans += N/5;
           N = N % 5;
       }
        
       else{
           N = N -3;
           ans++;
           if (N < 3 && N != 0){
               cout<<-1;
               return 0;
           }
        }
   }
    cout<<ans;
    return 0;
}
