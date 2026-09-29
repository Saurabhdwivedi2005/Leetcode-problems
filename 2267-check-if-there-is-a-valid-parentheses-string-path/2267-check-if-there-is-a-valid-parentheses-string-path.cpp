class Solution {
public:
    int dp[101][101][205];
    int helper(int i,int j,vector<vector<char>>&grid,int count){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m){
            return 0;
        }
         if(grid[i][j]=='('){
            count++;
        }
        else{ 
            count--;
        }
        if(i==n-1 && j==m-1){
            return count==0;
        }
        if(count<0 || count>n+m){
            return 0;
        }
        if(dp[i][j][count]!=-1){
            return dp[i][j][count];
        }
        
        return dp[i][j][count]=helper(i+1,j,grid,count) ||helper(i,j+1,grid,count);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       memset(dp, -1, sizeof(dp));
        return helper(0,0,grid,0);
        
    }
};