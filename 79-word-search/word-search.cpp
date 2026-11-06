class Solution {
public:
    int N = 0;
    int M = 0;
    bool dfs(const vector<vector<char>>& board, const string& word, int i,
             int j, int index, vector<vector<bool>>& visited) {
        if (index == word.size())
            return true;

        if (i < 0 || i >= N || j < 0 || j >= M || visited[i][j] || board[i][j] != word[index])
            return false;

        visited[i][j] = true;
        bool found = false;
        found = dfs(board, word, i + 1, j, index + 1, visited) ||
                dfs(board, word, i, j + 1, index + 1, visited) ||
                dfs(board, word, i - 1, j, index + 1, visited) ||
                dfs(board, word, i, j - 1, index + 1, visited);

        visited[i][j] = false;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        N = board.size();
        M = board[0].size();
        bool output = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] != word[0])
                    continue;
                vector<vector<bool>> visited(N, vector<bool>(M, false));
                if (dfs(board, word, i, j, 0, visited))
                    return true;
            }
        }
        return false;
    }
};