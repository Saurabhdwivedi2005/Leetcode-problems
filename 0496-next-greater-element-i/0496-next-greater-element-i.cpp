class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res(nums1.size());
        bool found=false;

        for(int i=0;i<nums1.size();i++){
            found =false;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    found=true;
                }
                if(found && nums2[j]>nums1[i]){
                    res[i]=nums2[j];
                    break;
                }

            }
        }
        for(int i=0;i<res.size();i++){
            if(res[i]==0){
                res[i]=-1;
            }
        }
        return res;
    }
};