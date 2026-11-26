
class Solution {
public:
    // int dp[10001];

    int jump(vector<int>& nums) {
        int n=nums.size();
        // memset(dp, INT_MIN, sizeof(dp));
        vector<int>dp(n,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i];j++){
                int x=i+j;
                if(x<n){
                    dp[x]=min(dp[x],dp[i]+1);
                }
            }
        }
        return dp[n-1];
        
    }
};
