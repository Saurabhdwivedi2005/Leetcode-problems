class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth=0;
        vector<int> ans(seq.length());
        for(int i=0;i<seq.length();i++){
            if(seq[i]=='('){
                depth++;
                ans[i]=depth%2;
            }else if(seq[i]==')'){
                ans[i]=depth%2;
                depth--;
            }
        }
        return ans;
        
    }
};