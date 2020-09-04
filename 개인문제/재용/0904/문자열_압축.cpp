// 2020_카카오_문자열_압축
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

int partition(string s, int len) { // len = 자르는 문자 개수
	string start = s.substr(0, len);
	string zip = "";
	int same = 1; // 같은 substring 개수

	for (int i = len; i < s.size(); i+=len) {
		string word = s.substr(i, len);
		if (start == word) same += 1;
		else {
			if (same > 1) zip += to_string(same);
			zip += start;

			// 초기화
			start = word;
			same = 1;
		}
	}

	// 마지막 substring도 append 해줌
	if (same > 1) zip += to_string(same);
	zip += start;

	return zip.size();
}

int solution(string s) {
	int answer = s.size();

	for (int i = 1; i <= s.size() / 2; i++) {
		answer = min(answer, partition(s, i));
	}

	return answer;
}
