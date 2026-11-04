class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;

        // Keep low larger than or equal to high
        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                int val = *low.rbegin();

                low.erase(prev(low.end()));
                high.insert(val);

                sumLow -= val;
                sumHigh += val;
            }

            while (low.size() < high.size()) {
                int val = *high.begin();

                high.erase(high.begin());
                low.insert(val);

                sumHigh -= val;
                sumLow += val;
            }
        };

        auto add = [&](int val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sumLow += val;
            } else {
                high.insert(val);
                sumHigh += val;
            }

            balance();
        };

        auto remove = [&](int val) {
            auto it = low.find(val);

            if (it != low.end()) {
                low.erase(it);
                sumLow -= val;
            } else {
                it = high.find(val);
                high.erase(it);
                sumHigh -= val;
            }

            balance();
        };

        // Cost of making the current window equal
        auto getCost = [&]() -> long long {
            long long median = *low.rbegin();

            return median * low.size() - sumLow
                 + sumHigh - median * high.size();
        };

        // Step 1: Calculate cost of every window
        vector<long long> cost;

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost.push_back(getCost());
            }
        }

        // Step 2: DP
        // dp[i][j] = minimum cost to select j windows
        // starting from index i

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {

                // Option 1: Skip current index
                dp[i][j] = dp[i + 1][j];

                // Option 2: Select window starting at i
                if (i + x <= n) {
                    dp[i][j] = min(
                        dp[i][j],
                        cost[i] + dp[i + x][j - 1]
                    );
                }
            }
        }

        return dp[0][k];
    }
};