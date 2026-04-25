class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set <int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.count (nums [i]) <= 0) {
                hash.insert (nums [i]);
            }
            else {
                return true;
            }
        }

        return false;
    }
};