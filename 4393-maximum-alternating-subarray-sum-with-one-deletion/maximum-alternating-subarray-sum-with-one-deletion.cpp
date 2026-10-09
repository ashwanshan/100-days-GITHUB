typedef long long ll;
ll dp[100001][3][3][2];
ll fun(int i,vector<int>& nums,int s,int sign, int p){
    if(i == nums.size()) {
     if(s==0) return -1e17;
     return 0;
    }

    if(dp[i][s][sign+1][p] != -1e17) return dp[i][s][sign+1][p];

    ll curr = 1LL*nums[i]*sign;
    ll m= -1e17;

    if(s==0){
      ll c1=  fun(i+1,nums,s,sign,p);
       ll c2= curr + fun(i+1,nums,1,-sign,p);
      m= max(m,c1);
      m=max(m,c2);
    }else{
         ll c1= curr + fun(i+1,nums,1,-sign,p);
         m = max(m,c1);
         m = max(m, 0LL);
         if(p==1){
           ll c=fun(i+1,nums,1,sign,0);
           m = max(m,c);
         }
    }
    return dp[i][s][sign+1][p] =  m;
}
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
       std::fill(&dp[0][0][0][0], &dp[0][0][0][0] + 100001LL * 3 * 3 * 2, -1e17);
        return fun(0,nums,0,1,1);
    }
};