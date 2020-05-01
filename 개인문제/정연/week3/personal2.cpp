// Leetcode - Jewels and Stones

#include <bits/stdc++.h>

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count=0;
        for (int jewel=0; jewel<J.length(); jewel++){
            for (int stone=0; stone<S.length(); stone++){
                if (J[jewel] == S[stone])
                    count++;
            }
        }
        return count;
    }
};

// 가장 쉬운 방법이긴 한데, 시간복잡도가 커서 J나 S string의 길이가 늘어나면 문제가 생길 수 있다. STL 라이브러리 함수에 대해 좀더 공부해서 시간복잡도를 줄일 수 있는 방법이 있는지 알아보고 수정해야겠다.
