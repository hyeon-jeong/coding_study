#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
 
int main()
{
	int station[5][3];
	int maxPeople = -1;
 
	memset(station, 0, sizeof(station));
 
	for (int i = 1; i <= 4; ++i) {
		cin >> station[i][0];
		cin >> station[i][1];
		station[i][2] = station[i][1] - station[i][0] + station[i - 1][2];
		maxPeople = max(maxPeople, station[i][2]);
	}
 
	cout << maxPeople << endl;
 
	return 0;
}
