class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int ans;
        map<int, int> mp;

        while (n > 0) {
            int x = n % 10;
            n /= 10;
            mp[x]++;
        }

        int mini = INT_MAX;
        
        for (auto p : mp) {
            //agar same bhi hoga then isme handle ho jaayega because we have used ordered map 
            // 1->2
            // 2->2
            // mini=1 & ans =1 after that 2<2 = false and ans=1 hi hoga
            if (p.second < mini) {
                mini = p.second;
                ans = p.first;
            }
        }

        return ans;
    }
};
