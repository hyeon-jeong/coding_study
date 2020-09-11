#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef pair<int, int> p;
vector<p> room;
 
bool compare(p a, p b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}
 
int main() {
    int N;
    cin >> N;
    
    int start, end;
    for(int i = 0; i < N; i++){
        cin >> start >> end
        room.push_back(make_pair(start, end));
    }
    sort(room.begin(), room.end(), compare);
    
    int timetable = room[0].second;
    int ans = 1;
    for(int i = 1; i < N; i++){
        if(timetable <= room[i].first){
            ans++;
            timetable = room[i].second;
        }
    }
    cout << ans << '\n';    
    return 0;
}
