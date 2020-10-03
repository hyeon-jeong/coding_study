class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target <= nums[0])
            return 0;
        int start = 0;
        int end = nums.size() - 1;
        int mid;
    
        while (start <= end){
            mid = (start + end) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target){
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        
        if (start > end)
            return end + 1;
        
        return -1;
    }
};
