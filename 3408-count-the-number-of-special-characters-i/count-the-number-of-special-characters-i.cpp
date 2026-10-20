class Solution {
public:
    int numberOfSpecialChars(string word) {
        int special = 0;
        unordered_set<char> occ;
        for(const auto& letter : word) {
            if(!occ.contains(letter) && (occ.contains(letter + 'A' - 'a') || occ.contains(letter + 'a' - 'A')))
                special++;
            occ.insert(letter);
        }
        return special;
    }
};