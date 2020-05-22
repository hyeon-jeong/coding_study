#include <iostream>

using namespace std;
/*
int count_0[41];
int count_1[41];

void count(int num){
    if (num == 0){
        count_0[0] = 1;
        count_1[0] = 0;
    }
    else if(num == 1){
        count_0[1] = 0;
        count_1[1] = 1;
    }
    else{
        count_0[num] = count_0[num-1] + count_0[num-2];
        count_1[num] = count_1[num-1] + count_1[num-2];
    }

}


int main(){
    int t, temp;
    cin >> t;

    for(int i=0; i<t ; i++){
        cin >> temp;
        count(temp);
        cout << count_0[temp] << count_1[temp] << "\n";
    }
    
    return 0;
}

*/

int cnt[41][2] = {{1,0}, {0,1}};
int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        for (int i=2; i<=n; i++){
            cnt[i][0] = cnt[i-1][0] + cnt[i-2][0];
            cnt[i][1] = cnt[i-1][1] + cnt[i-2][1];
        }

        cout << cnt[n][0] << ' ' << cnt[n][1] << '\n';
    }

    return 0;
}