class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mp1[256] = {0};
        int mp2[256] = {0};

        int n = s.length();
        int m = t.length();

        if (n != m)
            return false;

        for (int i = 0; i < n; i++) {
            // first occurence
            if (!mp1[s[i]] && !mp2[t[i]]) {
                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }
            //if it's not first occerence then it should map to same charcater in mp2
            else if (mp1[s[i]] != t[i])
                return false;
        }
        return true;
    }
};