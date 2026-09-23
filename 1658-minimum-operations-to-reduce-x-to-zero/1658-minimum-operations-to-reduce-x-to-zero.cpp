class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int remsum = sum - x;

        if(remsum < 0) {
            return -1;
        }
        if(remsum == 0) {
            return n;
        }

        unordered_map<int, int> mp;
        mp[0] = -1;

        int prefix = 0;
        int longestsubarray = -1;

        for(int i = 0; i < n; i++) {

            prefix += nums[i];

            int findsum = prefix - remsum;

            if(mp.find(findsum) != mp.end()) {
                int idx = mp[findsum];

                longestsubarray = max(
                    longestsubarray,
                    i - idx
                );
            }
            if(mp.find(prefix) == mp.end()) {
                mp[prefix] = i;
            }
        }

        if(longestsubarray == -1) {
            return -1;
        }

        return n - longestsubarray;
    }
};