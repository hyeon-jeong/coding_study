#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector <int> times;
    int N, t;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> t;
        times.push_back(t);
    }
    sort(times.begin(), times.end());
    int sum=0;
    for(int i=0; i<N; i++){
        int person=0;
        for(int j=0; j<=i; j++){
            //cout << "times : " << times[j];
            person += times[j];
        }
        //cout << "person : "<<person << "\n";
        sum += person;
    }
    cout << sum;
    return 0;
}