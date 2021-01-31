#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<pair<int, int>, int>> v;  

void printOrder(){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                 if (i == j)
                     continue;

                 else if (v[i].first.first < v[j].first.first && v[i].first.second < v[j].first.second)
                     v[i].second++;
             }
         }

        for (int i = 0; i < N; i++)
             cout << v[i].second << " ";
        cout << endl;
}

 

int main(void){
        cin >> N;

        for (int i = 0; i < N; i++){
            int x, y;
            cin >> x >> y;
            v.push_back(make_pair(make_pair(x, y), 1));
        }
        printOrder();
        return 0;
}
