class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        if (n == 0) return 0;

        vector<int> pref(n);
        pref[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pref[i] = nums[i] + pref[i - 1];
        }

        for (int i = 0; i < n; i++) {
            // Subarray starting at index 0
            if (pref[i] == k) {
                count++;
            }

            // Subarrays starting after index 0
            for (int j = 0; j < i; j++) {
                if (pref[i] - pref[j] == k) {
                    count++;
                }
            }
        }

        return count;
    }
};
