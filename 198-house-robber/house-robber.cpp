class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        uint16_t prev = nums[0];
        uint16_t curr = max(nums[0], nums[1]);
        for (uint8_t i = 2; i < nums.size(); i++)
        {
            uint16_t temp = curr;
            if(nums[i] + prev > curr)
                curr = nums[i] + prev;
            prev = temp;
        }
        return curr;
    }
};