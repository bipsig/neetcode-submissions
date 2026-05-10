class Solution {
public:
    int trap(vector<int>& height) {
        vector <int> right (height.size());
        right [height.size() - 1] = height [height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--) {
            if (height [i] > right [i+1]) {
                right [i] = height [i];
            }
            else {
                right [i] = right [i+1];
            }
        }

        int ans = 0;
        int curr = height [0];
        for (int i = 0; i < height.size(); i++) {
            if (height [i] > curr) {
                curr  = height [i];
            }
            int wat = min (curr, right [i]) - height [i];
            if (wat > 0) {
                ans += wat;
            }
        }

        return ans;
    }
};
