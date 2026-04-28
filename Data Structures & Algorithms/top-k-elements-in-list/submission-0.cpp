class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash [nums [i]]++;
        }

        priority_queue <pair <int, int>> heap;
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            heap.push (make_pair (it->second, it->first));
        }

        vector <int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back (heap.top().second);
            heap.pop();
        }

        return ans;
    }
};
