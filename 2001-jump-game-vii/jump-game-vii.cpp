class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back() == '1')
            return false;
        int l = minJump;
        int r = maxJump;
        int lastR = 0;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] != '0')
                continue;

            if(l < s.size() && s.size() - 1 <= r)
                    return true;

            if(l <= i && i <= r || i <= lastR) {
                l = i + minJump;
                if(l >= s.size())
                    break;
                lastR = r;
                r = i + maxJump;
            }
        }
        return false;
    }
};