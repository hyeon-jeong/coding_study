#include<iostream>
#include<cstring>

using namespace std;
int arr[100];
int score[10001];
int ans = 0;

int main(int argc, char** argv)
{  
	int T, N;
	cin>>T;
    
	for(int test_case = 1; test_case <= T; ++test_case)
	{
        memset(arr, 0, sizeof(arr));
    	memset(score, 0, sizeof(score));
        cin>>N;
        ans = 0;
        score[0] = 1;
        
        int temp = 0;
        for (int i = 0; i < N; i++){
            cin>>arr[i];
            temp += arr[i];
            for (int j = temp; j >= 0; j--){
                if (score[j])
                    score[j + arr[i]] = 1;
            } score[arr[i]] = 1;
        }
        
        for (int i = 0; i <= temp; i++){
            if (score[i])
                ans++;
        }
        
        cout<<"#"<<test_case<<" "<<ans<<endl;
    } return 0;
}
