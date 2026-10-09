// int dp[201][201];
int fun(int i, int j,vector<vector<int>>& t,vector<vector<int>>& dp){
    int n = t.size();

    if(i == n-1 ) return t[i][j];

    if(dp[i][j] != -2) return dp[i][j];

    int c1 = fun(i+1,j,t,dp);
    int c2 = fun (i+1,j+1,t,dp);

    return  dp[i][j] = t[i][j] + min(c1,c2);
}


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-2));
        return fun(0,0,triangle,dp);
    }
};