class Solution {
public:
    int dp[105][105];

    int fun(int i, int j, vector<vector<int>>& matrix) {
        int n = matrix.size();

        if(j < 0 || j >= n)
            return 1e9;

        if(i == n-1)
            return matrix[i][j];

        if(dp[i][j] != 1e9)
            return dp[i][j];

        return dp[i][j] = matrix[i][j] + min({fun(i+1, j-1, matrix),fun(i+1, j, matrix),fun(i+1, j+1, matrix)});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = 1e9;

        int ans = 1e9;

        for(int j = 0; j < n; j++) {
            ans = min(ans, fun(0, j, matrix));
        }

        return ans;
    }
};