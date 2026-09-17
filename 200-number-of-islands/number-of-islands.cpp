class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numOfIslands = 0;
        for (uint16_t i = 0; i < grid.size(); i++) 
            for (uint16_t j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    stack<pair<uint16_t, uint16_t>> stack;
                    stack.emplace(i, j);
                    numOfIslands++;
                    while (!stack.empty())
                    {
                        auto [ci, cj] = stack.top();
                        stack.pop();
                        if (grid[ci][cj] == '0')
                            continue;

                        grid[ci][cj] = '0';
                        for (const auto& [di, dj] : { pair{1,0}, {0,1}, {0,-1}, {-1,0} }) {
                            if (ci + di < grid.size() && ci + di >= 0 && cj + dj < grid[i].size() && cj + dj >= 0 && grid[ci + di][cj + dj] == '1')
                                stack.emplace(ci + di, cj + dj);
                        }
                    }
                }
            }
        return numOfIslands;
    }
};