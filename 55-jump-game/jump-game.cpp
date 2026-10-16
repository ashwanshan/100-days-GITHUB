int dp[10001];
bool fun(int i,vector<int> & nums){
    if(i>= nums.size() -1) return true;
    if(dp[i] != -1) return dp[i];
    for(int j=1;j<=nums[i];j++){
        if(fun(i+j,nums)) return dp[i] =true;
    }
    return dp[i] =false;
}


class Solution {
public:
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return fun(0,nums);
    }
};