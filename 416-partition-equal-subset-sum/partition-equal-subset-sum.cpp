class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0)
            return false;

        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum / 2 + 1, 0));

        for (int i = 1; i <= nums.size(); i++) {
            for (int s = 1; s <= sum / 2; s++)
            {
                if (nums[i - 1] <= s) {
                    dp[i][s] = max(dp[i - 1][s - nums[i - 1]] + nums[i - 1], dp[i - 1][s]);
                }
                else {
                    dp[i][s] = dp[i - 1][s];
                }
            }
        }
        return dp[nums.size()][sum / 2] == sum / 2;
    }
};