#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

int N, Q;
vector<pair<int, ll>> usado[5001];
bool visited[5001];

int main(){
	cin >> N >> Q;

	for (int i = 0; i < N - 1; i++)
	{
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		vec[v1].push_back({v2,w});
		vec[v2].push_back({v1,w});
	}

	for (int i = 0; i < Q; i++)
	{
		int k, v;
		cin >> k >> v;

		memset(visited, 0, sizeof(visited));

		visited[v] = true;
		queue<int> q;
		q.push(v);

		int count = 0;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			for (int j = 0; j < usado[cur].size(); j++)
			{
				if (!visited[vec[cur][j].first])
				{
					if (usado[cur][j].second >= k)
					{
						count++;
						visited[usado[cur][j].first] = true;
						q.push({usado[cur][j].first });
					}
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}
