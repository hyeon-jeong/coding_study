// 2020_카카오_보석_쇼핑.cpp
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

// map의 성질을 최대한 이용해야 함
// map에서는 [] 연산자를 이용해 key에 해당하는 원소의 value에 쉽게 접근/수정할 수 있음
// map을 일종의 배열처럼 사용할 수 있음
// [] 연산자로 map에 없는 key를 참조할 경우, 자동으로 default 생성자를 호출해 원소를 추가해줌 (insert 대신 [] 사용 가능)
vector<int> solution(vector<string> gems) {
	vector<int> answer = {1, (int)gems.size()};
	map<string, int> m; // first: 보석 이름, second: 해당 보석의 개수
	set<string> s;

	for (int i = 0; i < gems.size(); i++) { // 보석들을 중복 없이 set에 저장
		s.insert(gems[i]);
	}
	int gem_list = s.size(); // 보석 종류 수
	s.clear(); // 이제 set은 필요 없으니까 clear

	int start = 0; // 시작점
	int end = 0; // 끝점
	int distance = gems.size(); // 최소 구간 길이
	while (true) {
		if (end == gems.size()) break; // 마지막 보석까지 탐색 끝나면 종료
		else if (m.size() == gem_list) { // 모든 종류의 보석이 map에 들어간 경우
			if (distance > end - start) { // distance 갱신
				distance = end - start;
				answer[0] = start + 1;
				answer[1] = end; // +1 안하는 이유는 밖의 else 때문..
			}
			if (m[gems[start]] > 1) { // 같은 보석이 2개 이상 있을 때
				m[gems[start]]--; // 해당 보석 개수 -1 감소시키고
				start++; // 시작 인덱스 +1
			}
			else if (m[gems[start]] == 1) { // 특정 보석이 1개밖에 없을 때
				m.erase(gems[start]); // map에서 해당 보석 제거하고
				start++; // 시작 인덱스 +1
			}
		}
		else { // 아직 모든 종류의 보석이 다 안들어갔을 때..
			if (m.find(gems[end]) == m.end()) { // 없는 보석이면 새로 원소 추가
				m.emplace(gems[end], 1);
			}
			else { // 이미 있는 보석이면 value가 +1 증가
				m[gems[end]] += 1;
			}
			end++; // 마지막 인덱스 +1
		}
	}

	return answer;
}


// 이건 망한 알고리즘..
// segmentation fault가 나서 ㅂㅂ...
/*
bool compare(const pair<string, int> &a, const pair<string, int> &b) {
	return a.second < b.second;
}

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	map<string, int> m;
	set<string> kind;
	vector<pair<string, int>> index;
	vector<pair<int, int>> length;

	for (int i = 0; i < gems.size(); i++) { // 보석 종류 kind set에 저장
		kind.insert(gems[i]);
	}

	int gem_list = kind.size();
	kind.clear();

	int distance = gems.size();
	for (int i = 0; i < gems.size(); i++) {
		if (m.find(gems[i]) != m.end()) {
			m.erase(gems[i]);
		}
		m.emplace(gems[i], i);
		if (m.size() == kind.size()) {
			map<string, int>::iterator it;
			for (it = m.begin(); it != m.end(); it++) {
				index.emplace_back(it->first, it->second);
			}
			sort(index.begin(), index.end(), compare);
			length.emplace_back(index[0].second, index[3].second);
		}
	}


	return answer;
}
*/
