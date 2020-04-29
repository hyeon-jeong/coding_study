//처음 쓴 코드

#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map <long, long> room;

long long reservation(long long room_num){
    if (room[room_num] == 0){
        room[room_num] = 1;
        return room_num;
    }
    return reservation(room_num + 1);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    long long room_num, booking;
    
    for (int i=0; i<room_number.size(); i++){
        room_num = room_number[i];
        booking = reservation(room_num);
        answer.push_back(booking);
    }
    
    return answer;
}

// 하지만 이 코드는 채점했을 때 효율성 테스트에서 전부 timeout이 발생한다. 검색해보니 내가 기존에 작성한 코드와 유사한 알고리즘이 Union find 인데, 
// 이 경우 최적화를 통해 시간 복잡도를 줄일 수 있다고 해서 해당 부분을 반영했더니 통과되었다.

#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map <long, long> room;

long long reservation(long long room_num){
    if (room[room_num] == 0)
        return room_num;
    return room[room_num] = reservation(room[room_num]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    long long room_num, booking;
    
    for (int i=0; i<room_number.size(); i++){
        room_num = room_number[i];
        booking = reservation(room_num);
        answer.push_back(booking);
        room[booking] = booking + 1;
    } 
    return answer;
}
