int dp[2001][2001];
int fun(int i,int j,string &s1,string &s2){
    if(i>=s1.size() || j>=s2.size()) return 0;
    if(dp[i][j] != -1)
    return dp[i][j];
     int ans=0;
    if(s1[i]== s2[j]){
         ans = 1 + fun(i+1,j+1,s1,s2);
    }else{
         int c1=fun(i+1,j,s1,s2);
         int c2= fun(i,j+1,s1,s2);
         ans=max(c1,c2);
    }
   return dp[i][j] = ans;
}

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        memset(dp,-1,sizeof(dp));
        return fun(0,0,s,s2);
    }
};