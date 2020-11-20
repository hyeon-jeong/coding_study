// 2020_카카오 : 가사검색.cpp
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	for (int q = 0; q < queries.size(); q++) {
		string query = queries[q];

		bool flag = true;
		set<string> result;
		for (int w = 0; w < words.size(); w++) {
			string word = words[w];
			if (word.length() != query.length()) continue;
			for (int i = 0; i < query.length(); i++) {
				if (query[i] == '?') continue;
				if (query[i] != word[i]) {
					flag = false;
					break;
				}
			}
			if (!flag) {
				flag = true;
				continue;
			}
			else {
				result.insert(word);
			}
		}
		answer.push_back(result.size());
	}

	return answer;
}
