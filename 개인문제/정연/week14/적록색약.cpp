#include<iostream>
#include<cstring>
using namespace std;

int N;
char map[101][101];
bool visited[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int y, int x){
	visited[y][x] = true;
  
	for (int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
    
		if (ny >= 1 && ny <= 100 && nx >= 1 && nx <= 100)
			if (!(visited[ny][nx]) && (map[y][x] == map[ny][nx]))
				dfs(ny, nx);
	}
}

int main(){
	cin >> N;
	
	int norm = 0, weak = 0;
  
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> map[i][j];
      
	
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (!visited[i][j]){
				dfs(i, j);
				norm++;
			}
		}
	}
  
	memset(visited, false, sizeof(visited));
  
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (map[i][j] == 'R')
        map[i][j] = 'G';
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (!visited[i][j]){
				dfs(i, j);
				weak++;
			}
		}
	}
	cout << norm << " " << weak << endl;
}
