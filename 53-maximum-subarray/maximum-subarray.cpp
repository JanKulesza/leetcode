class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(currSum + nums[i] > 0) {
                currSum += nums[i];
                maxSum = max(maxSum, currSum);
            } 
            else {
                if(maxSum <= 0)
                    maxSum = max(maxSum, nums[i]);
                currSum = 0;
                continue;
            }
        }
        return maxSum;
    }
};