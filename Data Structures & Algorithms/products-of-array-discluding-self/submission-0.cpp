class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <long long> left (n, 1), right (n, 1);

        left [0] = nums [0];
        for (int i = 1; i < n; i++) {
            left [i] = 1ll*left [i-1]*nums [i];
        }
        right [n-1] = nums [n-1];
        for (int i = n-2; i >= 0; i--) {
            right [i] = 1ll*right [i+1]*nums[i];
        }

        vector <int> ans (n);
        cout << "Here";
        for (int i = 1; i < n-1; i++) {
            ans [i] = left [i-1]*right[i+1];
        }
        ans [0] = right [1];
        ans [n-1] = left [n-2];

        return ans;
    }
};
