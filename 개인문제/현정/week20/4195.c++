//정답코드
#include <iostream>
#include <map>
#include <cstring>

using namespace std;
int parent[200001];
int cnt[200001];

int find(int x){
    return parent[x]==x ? x: parent[x] = find(parent[x]);
}

int merge(int x1, int x2){
    x1 = find(x1); x2 = find(x2);
    if(x1 != x2){
        parent[x2] = x1;
        cnt[x1] += cnt[x2];
        cnt[x2] = 1; //솔직히 왜 하는지 이해 안됨.
    }
    return cnt[x1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int F, N;
    cin >> F;
    while(F--){
        //초기화
        map <string, int> m;
        int num=1;
        cin >> N; //사람수
        //union-find 기본세팅
        for(int i=0; i<2*N; i++){
            cnt[i] = 1; //친구관계는 자기자신뿐.
            parent[i] = i; //루트 = 자기자신
        }
        //map 에 삽입, 처음 들어오는 사람이라면 count = 1;
        string s1, s2;
        for(int i=0; i<N; i++){
            cin >> s1 >> s2;
            //이거 진짜 왜 하는지 모르겠다....
            if(m.count(s1)==0) m[s1] = num++;
            if(m.count(s2)==0) m[s2] = num++;
            cout << merge(m[s1], m[s2]) << "\n";
        }
    }    

}