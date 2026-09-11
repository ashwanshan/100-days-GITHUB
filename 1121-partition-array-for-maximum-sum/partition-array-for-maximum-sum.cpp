int dp[501][501];
int fun(int i, int prev,vector<int> &nums,int mx,int k){
    if(i>=nums.size()) return 0;

    if(dp[i][prev] != -1) return dp[i][prev];

    int len = i-prev+1;

    mx=max(mx,nums[i]);

    int ans=0;
    if(len==k){
        int a=mx*len + fun(i+1,i+1,nums,0,k);
        ans=max(ans,a);
    }else{
        int a=mx*len + fun(i+1,i+1,nums,0,k);
        int b=fun(i+1,prev,nums,mx,k);

        ans=max(ans,a);
        ans=max(ans,b);
    }
    return dp[i][prev] = ans;
}

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,arr,0,k);
    }
};