#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char num[11][11];
int N;
vector<int> v;

bool possible(int idx)
{
    int sum = 0;

    for (int i = idx; i >= 0; i--)
    {
        sum += v[i];
        
        if (num[i][idx] == '+' && sum <= 0)	return false;
        if (num[i][idx] == '-' && sum >= 0)	return false;
        if (num[i][idx] == '0' && sum != 0)	return false;
    }
    return true;
}

void solve(int idx){
    if (idx == N){
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        exit(0);
    }

    for (int i = -10; i <= 10; i++){
        v.push_back(i);

        if (possible(idx))
            solve(idx + 1);

        v.pop_back();
    }
}

int main()
{
    cin >> N;
    string s;
    cin >> s;

    int idx = 0;

    for (int i = 0; i < N; i++){
        for (int j = i; j < N; j++)
            num[i][j] = s[idx++];
    }

    solve(0);

}
