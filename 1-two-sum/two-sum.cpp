class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, uint16_t> occ;
        for(uint16_t i = 0; i < nums.size(); i++) {
            if(occ.contains(target - nums[i]))
                return {i, occ[target - nums[i]]};
            occ[nums[i]] = i;
        }
        return {-1, -1};
    }
};