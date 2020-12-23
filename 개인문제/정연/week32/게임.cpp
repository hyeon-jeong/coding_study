#include <iostream>
#define MAXVAL 1000000000
using namespace std;

int main(){
    long long x,y,z;
    cin>>x>>y;
    z = (100*y)/x;
    
    if (z>=99){
        cout<<-1<<endl;
        return 0;
    }
    
    int low=0, high=MAXVAL;
    int game = -1;
    while (low <= high){
        int mid = (low + high) / 2;
        int newZ = (100 * (y + mid)) / (x + mid);
        if (z >= newZ){
            game = mid + 1;
            low = mid + 1;
        }
        else
              high = mid - 1;
    }
        cout << game << "\n";
    
    return 0;
}
