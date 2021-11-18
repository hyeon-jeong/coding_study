#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct milk {
    int x;
    int y;
    bool visited;
};

int n=0, m=0, h=0, ans=0;
int village[11][11];
vector<milk> mintchoco;
pair<int,int> house;

void dfs(int x, int y, int strength, int cnt){
    if(cnt > ans){
        if(abs(x - house.first) + abs(y - house.second) <= strength)
            ans = cnt;
    }
    
    if(strength <= 0)
        return;
    
    for(int i=0; i<mintchoco.size(); i++){
        int distance = abs(mintchoco[i].x - x) + abs(mintchoco[i].y - y);
        
        if(distance <= strength && mintchoco[i].visited == false){
            int new_strength = strength - distance + h;
            
            mintchoco[i].visited = true;
            dfs(mintchoco[i].x, mintchoco[i].y, new_strength, cnt+1);
            mintchoco[i].visited = false;
        }
    }
}

int main(){
    cin>>n>>m>>h;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>village[i][j];
            
            if(village[i][j] == 1){
                house.first = i;
                house.second = j;
            }
            
            else if(village[i][j] == 2)
                mintchoco.push_back({i, j, 0});
        }
    }
    
    dfs(house.first, house.second, m, 0);
    
    cout<<ans<<endl;
    
    return 0;
}
