#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    //1단계
    for (char& c: new_id)
        c = tolower(c);
    
    //2단계
    for (char& c: new_id){
        if (c == '-' || c == '_' || c == '.' || '0'<=c && c<='9' || 'a'<=c && c<='z')
            answer.push_back(c);
    }
    
    //3단계
    string period = "";
    int size = answer.size();
    
    for (int i=0; i<size; i++){
        if (answer[i] == '.'){
            period.push_back('.');
            while (i<size && answer[i] == '.')
                i++;
            i--;
        }       
        else
            period.push_back(answer[i]);
    }
    answer = period;
    
    //4단계
    if (answer[0] == '.')
        answer.erase(0,1);
    if (answer[answer.size()-1] == '.')
        answer.erase(answer.size()-1,1);
    
    //5단계
    if (answer.empty())
        answer.push_back('a');
    
    //6단계
    if (answer.size() >= 16){
        answer = answer.substr(0,15);
        if (answer[answer.size()-1] == '.')
            answer = answer.substr(0,answer.size()-1);
    }
    
    //7단계
    while (answer.size() <= 2)
        answer += answer[answer.size()-1];
    
    return answer;
}
