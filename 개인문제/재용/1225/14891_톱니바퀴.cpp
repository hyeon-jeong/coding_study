// 14891_톱니바퀴.cpp
#include <iostream>
using namespace std;
#include <vector>

int gear[4][8];

void rotate(int gear_num, int dir) {
	int temp[8];
	if (dir == 1) { // 시계방향
		for (int i = 0; i < 8; i++) {
			temp[(i + 1) % 8] = gear[gear_num][i];
		}
	}
	else { // 반시계방향
		for (int i = 0; i < 8; i++) {
			temp[i] = gear[gear_num][(i + 1) % 8];
		}
	}
	
	/* temp를 gear에 복사 */
	for (int i = 0; i < 8; i++) {
		gear[gear_num][i] = temp[i];
	}
}

int main() {
	/* N극은 0, S극은 1 */
	for (int i = 0; i < 4; i++) {
		for (int d = 0; d < 8; d++) {
			scanf("%1d", &gear[i][d]);
		}
	}

	int k; // 회전 횟수
	scanf("%d", &k); 
	/* 시계방향은 1, 반시계방향은 -1 */
	for (int i = 0; i < k; i++) {
		int gear_num, d;
		scanf("%d %d", &gear_num, &d);
		gear_num--; // 톱니바퀴 번호는 0부터 시작

		int dir[4] = { 0, }; // 각 톱니바퀴의 회전방향
		dir[gear_num] = d;
		for (int i = gear_num; i < 3; i++) { // 현재 톱니바퀴로부터 오른쪽
			if (gear[i][2] != gear[i + 1][6]) dir[i + 1] = -dir[i];
		}
		for (int i = gear_num; i > 0; i--) { // 현재 톱니바퀴로부터 왼쪽
			if (gear[i][6] != gear[i - 1][2]) dir[i - 1] = -dir[i];
		}

		for (int i = 0; i < 4; i++) {
			if (dir[i] != 0) {
				rotate(i, dir[i]);
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < 4; i++) {
		if (gear[i][0] == 1) { // 12시방향이 S극이면
			answer += (1 << i);
		}
	}

	printf("%d\n", answer);
	return 0;
}

