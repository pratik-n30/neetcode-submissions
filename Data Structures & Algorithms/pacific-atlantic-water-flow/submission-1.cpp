class Solution {
public:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    void dfs(int r, int c,
             vector<vector<int>>& heights,
             vector<vector<bool>>& visited) {

        visited[r][c] = true;

        int m = heights.size();
        int n = heights[0].size();

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            if (visited[nr][nc])
                continue;

            // Reverse flow condition
            if (heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, heights, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific (top row)
        for (int j = 0; j < n; j++)
            dfs(0, j, heights, pacific);

        // Pacific (left column)
        for (int i = 0; i < m; i++)
            dfs(i, 0, heights, pacific);

        // Atlantic (bottom row)
        for (int j = 0; j < n; j++)
            dfs(m - 1, j, heights, atlantic);

        // Atlantic (right column)
        for (int i = 0; i < m; i++)
            dfs(i, n - 1, heights, atlantic);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};