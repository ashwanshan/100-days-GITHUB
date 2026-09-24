int dp[1001][1001];
int fun(int i,int j,string &text1,string &text2){
    if(i>=text1.size()){ 
       int sum =0;
       while(j<text2.size()){
          sum += text2[j];
          j++;
       }
       return sum;
}
    if(j>=text2.size()) {
       int sum = 0;
       while(i<text1.size()){
          sum += text1[i];
          i++;
       }
       return sum;
}
    if(dp[i][j] != -1)
    return dp[i][j];
     int ans=0;
    if(text1[i]== text2[j]){
         ans = fun(i+1,j+1,text1,text2);
    }else{
         int c1= text1[i] + fun(i+1,j,text1,text2);
         int c2= text2[j] + fun(i,j+1,text1,text2);
        //
         ans=min(c1,c2);
    }
   return dp[i][j] = ans;
}
class Solution {
public:
    int minimumDeleteSum(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,text1,text2);
    }
};