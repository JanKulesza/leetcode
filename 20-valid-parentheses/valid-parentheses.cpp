class Solution {
public:
    bool isValid(string s) {
        stack<char> lastOpen;
        int open = 0;
        for(const auto& par : s) {
            if(par == '}' || par == ')' || par == ']') {
                open--;
                if(open < 0 || abs(par - lastOpen.top()) > 2)
                    return false;
                lastOpen.pop();
            } 
            else {
                open++;
                lastOpen.push(par);
            }
        }
        return open == 0 ? true : false;
    }
};