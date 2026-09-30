class Solution {
public:
    bool canJump(vector<int>& nums) {
        int steps=0;
        for(int right=0;right<nums.size();right++){
            if(right>steps){
                return false;
            }
            steps=max(steps,right+nums[right]);
            if(steps==nums.size()-1) return true;
        }
        return -1;
        
    }
};