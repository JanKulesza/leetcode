class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxi = 0;
        while(j > i) {
            maxi = max(maxi, (j - i) * min(height[i], height[j]));
            if(height[j] > height[i])
                i++;
            else
                j--;
        }
        return maxi;
    }
};