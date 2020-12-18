// 17135_캐슬_디펜스.cpp
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <cmath>
#include <set>
using namespace std;
#define MAX 15

int n, m; // 좌표 크기
int D; // 사정거리
int map[MAX][MAX] = { 0, };
bool flag[MAX][MAX] = { false, };
vector<pair<int, int>> enemies; // 적 위치
vector<int> archors; // 궁수 위치. 행은 어차피 같으니까 열 번호만 저장

int distance(int ax, int ay, int ex, int ey) {
	int D = abs(ax - ex) + abs(ay - ey);
	return D;
}

int main() {
	scanf("%d %d %d", &n, &m, &D);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) { // 적의 위치 저장
				enemies.push_back({ i, j });
			}
		}
	}

	/* 
		next_permutation을 위한 궁수 위치 경우의 수: 0000000...111
	*/
	for (int i = 0; i < m - 3; i++) archors.push_back(0);
	for (int i = 0; i < 3; i++) archors.push_back(1);
	
	int result = 0; // 최대 적의 수

	do { // next_permutation
		/* 적의 위치 복사 */
		vector<pair<int, int>> temp = enemies;

		/* 궁수 위치 저장 (경우의 수) */
		vector<int> archorLoc;
		for (int i = 0; i < archors.size(); i++) {
			if (archors[i] == 1) archorLoc.push_back(i);
		}
		
		int killed = 0; // 죽인 적의 수
		while (!temp.empty()) {
			int ax = n; // 궁수의 x좌표
			set<int> target; // 죽일 적 위치(vector index) 저장

			for (int i = 0; i < archorLoc.size(); i++) {
				int ay = archorLoc[i]; // 궁수의 y좌표
				int idx = 0; // target
				int ey = temp[0].second; // 더 왼쪽인지 확인하기 위한 적의 y좌표
				int dist = distance(ax, ay, temp[0].first, temp[0].second);

				for (int j = 1; j < temp.size(); j++) {
					int tempDist = distance(ax, ay, temp[j].first, temp[j].second);
					// 더 가까운 적 발견
					if (dist > tempDist) { 
						ey = temp[j].second;
						dist = tempDist;
						idx = j;
					}
					// 거리가 같을 때 더 왼쪽에 있는 적
					else if (dist == tempDist && ey > temp[j].second) {
						ey = temp[j].second;
						idx = j;
					}
				}

				// 사정거리 내면 target에 추가
				if (dist <= D) target.insert(idx);
			}

			/* 적을 죽이기 */
			int subSize = 0;
			for (auto &t : target) {
				// 원소 한개가 지워지면 인덱스가 하나씩 앞으로 땡겨짐
				temp.erase(temp.begin() + (t - subSize++));
				killed++;
			}

			if (temp.empty()) break;

			/* 적이 앞으로 한칸 전진 */
			vector<pair<int, int>> copy;
			for (int i = 0; i < temp.size(); i++) {
				if (temp[i].first < n - 1) { // (n - 1)번째 행에 있는 적은 사라짐
					copy.push_back({ temp[i].first + 1, temp[i].second });
				}
			}
			temp = copy;
		}

		result = max(result, killed);
	} while (next_permutation(archors.begin(), archors.end()));


	printf("%d\n", result);
	return 0;
}
