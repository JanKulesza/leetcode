class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1 || obstacleGrid.back().back() == 1)
            return 0;
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 1));
        bool hasObstacle = false;
        for(int i = m - 2; i >= 0; i--) {
            if(obstacleGrid[i][n - 1] == 1)
                hasObstacle = true;
            if(hasObstacle)
                dp[i][n - 1] = 0;
        }
        hasObstacle = false;
        for(int j = n - 2; j >= 0; j--) {
            if(obstacleGrid[m - 1][j] == 1)
                hasObstacle = true;
            if(hasObstacle)
                dp[m - 1][j] = 0;
        }
        for(int i = m - 2; i >= 0; i--)
            for(int j = n - 2; j >= 0; j--) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        return dp[0][0];
    }
};