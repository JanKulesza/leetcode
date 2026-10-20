class Solution {
public:
    int numberOfSpecialChars(const string& word) {
        int arr['Z' - 'A' + 1]{};
        int special = 0;
        for(int i = word.size() - 1; i >= 0; i--) {
            if(word[i] <= 'Z') {
                if(arr[word[i] - 'A'] <= 1)
                    arr[word[i] - 'A'] = 1;
                if(arr[word[i] - 'A'] == 3) {
                    special--;
                    arr[word[i] - 'A'] = 2;
                }
            }
            else if(arr[word[i] - 'a'] == 1) {
                special++;
                arr[word[i] - 'a'] = 3;
            }
            else if(word[i] >= 'a' && arr[word[i] - 'a'] == 0)
                arr[word[i] - 'a'] = 2;
        }
        return special;
    }
};