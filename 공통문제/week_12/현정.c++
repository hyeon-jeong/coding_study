#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<pair <int, int>> result;
    map <string, int> m;
    queue <string> q;
    int distinct, ti, si; // temp index, start index
    int ei = 100001; // end index
    int mintemp = 100001;
    
    for (int i=0; i<gems.size(); i++){
        m[gems[i]] = 1;
    }
    distinct = m.size();// distinct 한 값들 개수
    ei = gems.size();
    
    m.clear(); //value 비워줌. 이거 없애면 시간초과.
    
    //초기화
    for(int i=0; i<gems.size(); i++){
        //gems[i] 가 map 에 없다면 cnt=1, 
        //if(m[gems[i]] == 0){
        if(m.find(gems[i]) == m.end()){
            m[gems[i]] = 1;
        }
        //gems[i] 가 map 에 있다면 cnt ++ 해줌
        else
            m[gems[i]] += 1;
        //구간 queue 에 저장
        q.push(gems[i]);
    }
    //중복되지 않는지 탐색
    //구간 시작 인덱스 ti 탐색
    ti = 1;
    while(1){
        if(mintemp > ti){
            //모든 종류의 보석을 포함하지 않았을 때는 어떡함..?
            mintemp = ti;
        }    
        if(m[q.front()]>1){
            m[q.front()] -= 1;
            int temp = ti;
            if(m[q.front()] == 0)
                ti = temp; //index 임
            else{
                ti ++;
            }
            q.pop();
        }
        else if(m[q.front()] == 1){
            //test 4 의 경우에는 어떻게 해야할까...
            if(q.size()>1)
                q.pop();
            break;
        }
        else{
            break;
        }
    
    }

    if(m.size() == distinct && q.size() <= ei){
        printf("m size : %d, q size: %d \n", m.size(), q.size());
        si = mintemp; // 진열대 번호는 1부터 시작
        ei = si + q.size()-1;
    }

    answer.push_back(si);
    answer.push_back(ei);
    
    
    /*답은 result 중 si 값이 작은 쌍!
    answer.push_back(result[0].first, result[0].second);
    */
    return answer;
}