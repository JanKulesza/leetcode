class Solution {
public:
    int maxDepth(string s) {
        int open = 0;
        int maxOpen = 0;
        for(int i = 0; i < s.size() - maxOpen; i++) {
            if(s[i] == '(')
                open++;
            else if(s[i] == ')')
                open--;

            maxOpen = max(maxOpen, open);
        }
        return maxOpen;
    }
};