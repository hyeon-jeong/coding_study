#include <iostream>
using namespace std;

int main()
{
    int N, gen, sum;
    cin>>N;
    
    for (int i=1; i<N; i++){
        gen = i;
        sum = i;
        
        while(gen){
            sum += gen%10;
            gen /= 10;
        }
        
        if(N == sum){
            cout << i << endl;
            return 0;
        }
    }
    
    cout << "0" << endl;
    return 0;
}
