class Solution {
public:
    int memo[1001][1001];
    int helper(int i,int j,string &s){
        if(i>j){
            return 0;
        }
        if(i==j){
            return 1;
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        if(s[i]==s[j]){
            return memo[i][j]=2+helper(i+1,j-1,s);
        }else{
            return memo[i][j]=max(helper(i+1,j,s),helper(i,j-1,s));
        }

    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        memset(memo,-1,sizeof(memo));
        return helper(0,n-1,s);
        
    }
};