class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;
        vector<int> dp(s.size(), 0);
        dp[s.size() - 1] = min(1, s.back() - '0');
        bool toTerminate = dp.back() == 0;
        for(int i = s.size() - 2; i >= 0; i--) {
            dp[i] = dp[i + 1];
            if(toTerminate && (s[i] == '1' || s[i] == '2')) {
                toTerminate = false;
                dp[i] = max(dp[i], 1);
                continue;
            }
            else if(toTerminate)
                return 0;

            if(s[i] == '0') {
                toTerminate = true;
                continue;
            }

            if((s[i] - '0') * 10 + (s[i + 1] - '0') <= 26 && !(i + 2 < s.size() && s[i + 2] == '0')) {
                if(i + 2 < s.size())
                    dp[i] = dp[i + 1] + dp[i + 2];
                else
                    dp[i] = dp[i + 1] + 1;
            }
        }
        return dp[0];
    }
};