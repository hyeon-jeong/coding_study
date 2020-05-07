#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    // 문제 조건에서 n 이 90까지 주어지는데, 그렇게 되면 int 범위를 넘는다고 함.
    vector <long long> vec;

    vec.push_back(0);
    vec.push_back(1);
     
    for (int i=2; i<= n; i++){
        vec.push_back(vec[i-2]+vec[i-1]);
    }

    cout << vec[n] << "\n";
    
}