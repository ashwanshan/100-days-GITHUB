int dp[2001][2001];
int fun(int i,int p,vector<vector<int>>& pairs){
   if(i>=pairs.size()) return 0;
   if( p != -1 && dp[i][p] != -1) return dp[i][p];
    int c1 = 0;
   if(p== -1 || pairs[p][1] < pairs[i][0]){
    c1 = 1+ fun(i+1,i,pairs);
   }
        int c2= fun(i+1,p,pairs);
    if (p != -1)
       return dp[i][p] = max(c1, c2);
       return max(c1,c2);
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        memset(dp,-1,sizeof(dp));
         return fun(0,-1,pairs);
    }
};