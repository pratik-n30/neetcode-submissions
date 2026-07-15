class Solution {
public:
    vector<int> dr = {1,0,-1,0};
    vector<int> dc = {0,-1,0,1};

    void dfs(int r, int c, int &area,
             vector<vector<int>>& grid,
             vector<vector<int>>& visited)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>=0 && nr<rows &&
               nc>=0 && nc<cols &&
               grid[nr][nc]==1 &&
               !visited[nr][nc])
            {
                visited[nr][nc]=1;
                area++;
                dfs(nr,nc,area,grid,visited);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols,0));

        int max_area = 0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    visited[i][j]=1;
                    int area=1;
                    dfs(i,j,area,grid,visited);
                    max_area=max(max_area,area);
                }
            }
        }

        return max_area;
    }
};