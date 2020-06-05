// bit 연산 등을 이용해서 시간복잡도 O(n)으로 풀어야 timeout이 되지 않는 문제이다. 
// bit 연산을 알고리즘에 적용하는 것은 처음 해봤는데, 앞으로 복잡한 문제에 적용할 수 있도록 더 공부해야겠따.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = nums[0];
        
        for (int i=1; i<nums.size(); i++)
            single ^= nums[i];
        
        return single;
    };
};
