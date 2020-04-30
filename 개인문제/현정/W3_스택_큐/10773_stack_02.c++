#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    stack <int> s;
    int sum = 0;
    int k;
    cin >> k;

    for (int i=0; i<k ; i++){
        int num;
        cin >> num;
        if(num == 0){
            int temp;
            temp = s.top();
            sum = sum - temp;
            s.pop();
        }
        else{
            s.push(num);
            sum = sum + num;
        }
    }
    cout << sum << "\n";

    return 0;
}