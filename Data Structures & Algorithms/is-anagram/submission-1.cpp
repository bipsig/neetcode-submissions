class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> hash;
        for (int i = 0; i < s.size(); i++) {
            hash [s [i]]++;
        }

        for (int i = 0; i < t.size(); i++) {
            hash [t [i]]--;
        }

        for (auto it = hash.begin(); it != hash.end(); ++it) {
            if (it->second != 0) {
                return false;
            }
        }

        return true;
    }
};
