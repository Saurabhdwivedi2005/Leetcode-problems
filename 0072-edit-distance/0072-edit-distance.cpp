class Solution {
public:
    int dp[501][501];
    int helper(int i,int j,string word1, string word2){
        if(i == word1.size()) {
            return word2.length() - j;
        }

        if(j == word2.length()) {
            return word1.length() - i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return dp[i][j]= helper(i+1,j+1,word1,word2);
        }else{
            dp[i][j] = 1 + min(helper(i,j+1,word1,word2),
                min(helper(i+1,j,word1,word2),helper(i+1,j+1,word1,word2)));

        } 
        return dp[i][j];  

    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,word1,word2);
        
    }
};