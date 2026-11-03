class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int product = 1;
            for (int j = i; j < nums.size(); j++) {
                product = product * nums[j];
                if (product > res) {
                    res = product;
                }
            }
        }
        return res;
    }
};