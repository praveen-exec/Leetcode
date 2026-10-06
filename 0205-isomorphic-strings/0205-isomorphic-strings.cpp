//Time  : O(n) 
//Space : O(1)

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


//Approach 2 using maps 
//Time : O(n)  
//Space :O(K) where K is no of distinct characters

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
