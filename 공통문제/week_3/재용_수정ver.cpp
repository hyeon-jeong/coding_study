// 2019_카카오_호텔_방_배정.cpp
// Union-Find 알고리즘
#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>

/* 현재 방의 바로 다음 빈 방을 저장하는 map */
/* value가 0이면 현재 방이 비어있다는 뜻 */
map<long long, long long> rooms; // 초기값 = 0

long long reservation(long long room_number) {
	if (rooms[room_number] == 0) { // 방이 비어있으면
		return room_number; // 해당 방 번호 리턴
	}
	/* 방이 이미 예약된 경우 */
	else {
		rooms[room_number] = reservation(rooms[room_number]); // 비어있는 다음 방을 찾아서 리턴
		return rooms[room_number];
	}
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	for (long long i = 0; i < room_number.size(); i++) {
		long long empty = reservation(room_number[i]); // 빈 방 찾음
		answer.push_back(reservation(room_number[i])); // 방 예약
		rooms[empty] = empty + 1; // 해당 방이 예약되었으므로 바로 다음 빈 방 번호를 저장
	}
	
	return answer;
}

/* 예를 들어, 1번 방만 차있다고 가정하면, rooms[1] = 2이다.
그 다음 손님이 1번 방을 원했을 때, rooms[1]은 0이 아닌 2이므로, reservation(rooms[1]), 즉 reservation(2)를 수행한다.
rooms[2] = 0이기 때문에 reservation(2)의 반환값은 2가 된다. 이렇게 2번 방도 예약되면, rooms[2] = 3으로 갱신한다.  */