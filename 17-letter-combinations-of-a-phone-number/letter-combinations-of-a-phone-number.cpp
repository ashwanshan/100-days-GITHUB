vector<string> ans; // Sare final combinations store karne ke liye

void fun(int i, string &s, string tmp, map<int, string> &m1) {

    // Agar sare digits cover ho gaye to combination complete hai
    if (i >= s.size()) {
        ans.push_back(tmp); // Complete combination answer me daal diya
        return;
    }

    int curr = s[i] - '0'; // Current character ko digit me convert kiya

    string str = m1[curr]; // Current digit ke corresponding letters nikal liye

    // Kyuki ek digit ke multiple letters ho sakte hain,
    // isliye har letter ko try karenge
    for (int j = 0; j < str.size(); j++) {

        tmp += str[j]; // Ek letter combination me add kiya

        // Current letter choose karke next digit par gaye
        fun(i + 1, s, tmp, m1);

        // Wapas aake current letter hata diya,
        // taki next letter try kar saken
        tmp.pop_back();
    }
}


class Solution {
public:
    vector<string> letterCombinations(string s) {

        map<int, string> m1; // Digit aur letters ki mapping ke liye

        m1[2] = "abc";
        m1[3] = "def";
        m1[4] = "ghi";
        m1[5] = "jkl";
        m1[6] = "mno";
        m1[7] = "pqrs";
        m1[8] = "tuv";
        m1[9] = "wxyz";

        ans.clear(); // Purane answers hatane ke liye

        fun(0, s, "", m1); // First digit se empty string ke saath start kiya

        return ans; // Sare combinations return kiye
    }
};