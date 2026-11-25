class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for(int i = 0; i < n; i++) {
            long long p = 1;
            int g = 0, l = 1;

            for(int j = i; j < n; j++) {
                if(p > LLONG_MAX / nums[j])
                    break;

                p *= nums[j];
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);

                if(p == 1LL * g * l)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};