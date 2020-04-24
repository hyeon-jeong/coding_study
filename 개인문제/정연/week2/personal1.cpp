#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int arr[105];

void bike()
{ 
    int N;
	int ans = 0;
	
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 1; i < N - 1; i++){
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1])
            ans++;
	    }
    cout << ans << endl;
}

int main()
{
    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        bike();
    }
}
