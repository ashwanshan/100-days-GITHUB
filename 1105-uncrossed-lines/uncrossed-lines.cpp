int dp[1001][1001];
int fun(int i,int j,vector<int>&a,vector<int>&b){
    if(i>=a.size() || j>=b.size()) return 0;
    if(dp[i][j] != -1)
    return dp[i][j];
     int ans=0;
    if(a[i]== b[j]){
         ans = 1 + fun(i+1,j+1,a,b);
    }else{
         int c1=fun(i+1,j,a,b);
         int c2= fun(i,j+1,a,b);
        //
         ans=max(c1,c2);
    }
   return dp[i][j] = ans;
}
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
      memset(dp,-1,sizeof(dp));
        return fun(0,0,nums1,nums2);
    }
};