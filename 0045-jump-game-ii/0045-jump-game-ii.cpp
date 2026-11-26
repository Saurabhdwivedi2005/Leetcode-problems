
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, INT_MAX);

        dp[0] = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= nums[i]; j++) {

                int x = i + j;

                if(x < n && dp[i] != INT_MAX) {
                    dp[x] = min(dp[x], dp[i] + 1);
                }
            }
        }

        return dp[n-1];
    }
};
