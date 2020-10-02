class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int dlen = digits.size();
        if (dlen == 0)
            return digits;
        
        for (int i=dlen - 1; i>=0; i--){
            if (digits[i]+1 > 9){ // 각 자릿수가 9인 경우 단순히 1을 더하면 안되므로, 따로 처리해준다.
                int tmp = digits[i] + 1;
                cout<<tmp % 10;
                digits[i] = tmp % 10;
                if (i == 0)
                    digits.insert(digits.begin(), 1); // 가장 높은 자리의 수가 9인 경우, 1을 더하면 10이 되므로 앞에 1을 insert
            }
            else{
                digits[i]++;
                break;
            }
        }
        return digits;
    }
};
