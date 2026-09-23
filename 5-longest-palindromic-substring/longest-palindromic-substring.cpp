class Solution {
public:
    string getPalindrome(string& s, int l, int r) {
        while(l >= 0 && r < s.size()) {
            if(s[l] != s[r]) 
                return s.substr(l + 1, r - l - 1);
                l--;
                r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
    string longestPalindrome(string s) {
        string longest = s.substr(0,1);
        for(int i = 1; i < s.size(); i++) {
            string p = getPalindrome(s, i, i);
            if(p.size() > longest.size()) {
                longest = p;
            }
            if(s[i] == s[i - 1]) {
                p = getPalindrome(s, i - 1, i);
                if(p.size() > longest.size()) {
                    longest = p;
                }
            }
        }
        return longest;
    }
};