class Solution {
public:
    int coinChange(vector<int>& coins, uint16_t amount) {
        vector<uint16_t> dp(amount + 1, UINT16_MAX - 1);
        dp[0] = 0;
        for (const int& coin : coins)
            if(coin <= UINT16_MAX)
            	for (uint16_t j = coin; j <= amount; j++) 
                    if(dp[j] > 1 + dp[j - coin])
            		    dp[j] = 1 + dp[j - coin];

        return dp.back() == UINT16_MAX - 1 ? -1 : dp.back();
    }
};