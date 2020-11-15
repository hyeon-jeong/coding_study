#include <iostream>
using namespace std;

int main() {
    int num, min = 100, sum = 0, cnt = 0;
    for (int i = 0; i < 7; i++){
        cin >> num;
        if (num % 2 == 1){
            cnt++;
            sum += num;
            if (min > num)
                min = nun;
        }
    }
    if (cnt == 0)
        cout << "-1"<<'\n';
        
    else
        cout << sum << '\n' << min << '\n';
    
    return 0;
}
