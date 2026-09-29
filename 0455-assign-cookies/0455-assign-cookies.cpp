class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int left=0;
        int right=0;
        int n=g.size();
        int m=s.size();
        int i=0;
        int count=0;
        while(left<n && right<m){
            if(g[left]<=s[right]){
                left++;
                right++;
            }
            else if(g[left]>s[right]){
                right++;
            }else{
                left++;
            }  
        }
        return left;
    }
};