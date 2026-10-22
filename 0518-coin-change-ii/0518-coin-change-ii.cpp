
class Solution {
public:
    int dp[301][5001];

    int helper(int i, int amount, vector<int>& coins) {
        if (amount == 0) {
            return 1;
        }

        if (amount < 0 || i == coins.size()) {
            return 0;
        }

        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }

        int take = helper(i, amount - coins[i], coins);
        int skip = helper(i + 1, amount, coins);

        return dp[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return helper(0, amount, coins);
    }
};
