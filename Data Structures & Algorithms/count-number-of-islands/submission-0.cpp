class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        int dr[4] = {0, -1, 0, 1};
        int dc[4] = {1, 0, -1, 0};

        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < rows &&
                nc >= 0 && nc < cols &&
                grid[nr][nc] == '1' &&
                visited[nr][nc] == 0) {

                visited[nr][nc] = 1;
                dfs(nr, nc, grid, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        int islands = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    islands++;
                    visited[i][j] = 1;
                    dfs(i, j, grid, visited);
                }
            }
        }

        return islands;
    }
};