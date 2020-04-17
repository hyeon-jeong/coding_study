#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector <int> numbers;

void backtracking(int index, int sp){
    if(index== m){
        for(int j=0; j<m; j++)
            cout << numbers[j] << " ";
        cout << "\n";
        return;
    }

    for(int j=sp; j<=n; j++){
        numbers.push_back(j);
        backtracking(index+1, j);
        numbers.pop_back();
    }
}

int main(){
    cin >> n >> m;
    backtracking(0,1);
    return 0;
}