
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);

        long long total = 0;
        int maxi = 0;

        long long k = 1LL * k1 + k2;

        // Step 1: Calculate absolute differences
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            maxi = max(maxi, diff[i]);
        }

        // Step 2: If all differences can become zero
        if (total <= k) {
            return 0;
        }

        // Step 3: Binary search the maximum allowed difference
        int left = 0, right = maxi;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid) {
                    need += d - mid;
                }
            }

            if (need <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // Step 4: Reduce every difference to at most left
        for (int i = 0; i < n; i++) {
            k -= max(0, diff[i] - left);
            diff[i] = min(diff[i], left);
        }

        // Step 5: Use remaining operations
        for (int i = 0; i < n && k > 0; i++) {
            if (diff[i] == left) {
                diff[i]--;
                k--;
            }
        }

        // Step 6: Calculate sum of squares
        long long ans = 0;

        for (int d : diff) {
            ans += 1LL * d * d;
        }

        return ans;
    }
};
