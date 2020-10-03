//정렬을 사용해서 평범하게 풀기.
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm> //sort 써야하니까~~~

using namespace std;

char input[11];
int t, n;
vector <string> v;
int flag; //중복되는지, 아닌지!

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        flag = 0;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> input; //문자열을 이렇게 '문자 배열'로 받을 수 있구나~~!!!
            v.push_back(input);
        }
        //정렬!
        sort(v.begin(), v.end()); //cstring header 필수, begin() 과 end()여야 한다. front() 이딴거 안됨.
        for(int i=0; i<n-1; i++){
            if(v[i].length() >= v[i+1].length()) continue; //앞에 정렬한 단어가 더 길거나, 길이가 같다면? 그냥 넘어감. 왜냐구? sort 하니까!
            if(v[i+1].substr(0, v[i].length()) == v[i]) { //앞에 위치한 단어가 더 짧을 때, 뒤의 단어에 포함되는 경우!??
                //cout << "v[i+1]:" << v[i+1] << " v[i]: " << v[i] << endl;
                cout << "NO\n";
                flag=1;
                break;
            }
        }
        if(flag==0) cout << "YES\n";
        v.clear();
    }
    return 0;
}