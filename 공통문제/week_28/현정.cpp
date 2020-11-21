#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    int memCnt;
    for(int i=0; i<queries.size(); i++){
        memCnt = 0;
        for(int j=0; j<words.size(); j++){
            //일단 길이로 걸러내고
            bool flag;
            if(queries[i].length() == words[j].length()){
                //?위치에 문자있는지
                for(int k=0; k<queries[i].length(); k++){
                    if(queries[i][k]!='?' && queries[i][k] == words[j][k]){
                        flag = true;
                    }
                    else if(queries[i][k] != '?' && queries[i][k] != words[j][k]){ 
                        flag = false;
                        continue;
                    }
                    else
                       continue;
                }
                if(flag) memCnt ++;
            }
            else
                continue;
        }
        answer.push_back(memCnt);
    }
    
    return answer;
}