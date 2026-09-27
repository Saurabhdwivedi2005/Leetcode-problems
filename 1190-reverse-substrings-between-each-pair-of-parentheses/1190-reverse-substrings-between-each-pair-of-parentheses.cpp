class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        // string result="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=')'){
                st.push(s[i]);
            }
            else {
                string result = "";

                while(st.top()!='('){
                    result.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(char ch : result){
                    st.push(ch);
                }
            }

        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;      
    }
};