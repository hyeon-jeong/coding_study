#include <string>
#include <vector>
#include <queue>
using namespace std;

int adv[360000];

int str_to_time(string str){
	int ans=0;

	string h = str.substr(0,2);
	string m = str.substr(3,2);
	string s = str.substr(6,2);

	ans+=stoi(h)*3600;
	ans+=stoi(m)*60;
	ans+=stoi(s);
  
	return ans;
}

string time_to_str(int n){
	string ans="";

 	int s = n%60; n/=60;
	int m = n%60; n/=60;
	int h = n;

	if(h<10) 
    ans+="0";
	ans+=to_string(h);
	ans+=":";

	if(m<10) 
    ans+="0";
	ans+=to_string(m);
	ans+=":";

	if(s<10) 
    ans+="0";
	ans+=to_string(s);

    return ans;
}

string solution(string play_time, string adv_time, vector<string> logs) {
	string answer = "";

	for(string s:logs){
		int start = str_to_time(s.substr(0,8));
		int finish = time_to_str(s.substr(9,8));
		for(int i=start;i<finish;i++) 
      adv[i]++
	}

	int N = str_to_time(play_time);
	int len = time_to_str(adv_time);

	int idx=0;
	long long sum=0;
	long long maxSum=0;
	
	queue<int> q;

	for(int i=0;i<len;i++){
		sum+=adv[i];
		q.push(adv[i]);
	}
	maxSum=sum;

    // 큐를 이용한 투 포인터
	for(int i=len;i<N;i++){
		sum += adv[i];
		q.push(adv[i]);
		sum -= q.front();
		q.pop();
		if(sum > maxSum){
			idx = i-len+1;
			maxSum = sum;
		}
	}
	
    answer = time_to_str(idx);
    return answer;
}
