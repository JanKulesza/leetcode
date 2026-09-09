class Solution {
public:
    int climbStairs(uint8_t n) {
        if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        int* dp = new int[n];
        dp[0] = 1;
        dp[1] = 2;
        for(uint8_t i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};