#include <string>
#include <vector>
#include <map>

using namespace std;


long long find_room(vector <long long> rooms, long long number){
    if(rooms[number] == 0)
        return number;
    else
        return find_room(rooms, rooms[number]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    vector <long long> rooms(k);
    
    for (int i=0; i<room_number.size(); i++){
        long long empty = find_room(rooms, room_number[i]);
        answer.push_back(empty);
        rooms[empty] = empty+1; // 다음 empty 노드(=옆 index)로 탐색(링크드 리스트..?)
    }
    return answer;
}