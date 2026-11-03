class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int pref= 1;
        int suff=1;
        
        for (int i = 0; i < nums.size(); i++) {
            if(pref==0){
                pref=1;
            }
            if(suff==0){
                suff=1;
            }
            int n=nums.size();
            pref=pref*nums[i];
            suff=suff*nums[n-i-1];
            res=max({res,suff,pref});
           
        }
        return res;
    }
};