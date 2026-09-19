int dp[501][501][26];
int fun(int i,int prev,int k,vector<int> &nums){
    if(i>=nums.size()) return 0;
    if(dp[i][prev +1][k] != -1) return dp[i][prev +1][k];
       int c1=0;

       if (prev == -1 || nums[i] == nums[prev]) {
        c1 = 1 + fun(i+1,i,k,nums);
        }
        else if (k>0) {
        c1 = 1 + fun(i+1,i,k-1,nums);
        }
        int c2= fun(i+1,prev,k,nums);

        return dp[i][prev +1][k] = max(c1,c2);
}

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
         return fun(0,-1,k,nums);
    }
};