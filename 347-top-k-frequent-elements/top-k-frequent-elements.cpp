class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> numsMap;
        int maxi = 0;
        for(const int& num : nums) {
            numsMap[num]++;
            maxi = max(maxi, numsMap[num]);
        }
        unordered_map<int, vector<int>> numsMap2;
        for (auto [key, val] : numsMap) {
            numsMap2[val].push_back(key);
        }
        
        vector<int> res;
        while (maxi > 0 && res.size() < k) {
            if (numsMap2.count(maxi) > 0) {
                for (const int& num : numsMap2[maxi]) {
                    res.push_back(num);
                    if (res.size() == k) break;
                }
            }
            maxi--;
        }
        return res;
    }
};