#include <string>
#include <vector>

using namespace std;
int answer = 100;

void dfs(string begin, string target, vector<string> &words, vector<bool> &visited, int count) {
    
    for (int i = 0; i < words.size(); i++) {
        int diff = 0;
        
        for (int j = 0; j < begin.size(); j++) {
            if (!visited[i] && begin[j] != words[i][j]) 
                diff++;
        }
        
        if (diff == 1) {
            if (target == words[i] && answer > count + 1) {
                answer = count + 1;
                return;
            }
          
            visited[i] = true;
            dfs(words[i], target, words, visited, count+1);
            visited[i] = false;
        }
        
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> visited(words.size(), false);
    dfs(begin, target, words, visited, 0);

    if (answer == 100) 
        return 0;
    
    return answer;
}
