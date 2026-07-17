class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto ch:nums){
            mp[ch]++;

        }
        sort(nums.begin(),nums.end(),[& mp](int key,int value){
            if(mp[key] == mp[value]){
                return key > value;
            }      
            return mp[key] < mp[value]; 
        });
        return nums;
    }
};