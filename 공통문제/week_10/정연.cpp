#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

bool sorting(const string &name1, const string &name2){
    if (name1.size() == name2.size())
        return name1 < name2;
    return name1.size() < name2.size();
}

int main(int argc, char** argv)
{
	int test_case;
	int T, N;
	scanf("%d", &T);
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        scanf("%d", &N);
        vector<string> list;
        for(int i=0; i<N; i++){
            char name[51];
            scanf("%s", name);
            string str(name);
            list.push_back(name);  // 명부 입력받기
        }
        
        sort(list.begin(), list.end(), sorting);
        list.erase(unique(list.begin(), list.end()), list.end());
        
        printf("#%d\n", test_case);
        vector<string>::iterator iter;
        for(iter = list.begin(); iter != list.end(); iter++){
            printf("%s\n", iter->c_str());
        }
    }
	return 0;
}
