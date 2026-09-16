class Solution {
public:
    bool canPartition(vector<int>& nums) {
        uint16_t sum = 0;
        unordered_set<uint16_t> occ;
        for (size_t i = 0; i < nums.size(); i++) {
            occ.insert(nums[i]);
            sum += nums[i];
        }
        if (sum % 2 != 0)
            return false;

        if(occ.contains(sum / 2))
            return true;

        vector<vector<uint16_t>> dp(nums.size() + 1, vector<uint16_t>(sum / 2 + 1, 0));

        for (size_t i = 1; i <= nums.size(); i++) {
            for (size_t s = 1; s <= sum / 2; s++)
            {
                if (nums[i - 1] <= s && dp[i - 1][s - nums[i - 1]] + nums[i - 1] > dp[i - 1][s]) {
                    dp[i][s] = dp[i - 1][s - nums[i - 1]] + nums[i - 1];
                }
                else {
                    dp[i][s] = dp[i - 1][s];
                }
            }
        }
        return dp[nums.size()][sum / 2] == sum / 2;
    }
};