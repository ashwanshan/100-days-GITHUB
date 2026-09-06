class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int cr =0;

        for(int i=0;i<n;i++){
            if(s[i] ==s[(i+1) % n]){
                cr++;
            }
        }
        if(k== cr-1) return cr;
        if(k== cr) return n-cr;
        return 0;
    }
};