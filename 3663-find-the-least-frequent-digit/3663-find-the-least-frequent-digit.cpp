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
            if (p.second < mini) {
                mini = p.second;
                ans = p.first;
            }
        }

        return ans;
    }
};