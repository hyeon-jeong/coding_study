// Leetcode - Minimum Time Visiting All Points


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int optPath = 0;
        for (int i=1; i<points.size(); i++){
            optPath += max(abs(points[i][0]-points[i-1][0]), abs(points[i][1]-points[i-1][1]));
        }
        return optPath;
    }
};
