#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

bool sorting(const int &n1, const int &n2){
    return n1 < n2;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	scanf("%d", &T);
    int num[10];
    vector<int> v;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        for(int i=0; i<10; i++){
            scanf("%d", num[i]);
            v.push_back(num[i]);
        }
        sort(v.begin(), v.end(), sorting);
        v.erase(v.begin()); v.erase(v.end());
        
        int sum = 0;
        for (auto& n : v){
            sum += n;
        }
            
        int avg = sum;
        printf("#%d %d\n", test_case, avg);
	}
	return 0;
}
