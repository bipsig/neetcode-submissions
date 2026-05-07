class Solution {
public:
    vector <vector <int>> dp;

    int solve (int i, int amount, vector <int>& coins) {
        // cout << i << ", " << amount << endl;
        if (amount == 0) {
            return 1;
        }
        if (i == coins.size() || amount < 0) {
            return 0;
        }

        if (dp [i][amount] != -1) {
            return dp [i][amount];
        }

        int pick = solve (i, amount - coins [i], coins);
        int notpick = solve (i+1, amount, coins);

        return dp [i][amount] = pick + notpick;
    }

    int change(int amount, vector<int>& coins) {
        dp.resize (coins.size() + 2, vector <int> (amount + 2, -1));
        return solve (0, amount, coins);
    }
};
