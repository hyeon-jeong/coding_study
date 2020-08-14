// 2019_카카오_무지의_먹방라이브.cpp
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>


struct food {
	int num; // 음식 번호
	long long time; // 음식 먹는데 걸리는 시간
};

bool time_less(food a, food b) { // 시간 내림차순 정렬 함수
	return a.time > b.time;
}

bool num_greater(food a, food b) { // 인덱스 오름차순 정렬 함수
	return a.num < b.num;
}

int solution(vector<int> food_times, long long k) {
	int answer = 0;
	int food_size = food_times.size();
	vector<food> vec;

	long long sum = 0;
	for (int i = 0; i < food_size; i++) {
		food temp;
		temp.num = i + 1, temp.time = food_times[i];
		vec.push_back(temp);
		sum += food_times[i];
	}

	long long before = 0;
	sort(vec.begin(), vec.end(), time_less); // 시간 내림차순으로 정렬
	// 벡터의 맨 끝 부분 원소가 시간이 최소임

	if (sum <= k) return -1; // k초 안에 다 먹을 수 있는 경우 -1 출력
	else { // k초 안에 다 못먹는 경우
		while (true) {
			food_size = vec.size(); // 벡터 길이
			int min_index = food_size - 1; // 마지막 인덱스
			if (k >= (vec[min_index].time - before) * food_size) {
				k -= (vec[min_index].time - before) * food_size; // 제일 시간이 짧은 음식을 다 먹은 시간을 모든 음식에 대해 빼줌
				before = vec[min_index].time; // 직전 음식을 다 먹는데 걸리는 시간
				vec.pop_back();
			}
			else break;
		}
		sort(vec.begin(), vec.end(), num_greater); // 인덱스 오름차순으로 정렬
		int end = k % vec.size();
		answer = vec[end].num;
	}

	return answer;
}


/*
// 효율성 시간초과
int solution(vector<int> food_times, long long k) {
	int food_num = food_times.size();
	int idx = 0;

	long long sum = 0;
	for (int i = 0; i < food_num; i++) {
		sum += food_times[i];
	}
	if (sum <= k) return -1;

	while (true) {
		if (idx >= food_num) idx = 0;
		if (food_times[idx] == 0) {
			idx += 1;
			continue;
		}
		if (k > 0) {
			food_times[idx] -= 1;
			k -= 1;
			idx += 1;
			continue;
		}
		if (k == 0) {
			return idx + 1;
		}
	}
}
*/

/* [6, 5, 4], k = 15일 때,
제일 시간이 작은 수 = 4
해당 음식을 다 먹을 때까지 걸리는 시간 = 4 * 3 = 12
[6, 5, 4] -> [2, 1, 0]
그 다음 음식(6초짜리)을 다 먹는데 걸리는 시간 = [6(현재 음식) - 4(이전 음식)] * 2(남은 음식 개수) = 4
하지만 남은 k는 3초이므로 k % 남은 음식 개수
*/
