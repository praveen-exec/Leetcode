
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> mp;

        for (char ch : text) {
            mp[ch]++;
        }

        int b = mp['b'];
        int a = mp['a'];
        int l = mp['l'] / 2;
        int o = mp['o'] / 2;
        int n = mp['n'];

        return min({b, a, l, o, n});
    }
};
