class Solution {
public:
    int minMoves(vector<int>& nums) {
         int mini = *max_element(nums.begin(), nums.end());

        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            ans += nums[i] - mini;
        }

        return abs(ans);
    }
        
    
};