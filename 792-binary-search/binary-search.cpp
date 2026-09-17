class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r) {
            int s = (l + r) / 2;
            if(nums[s] == target)
                return s;
            if(nums[s] > target)
                r = s - 1;
            else 
                l = s + 1;
        }
        return nums[l] == target ? l : -1;
    }
};