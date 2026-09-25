int dp[2001][2001];
bool check(string &a,string &b){
    if(b.size() != a.size() +1) return false;
    int i=0,j=0;
    while(i<a.size() && j<b.size()){
        if(a[i] == b[j])
        i++;
        j++;
    }
    return i == a.size();
}
int fun(int i,int p,vector<string>& pairs){
   if(i>=pairs.size()) return 0;
   if( p != -1 && dp[i][p] != -1) return dp[i][p];
    int c1 = 0;
   if(p== -1 || check(pairs[p],pairs[i])){
    c1 = 1+ fun(i+1,i,pairs);
   }
        int c2= fun(i+1,p,pairs);
    if (p != -1)
       return dp[i][p] = max(c1, c2);
       return max(c1,c2);
}
bool cmp(string a, string b) {
return a.size() < b.size();
}

class Solution {
public:
    int longestStrChain(vector<string>& pairs) {
         sort(pairs.begin(),pairs.end(),cmp);
        memset(dp,-1,sizeof(dp));
         return fun(0,-1,pairs);
    }
};