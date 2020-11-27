#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	stack<char> s;
	int T;
	cin >> T;

	for (int i = 0; i < T; i++){
		string vps;
		cin >> vps;
		for (int j = 0; j < vps.length(); j++){
			if (vps[j] == '(' || s.empty()) 
        s.push(vps[j]);
			else if(s.top() == '(')
        s.pop();
		}

		if (s.empty()) 
      cout << "YES" << endl; 
		else 
      cout << "NO" << endl;
		while (!s.empty()) 
      s.pop();
	}
}
