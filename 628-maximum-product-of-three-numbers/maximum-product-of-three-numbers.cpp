class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int16_t max1, max2, max3, min1, min2;
            max1 = max2 = max3 = -1001;
            min1 = min2 = 1001;

        for (int16_t i = 0; i < nums.size(); i++) {
            if (nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            }
            else if (nums[i] < min2)
                min2 = nums[i];

            if (nums[i] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if (nums[i] > max2) {
                max3 = max2;
                max2 = nums[i];
            }
            else if (nums[i] > max3)
                max3 = nums[i];
        }
        if (min1 * min2 * max1 > max1 * max2 * max3)
            return min1 * min2 * max1;
        return max1 * max2 * max3;
    }
};