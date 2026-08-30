void fun(int i,vector<int> &nums,unordered_map<int,int>& m1){
    if(i==nums.size())
        return;
    if(i==0||nums[i] != nums[i-1])
        m1[nums[i]]++;
    fun(i+1,nums,m1);
}

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int> m1;
        fun(0,nums,m1);

        int ans=0;
        for(auto x : m1){
            if(x.second == 1)
                ans++;
        }
        return ans;
    }
};