class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hm;
        int maxi = 0;
        for(const int& num : nums) {
            hm[num]++;
            maxi = max(maxi, hm[num]);
        }
        unordered_map<int, vector<int>> hm2;
        for (auto [key, val] : hm) {
            hm2[val].push_back(key);
        }
        
        vector<int> res;
        while (maxi > 0 && res.size() < k) {
            if (hm2.count(maxi) > 0) {
                for (const int& num : hm2[maxi]) {
                    res.push_back(num);
                    if (res.size() == k) break;
                }
            }
            maxi--;
        }
        return res;
    }
};