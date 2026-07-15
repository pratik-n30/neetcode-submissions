class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        int ones =0;
        int zeroes = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({{i,j},2});
                if(grid[i][j]==1) ones++;
                if(grid[i][j]==0) zeroes++;
            }
        }

        vector<int> dr = {0,-1,0,1};
        vector<int> dc = {1,0,-1,0};

        if(q.empty()){
            if(ones == 0) return 0;
            else return -1;
        }

        while(!q.empty())
        {
            pair<pair<int,int>,int> node = q.front();
            q.pop();
            int r = node.first.first;
            int c = node.first.second;
            int minute = node.second;
            


            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                    q.push({{nr,nc},minute+1});
                    grid[nr][nc] = minute + 1;
                }
            }

        }

        int result = -1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    result = -1;
                    break;
                }
                else{
                    result = max(result,grid[i][j]-2);
                }
            }
        }

        return result;
    }
};
