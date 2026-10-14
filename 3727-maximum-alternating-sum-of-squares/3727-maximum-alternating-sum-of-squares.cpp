class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];
        }     
        sort(nums.begin(),nums.end());
        long long largehalf=accumulate(begin(nums)+n/2,end(nums),0LL);
        long long smallhalf=accumulate(begin(nums),begin(nums)+n/2,0LL);
        return largehalf-smallhalf;
    }
};