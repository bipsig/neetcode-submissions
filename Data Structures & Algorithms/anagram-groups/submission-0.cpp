class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        unordered_map <string, vector <int>> hash;
        for (int i = 0; i < str.size(); i++) {
            string tmp = str [i];
            sort (tmp.begin(), tmp.end());
            hash [tmp].push_back (i);
        }

        vector <vector <string>> ans;
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            vector <string> tmp;
            for (int i = 0; i < it->second.size(); i++) {
                tmp.push_back (str [it->second [i]]);
            }

            ans.push_back (tmp);
        }

        return ans;
    }
};
