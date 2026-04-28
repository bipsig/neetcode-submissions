class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int num : nums) {
            hash[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& [num, freq] : hash) {
            bucket[freq].push_back(num);
        }

        vector<int> ans;
        for (int i = bucket.size() - 1; i >= 0 && ans.size() < k; i--) {
            for (int j = 0; j < bucket[i].size() && ans.size() < k; j++) {
                ans.push_back(bucket[i][j]);
            }
        }

        return ans;
    }
};