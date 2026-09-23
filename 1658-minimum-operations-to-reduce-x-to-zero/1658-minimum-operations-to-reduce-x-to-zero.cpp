class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        // x is greater than total sum
        if (totalSum < x) {
            return -1;
        }

        // We need to keep a subarray with this sum
        int target = totalSum - x;

        // If target = 0, we keep nothing
        if (target == 0) {
            return n;
        }

        unordered_map<int, int> mp;
        mp[0] = -1;

        int prefixSum = 0;
        int longestSubarray = -1;

        for (int i = 0; i < n; i++) {

            prefixSum += nums[i];

            int findSum = prefixSum - target;

            if (mp.find(findSum) != mp.end()) {
                int idx = mp[findSum];

                longestSubarray =
                    max(longestSubarray, i - idx);
            }

            // Store first occurrence only
            if (mp.find(prefixSum) == mp.end()) {
                mp[prefixSum] = i;
            }
        }

        // No subarray with target sum
        if (longestSubarray == -1) {
            return -1;
        }

        return n - longestSubarray;
    }
};