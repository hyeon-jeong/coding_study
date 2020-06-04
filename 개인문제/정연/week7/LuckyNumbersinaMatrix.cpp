class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int min, max;
        vector<int> temp, ans;
        
        for (int i=0; i<m; i++){
            min = matrix[i][0];
            for (int j=0; j<n; j++){
                if (matrix[i][j] < min)
                    min = matrix[i][j];
            }
            temp.push_back(min);
        }
        
        for (int j=0; j<n; j++){
            max = matrix[0][j];
            for (int i=0; i<m; i++){
                if (matrix[i][j] > max)
                    max = matrix[i][j];
            }
            
            for (int k=0; k<temp.size(); k++){
                if (max == temp[k])
                    ans.push_back(max);
            }            
        }
        return ans;
    };
};
