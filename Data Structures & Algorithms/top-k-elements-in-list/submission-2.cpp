class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector <vector <int>> freq (nums.size()+1);
        unordered_map <int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash [nums [i]]++;
        }

        for (auto it = hash.begin(); it != hash.end(); ++it) {
            freq [it->second].push_back (it->first);
        }

        int x = 0;
        vector <int> ans;
        for (int i = n; i >= 0; i--) {
            for (int j = 0; j < freq [i].size(); j++) {
                ans.push_back (freq [i][j]);
                x++;

                if (x == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
