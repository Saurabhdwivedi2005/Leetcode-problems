
class Solution {
public:
    int dp[10001];

    int helper(int i, vector<int>& nums) {
        int n = nums.size();

        if(i >= n - 1) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int res = INT_MAX;

        for(int j = 1; j <= nums[i]; j++) {
            int x = i + j;

            if(x < n) {
                int ans = helper(x, nums);

                if(ans != INT_MAX) {
                    res = min(res, 1 + ans);
                }
            }
        }

        return dp[i] = res;
    }

    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(0, nums);
    }
};
