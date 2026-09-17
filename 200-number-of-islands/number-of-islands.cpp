class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numOfIslands = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    stack<pair<int, int>> stack;
                    stack.emplace(i, j);
                    numOfIslands++;
                    grid[i][j] = '0';
                    while (!stack.empty())
                    {
                        auto [ci, cj] = stack.top();
                        stack.pop();
                        for (const auto& [di, dj] : { pair{1,0}, {0,1}, {0,-1}, {-1,0} }) {
                            if (ci + di < grid.size() && ci + di >= 0 && cj + dj < n && cj + dj >= 0 && grid[ci + di][cj + dj] == '1') {
                                stack.emplace(ci + di, cj + dj);
                                grid[ci + di][cj + dj] = '0';
                            }
                        }
                    }
                }
            }
        return numOfIslands;
    }
};