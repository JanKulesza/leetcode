class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int s = (l + r) / 2;
            if(nums[s] == target)
                return s;

            if(nums[s] >= nums[l]) {
                if(nums[l] <= target && nums[s] > target) {
                    r = s - 1;
                }   
                else {
                    l = s + 1;
                }
            }
            else {
                if(target <= nums[r] && target > nums[s])
                    l = s + 1;
                else 
                    r = s - 1;
            }
        }
        return -1;
    }
};