class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numsMap;
        int maxi = 0;
        for (const auto& num : nums) {
            numsMap[num]++;
            maxi = max(maxi, numsMap[num]);
        }
        vector<vector<int>> buckets(maxi + 1);
        for (const auto& [key, val] : numsMap) {
            buckets[val].push_back(key);
        }

        vector<int> res;
        res.reserve(k);
        while (maxi > 0 && res.size() < k) {
            for (const auto& num : buckets[maxi]) {
                res.push_back(num);
                if (res.size() == k)
                    break;
            }
            maxi--;
        }
        return res;
    }
};