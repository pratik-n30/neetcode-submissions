class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int perimeter=0;
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};
        for(int i =0; i<r; i++){
            for(int j=0; j<c;j++){
                if(grid[i][j]==1){
                    if(i==0){
                        perimeter++;
                    }
                    if(j==0){
                        perimeter++;
                    } 
                    if(i==r-1) perimeter++;
                    if(j==c-1) perimeter++;
                    for(int z=0;z<4;z++){
                        if(i+dr[z] < r && i+dr[z]>=0 &&j+ dc[z]<c && j+ dc[z]>=0 && grid[i + dr[z]][j + dc[z]]==0) perimeter++;
                    }

                }
            }
        }
        return perimeter;
    }
};