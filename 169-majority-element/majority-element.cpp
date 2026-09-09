class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, uint16_t> occ;
        for (const auto& num : nums) 
            if (++occ[num] > nums.size() / 2)
                return num;
        return -1;
    }
};