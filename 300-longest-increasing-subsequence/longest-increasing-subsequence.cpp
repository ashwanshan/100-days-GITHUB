int dp[2501][2501];
int fun(int i, int p,vector<int> &nums){
    if(i>=nums.size()) return 0;
    if(dp[i][p+1] != -1) return dp[i][p+1];
   int ans =0;
    if(p== -1){
        int a= 1+ fun(i+1,i,nums);
        int b=fun(i+1,p,nums);
        ans=max(ans,a);
        ans=max(ans,b);
    }else{
        if(nums[i]>nums[p]){
        int a= 1+ fun(i+1,i,nums);
        int b=fun(i+1,p,nums);   
        ans=max(ans,a);
        ans=max(ans,b);
        }else{
             int b=fun(i+1,p,nums);  
              ans=max(ans,b);
        }
    }
    return dp[i][p+1] =ans;
}
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return fun(0,-1,nums);
    }
};