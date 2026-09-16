class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        bool* dp = new bool[target + 1]();
        dp[0] = true;
        for (const auto& num : nums) {
            for (size_t s = target; s >= num; s--)
                if(dp[s - num])
                    dp[s] = true;

            if(dp[target])
                return true;
        }
        bool result = dp[target];
        delete[] dp;
        return result;
    }
};