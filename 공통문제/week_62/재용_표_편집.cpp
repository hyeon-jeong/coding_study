// 프로그래머스 : 2021 카카오 채용연계형 인턴십 - 표_편집.cpp
/* 선행, 후행 연산자 주의!! 이 순서에 따라 시간초과 여부가 갈림 */
#include <string>
#include <vector>
#include <set>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
	string answer = "";

	/* 표 초기화 */
	set<int> graph;
	for (int i = 0; i < n; i++) graph.insert(i);

	// 삭제된 행
	stack<int> deleted;

	// 현재 선택된 행(원소)
	set<int>::iterator select, temp;
	select = graph.begin();
	while (k--) select++;

	for (auto c : cmd) {
		// 아래로 이동
		if (c[0] == 'D') {
			int value = stoi(c.substr(2));
			while (value--) ++select;
		}
		// 위로 이동
		else if (c[0] == 'U') {
			int value = stoi(c.substr(2));
			while (value--) --select;
		}
		// 현재 행 삭제 후 아래 행 선택
		else if (c[0] == 'C') {
			// 삭제된 행 저장
			deleted.push(*select);
			temp = select; 
			temp++; // 삭제된 행의 아래 행
			// 삭제된 행이 마지막 행인 경우
			if (temp == graph.end()) {
				temp = select;
				--temp; // 바로 위 행 선택
			}
			graph.erase(select); // 삭제
			select = temp; // 선택
		}
		// 가장 최근에 삭제된 행 복구
		else if (c[0] == 'Z') {
			int recover = deleted.top();
			deleted.pop();
			graph.insert(recover);
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (graph.find(i) != graph.end()) {
			answer += 'O';
		}
		else answer += 'X';
	}

	return answer;
}
