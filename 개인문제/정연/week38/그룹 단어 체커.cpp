#include <iostream>
using namespace std;

int main(){	
	int n;
	int ans = 0;
	string str;
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> str;
		bool flag = true;
		
		for(int j=0; j<str.length(); j++){
			for(int k=0; k<j; k++){
				if(str[j] != str[j-1] && str[j] == str[k]){
					flag = false;
					break;			
				}				
			}
		}
		if(flag) 
      ans++;
	}
	cout << ans;
  return 0;
}
