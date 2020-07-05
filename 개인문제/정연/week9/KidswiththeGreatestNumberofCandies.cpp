class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> answer;
        int max = 0;
        
        for (int i=0; i<candies.size(); i++){
            if (candies[i] > max)
                max = candies[i];
        }
        
        for (int i=0; i<candies.size(); i++){
            if (candies[i] + extraCandies >= max)
                answer.push_back(true);
            else
                answer.push_back(false);
        }
        
        return answer;
    };
};
