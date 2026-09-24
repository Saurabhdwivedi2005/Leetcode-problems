class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int sum=0;
            int digit=nums[i];
            while(digit>0){
                int num=digit%10;
                sum+=num;
                digit=digit/10;
            }
            if(sum==i){
                return i;
            }
        }
        return -1;
    }
};