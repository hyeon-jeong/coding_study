// 2019_카카오_호텔_방_배정.cpp
#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>

map<long long, long long> rooms; // 초기값 = 0

long long reservation(long long room_number) { // 방번호 배정
	if (rooms[room_number] == 0) {
		rooms[room_number] = 1;
		return room_number;
	}
	else {
		return room_number = reservation(room_number + 1);
	}
}

vector<long long> solution(long long k, vector<long long> room_number) {
	long long i;
	vector<long long> answer;
	
	for (i = 0; i < room_number.size(); i++) {
		answer.push_back(reservation(room_number[i]));
	}
	
	return answer;
}