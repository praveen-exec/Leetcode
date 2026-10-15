
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> mp1, mp2, mp3;

        string str1 = "qwertyuiop";
        string str2 = "asdfghjkl";
        string str3 = "zxcvbnm";

        for (char ch : str1)
            mp1[ch]++;

        for (char ch : str2)
            mp2[ch]++;

        for (char ch : str3)
            mp3[ch]++;

        vector<string> ans;

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];

            bool row1 = true, row2 = true, row3 = true;

            for (int j = 0; j < word.length(); j++) {
                char ch = tolower(word[j]);

                if (mp1.find(ch) == mp1.end())
                    row1 = false;

                if (mp2.find(ch) == mp2.end())
                    row2 = false;

                if (mp3.find(ch) == mp3.end())
                    row3 = false;
            }

            if (row1 || row2 || row3)
                ans.push_back(word);
        }

        return ans;
    }
};
