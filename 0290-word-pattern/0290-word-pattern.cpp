class Solution {
public:
    bool wordPattern(string pattern, string s) {

        // s ko tokens mein convert kar rhe hai
        stringstream ss(s);
        vector<string> tokens;
        string word;

        while (getline(ss, word, ' ')) {
            tokens.push_back(word);
        }

        int n = tokens.size();
        int m = pattern.length();

        // Number of words and pattern characters same hone chahiye
        if (n != m)
            return false;

        unordered_map<string, char> mp;
        unordered_set<char> usedChar;

        for (int i = 0; i < n; i++) {

            // Word pehli baar mila
            if (mp.find(tokens[i]) == mp.end()) {

                // Character already kisi aur word ko assigned hai
                if (usedChar.find(pattern[i]) != usedChar.end())
                    return false;

                // word -> character mapping
                mp.insert({tokens[i], pattern[i]});
                usedChar.insert(pattern[i]);
            }

            // Word ka existing mapping check karo
            if (mp[tokens[i]] != pattern[i])
                return false;
        }

        return true;
    }
};
