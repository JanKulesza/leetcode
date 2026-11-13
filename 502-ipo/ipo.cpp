class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        map<int, vector<int>> m;
        for (int i = 0; i < profits.size(); i++) {
            m[profits[i]].emplace_back(capital[i]);
        }
        for(auto it = m.begin(); it != m.end(); ++it) {
            sort(it->second.begin(), it->second.end(), [](const auto& a, const auto& b) {
                return a > b;
            });
        }
        for (int i = 0; i < k; i++) {
            bool found = false;
            for (auto it = m.rbegin(); it != m.rend(); ++it) {
                if (!it->second.empty() && it->second.back() <= w) {
                    w += it->first;
                    it->second.pop_back();
                    found = true;
                    break;
                }
            }
            if(!found)
                break;
        }
        return w;
    }
};