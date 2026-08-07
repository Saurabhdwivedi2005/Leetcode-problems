class Solution {
public:
    bool isValid(string &str){
        int count = 0;

        for(char &ch : str){
            if(ch == '(')
                count++;
            else
                count--;

            if(count < 0)
            return false;
        }
        return count == 0;
    }
    vector<string>res;
    void helper(string&curr,int n){
        if(curr.length()==2*n){
            if(isValid(curr)){
                res.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        helper(curr,n);
        curr.pop_back();

        curr.push_back(')');
        helper(curr,n);
        curr.pop_back();

    
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        helper(curr,n);
        return res;
        
    }
};