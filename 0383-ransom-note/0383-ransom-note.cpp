class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> mp;

        // Magazine ke har character ka count store karo
        for(char x : magazine) {
            mp[x]++;
        }

        // Ransom note ke characters check karo
        for(int i = 0; i < ransomNote.length(); i++) {

            // Character present nahi hai
            if(mp.find(ransomNote[i]) == mp.end())
                return false;

            if(mp[ransomNote[i]] == 0)
                return false;

            mp[ransomNote[i]]--;
        }

        return true;
    }
};