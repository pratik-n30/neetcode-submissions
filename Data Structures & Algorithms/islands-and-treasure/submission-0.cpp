class Solution {
public:
    long long INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int m = grid.size();
        int n = grid[0].size();

        for(int i =0; i<m; i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) q.push({{i,j},0});
            }
        }
        vector<int> dr = {0,-1,0,1};
        vector<int> dc = {1,0,-1,0};

        while(!q.empty()){
            pair<pair<int,int>,int> node = q.front();
            int r = node.first.first;
            int c = node.first.second;
            int val = node.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    if(grid[nr][nc]==INF){
                        grid[nr][nc]=val+1;
                        q.push({{nr,nc},val+1});
                    }
                }
            }
        }
    }
};
