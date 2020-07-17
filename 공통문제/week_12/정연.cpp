#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;


vector<int> solution(vector<string> gems) {
    vector<int> answer = {1, (int)gems.size()};
    set<string> j;
    map<string, int> ans;
    
    for (string i : gems) j.insert(i);

    int start = 0, end = 0;

    while (true) {
        if (ans.size() == j.size()) {
            if (answer[1] - answer[0] > end - start) {
                answer[0] = start + 1;
                answer[1] = end;
            }
            
            if (ans[gems[start]] == 1) {
                ans.erase(gems[start]);
                start++;
            }
        
            else if (ans[gems[start]] - 1 > 0) {
                ans[gems[start]]--;
                start++;                        
            }
        }
        
        else if (end == gems.size()) break;
      
        else {
            ans[gems[end]]++;
            end++;
        }
    }    
    return answer;
}
