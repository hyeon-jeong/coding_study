#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 300
using namespace std;
 
int ans;
int cnt = 1;
int visit[MAX][MAX];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<int> p;
vector<pair<int, pair<int, int>>> edge;
 
void BFS(int x, int y, int n, vector<vector<int>> m, int h)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visit[x][y] = n;
 
    while (q.empty() == 0)
    {
        int x1 = q.front().first;
        int y1 = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x1 + dx[i];
            int ny = y1 + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m.size() && ny < m.size())
            {
                if (visit[nx][ny] == 0 && abs(m[x1][y1] - m[nx][ny]) <= h)
                {
                    visit[nx][ny] = n;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}
 
void landgroup(vector<vector<int>> land, int h)
{
    for (int i = 0; i < land.size(); i++)
    {
        for (int j = 0; j < land[i].size(); j++)
        {
            if (visit[i][j] == 0) BFS(i, j, cnt++, land, h);
        }
    }
}
 
void distance(vector<vector<int>> land, int h)
{
    for (int x = 0; x < land.size(); x++)
    {
        for (int y = 0; y < land.size(); y++)
        {
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && ny >= 0 && nx < land.size() && ny < land.size())
                {
                    if (visit[x][y] != visit[nx][ny])
                    {
                        edge.push_back(make_pair(abs(land[x][y] - land[nx][ny]), make_pair(visit[x][y], visit[nx][ny])));
                    }
                }
            }
        }
    }
}
 
int parent(int A)
{
    if (A == p[A]) return A;
    return p[A] = parent(p[A]);
}
 
void connect (int A, int B)
{
    A = parent(A);
    B = parent(B);
    p[B] = A;
}
 
bool if_same (int A, int B)
{
    A = parent(A);
    B = parent(B);
    if (A == B) return true;
    return false;
}
 
void search()
{
    p.resize(cnt);
    sort(edge.begin(), edge.end());
    for (int i = 1; i < cnt; i++) p[i] = i;
    for (int i = 0; i < edge.size(); i++)
    {
        int N1 = edge[i].second.first;
        int N2 = edge[i].second.second;
        int cost = edge[i].first;
        
        if(if_same(N1, N2) == false)
        { 
            connect(N1, N2);
            ans = ans + cost;
        }
    }
}
 
int solution(vector<vector<int>> land, int h)
{
    landgroup(land, h);
    distance(land, h);
    search();
 
    return ans;
}
