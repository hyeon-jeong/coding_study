#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct Stud{
	char name[10];
	int kor, eng, math;
}; // 각 학생별 정보

bool compare(const Stud &s1, const Stud &s2){
  if (s1.kor == s2.kor && s1.eng == s2.eng && s1.math == s2.math) // 중복을 막기 위해 많은 조건을 충족해야 하는 케이스부터 처리
    return s1.name < s2.name;
	if (s1.kor == s2.kor && s1.eng == s2.eng) 
    return s1.math > s2.math;
	if (s1.kor == s2.kor) 
    return s1.eng < s2.eng;
	return s1.kor > s2.kor;
}

int main(){
	int n;
	cin>>n;

	vector<Stud> vec(n);
  
	for(int i=0; i<n; i++) 
		cin>>vec[i].name>>vec[i].kor>>vec[i].eng>>vec[i].math;
	
	sort(vec.begin(), vec.end(), compare);

	for(int i=0; i<n; i++)
		cout<<vec[i].name<<'\n';
}
