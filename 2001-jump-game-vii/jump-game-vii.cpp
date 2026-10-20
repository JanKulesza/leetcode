class Solution {
public:
    bool canReach(string& s, int& minJump, int& maxJump) {
        s[0] = '2';
        int reachableCount = 0;
        for(int i = 1; i < s.size(); i++) {
            if(i >= minJump && s[i - minJump] == '2')
                reachableCount++;
            if(i > maxJump && s[i - maxJump - 1] == '2')
                reachableCount--;

            if(reachableCount > 0 && s[i] == '0')
                s[i] = '2';
        }
        return s.back() == '2';
    }
};