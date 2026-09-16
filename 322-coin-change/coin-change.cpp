class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, INT_MAX - 1));
for (int i = 1; i <= coins.size(); i++)
{
	const int& coin = coins[i - 1];
	dp[i][0] = 0;
	for (int j = 1; j <= amount; j++)
	{
		int minWithCoin = INT_MAX;
		if (coin <= j)
			minWithCoin = 1 + min(dp[i][j - coin], dp[i - 1][j - coin]);
		dp[i][j] = min(minWithCoin, dp[i - 1][j]);
	}
}

return dp.back().back() == INT_MAX - 1 ? -1 : dp.back().back();
    }
};