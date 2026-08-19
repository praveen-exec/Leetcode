 //Approach 1 ==> Map
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       
        unordered_map<int, int> mp;

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


//Aproach 2 ==> Min Heap
class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> mp;

        typedef pair<int, int> P;

        // Store frequency
        for (int x : nums) {
            mp[x]++;
        }

        // min heap
        priority_queue<P, vector<P>, greater<P>> pq;

        for (auto& p : mp) {
            int element = p.first;
            int freq = p.second;

            pq.push({freq, element});

            if (pq.size() > k) pq.pop();
        }
        // Freq -element
        // 3 - 1
        // 2 - 2
        // 1 - 3

        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
