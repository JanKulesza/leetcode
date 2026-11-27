class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0)
            return {1};
        vector<int> dp(2, 1);
        for(int i = 2; i <= rowIndex; i++) {
            vector<int> next(dp.size() + 1, 1);
            for(int j = 1; j < i; j++) {
                next[j] = dp[j - 1] + dp[j];
            }
            dp = next;
        }
        return dp;
    }
};