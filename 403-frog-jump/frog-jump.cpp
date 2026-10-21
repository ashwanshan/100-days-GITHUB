class Solution {
public:
    unordered_map<long long, bool> dp;

    bool solve(int curr, int jump, vector<int>& stones, unordered_set<int>& st) {

        if(curr == stones.back())
            return true;

        long long key = ((long long)curr << 32) | jump;

        if(dp.count(key))
            return dp[key];

        for(int x = jump - 1; x <= jump + 1; x++) {

            if(x <= 0)
                continue;

            int next = curr + x;

            if(st.count(next)) {
                if(solve(next, x, stones, st))
                    return dp[key] = true;
            }
        }

        return dp[key] = false;
    }

    bool canCross(vector<int>& stones) {

        unordered_set<int> st(stones.begin(), stones.end());

        return solve(stones[0], 0, stones, st);
    }
};