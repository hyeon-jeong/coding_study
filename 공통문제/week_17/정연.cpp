#include <string>
#include <vector>
using namespace std;
const int MAX = 200000;

bool visited[MAX];
int before[MAX];
int missed[MAX];
vector<int> edge[MAX];

void visit(int num){
    if(visited[num]) 
        return;
   
    if(!visited[before[num]]){
        missed[before[num]] = num;
        return;
    }
    
    visited[num] = true;
    visit(missed[num]);
   
    for(int n : edge[num]) 
        visit(n);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    for(auto &it : path){
        edge[it[0]].push_back(it[1]);
        edge[it[1]].push_back(it[0]);
    }
    
    for(auto &it : order) 
        before[it[1]] = it[0]; 
   
    if(before[0]) return false;
   
    visited[0] = true;
    for(int n : edge[0])
        visit(n);
    
    for(int i = 0 ; i < n ; i++) 
        if(!visited[i]) 
            return false;
    
    return true;
}
