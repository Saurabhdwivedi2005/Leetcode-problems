class Solution {
public:
    int maxDepth(string s) {
        stack<int>st;
        int ans=0;
        int count=0;
        for(int i=0;i<s.length();i++){
            // int count=0;
            if(s[i]=='(' ){
                st.push(s[i]);
                count++;
                ans=max(ans,count);
            }
            else if(s[i]==')'){
                st.pop();
                count--;
                
            }
            // st.pop();
            ans=max(ans,count);
            
        }
        return ans;
    }
};