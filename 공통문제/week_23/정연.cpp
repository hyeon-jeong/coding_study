#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end()); // 길이가 짧은 번호일수록 앞 순서로 정렬하고, 비교 기준으로 설정할 수 있도록 한다.
    for (int i=0; i<phone_book.size()-1; i++){
        if (phone_book[i+1].substr(0, phone_book[i].size()) == phone_book[i]){ // 기준이 되는(더 짧은) 번호 전체가 중복되는지 확인
            return false;
            break;
        }
    }
    return answer;
}
