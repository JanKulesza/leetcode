class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (const auto& n : numSet) {
            if (numSet.count(n - 1) == 0) {
                int currN = n;
                int currStreak = 1;
                while (numSet.count(currN + 1) > 0) {
                    currN++;
                    currStreak++;
                }
                longestStreak = max(longestStreak, currStreak);
            }
        }
        return longestStreak;
    }
};