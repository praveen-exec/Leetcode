class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Approach 1 ==> Map
        map<int, int> mp;

        // Store frequency
        for(int x : nums) {
            mp[x]++;
        }

        vector<pair<int,int>> v;

        // {frequency, element}
        for(auto &p : mp) {
            v.push_back({p.second, p.first});
        }

        // Sort by frequency in descending order
        sort(v.begin(), v.end(), greater<pair<int,int>>());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};