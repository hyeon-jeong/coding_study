#include <iostream>

using namespace std;

int n,r,c,cnt;

void search(int len, int y, int x){
    if (len == 2){
        if (y == r && x == c){
            cout << cnt << "\n";
            return;
        }
        cnt++;
        
        if (y == r && x+1 == c){
            cout << cnt << "\n";
            return;
        }
        cnt++;
        
        if (y+1 == r && x == c){
            cout << cnt << "\n";
            return;
        }
        cnt++;
        
        if (y+1 == r && x+1 == c){
            cout << cnt << "\n";
            return;
        }
        cnt++;
        return;
    }
    
    search(len/2, y, x);
    search(len/2, y, x + len/2);
    search(len/2, y + len/2, x);
    search(len/2, y + len/2, x + len/2);    
}

int main(){
    cin>>n>>r>>c;
    search(1<<n,0,0); // pow 보다 비트 연산자를 쓰는 것이 효율적이라고 한다.
    
    return 0;
}
