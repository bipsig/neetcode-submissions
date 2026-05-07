class Solution {
public:
    vector <vector <int>> dp;

    bool solve (int i, int j, string& s1, string& s2, string& s3) {
        if (i+j == s3.size()) {
            return true;
        }
        if (dp [i][j] != -1) {
            return dp [i][j];
        }

        bool op1 = false, op2 = false;

        if (i < s1.size() && s1 [i] == s3 [i+j]) {
            op1 = solve (i+1, j, s1, s2, s3);
        }
        if (j < s2.size() && s2 [j] == s3 [i+j]) {
            op2 = solve (i, j+1, s1, s2, s3);
        }

        return dp [i][j] = op1 || op2;
    }

    bool isInterleave(string s1, string s2, string s3) {
        dp.resize (s1.size() + 2, vector <int> (s2.size() + 2, -1));
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        return solve (0, 0, s1, s2, s3);
    }
};
