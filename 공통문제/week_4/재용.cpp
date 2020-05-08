// 프로그래머스_기지국_설치.cpp
#include <iostream>
using namespace std;
#include <vector>


int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int length = 2 * w + 1; // 전파 범위
	int location = 1; // 현재 위치
	int i = 0; // stations의 index
	
	/* index i의 범위를 꼭 지정해줘야 함. 안그러면 test 2에서 에러 발생..ㅠ */
	while (location <= n) {
		if (i < stations.size() && location >= (stations[i] - w)){ // 현재 위치가 전파 범위 안에 있을 때
			location = stations[i] + w + 1; // 범위 밖으로 location 이동
			i++; // 다음 station으로 이동
		}
		else { // 현재 위치가 전파 범위 밖에 있을 때 or 전파 범위 내이지만 다음 station이 없을 때
			answer++; // 기지국 설치하고
			location += length; // 현재 위치를 전파범위 밖만큼 이동시킴
		}
	}

	return answer;
}
