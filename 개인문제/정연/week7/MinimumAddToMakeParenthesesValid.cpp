#include<bits/stdc++.h>

class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> par;
        int ans = 0;
        
        for (int i=0; i<S.size(); i++){
            if (S[i] == '(')
                par.push('(');
            else if (par.empty())
                ans++;
            else
                par.pop();
        }
        
        ans += par.size();
        return ans;
    };
};
