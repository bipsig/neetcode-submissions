class Solution {
public:
    vector <vector <int>> dp;

    int solve (int i, int tar, vector <int>& coins) {
        if (tar == 0) {
            return 0;
        }
        if (i == coins.size() || tar < 0) {
            return INT_MAX;
        }
        if (dp [i][tar] != -1) {
            return dp [i][tar];
        }

        int pick = solve (i, tar - coins [i], coins);
        pick = pick != INT_MAX ? pick+1 : pick;
        int notpick = solve (i+1, tar, coins);

        return dp [i][tar] = min (pick, notpick);
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.resize (coins.size() + 2, vector <int> (amount + 2, -1));
        int ans = solve (0, amount, coins);

        return ans == INT_MAX ? -1 : ans;
    }
};
