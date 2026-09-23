class Solution {
public:
int mod = 1e9+7;
    vector<vector<vector<int>>>dp;
    int f(int i,int j,vector<vector<int>>& grid,int k,int sum){
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m)return 0;
        int nsum = (grid[i][j]+sum)%k;
        if(i == n-1 && j == m-1){
            return dp[i][j][nsum] = (nsum == 0)?1:0;
        }
        if(dp[i][j][nsum] != -1)return dp[i][j][nsum];
        int down = f(i+1,j,grid,k,nsum);
        int right = f(i,j+1,grid,k,nsum);
        return dp[i][j][nsum] = (down+right)%mod;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return f(0,0,grid,k,0);
    }
};
