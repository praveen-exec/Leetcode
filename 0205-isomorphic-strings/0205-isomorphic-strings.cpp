class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        map<char, char> s1;
        map<char, char> s2;

        for (int i = 0; i < s.size(); i++) {
            char ch1 = s[i];
            char ch2 = t[i];
            
            if (s1.find(ch1) != s1.end() && s1[ch1] != ch2 ||
                s2.find(ch2) != s2.end() && s2[ch2] != ch1)
                return false;

            //mapping the char if not mapped 
            s1[ch1] = ch2;
            s2[ch2] = ch1;
        }

        return true;
    }
};
