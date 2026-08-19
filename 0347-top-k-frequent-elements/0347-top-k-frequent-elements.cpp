class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Approach 2 ==> Min Heap
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