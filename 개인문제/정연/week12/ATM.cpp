#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int p[1001];

int main(){
        cin >> N;
        for (int i = 0; i < N; i++)
                 cin >> p[i];
    
        sort(p, p+N);     

        int time = 0;
        for (int i = 0; i < N; i++)
                 for (int j = 0; j <= i; j++)
                         time += p[j];

        cout << time << endl;
        return 0;
}
