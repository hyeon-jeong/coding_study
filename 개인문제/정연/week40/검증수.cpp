#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
int main()
{
	int num;
	int result = 0;
 
	for (int i = 0; i < 5; ++i) {
		cin >> num;
		result += num * num;
	}
	
	result = result % 10;
 
	cout << result << endl;
 
	return 0;
}
