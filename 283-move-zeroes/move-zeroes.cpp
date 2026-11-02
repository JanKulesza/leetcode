class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            while (j < nums.size() && nums[j] == 0)
                j++;
            while (i < nums.size() && nums[i] != 0)
                i++;

            if (i > j) {
                j = i + 1;
                continue;
            }
            if(j >= nums.size())
                break;

            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            j++;
            i++;
        }
    }
};