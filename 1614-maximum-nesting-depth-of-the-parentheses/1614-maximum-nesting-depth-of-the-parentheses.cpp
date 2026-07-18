class Solution {
public:
    int maxDepth(string s) {
        int maxx=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            // int count=0;
            if(s[i]=='('){
                count+=1;
                maxx=max(maxx,count);
            }else if(s[i]==')'){
                // i++;
                count--;

            }
            maxx=max(maxx,count);
        }
        return maxx;
        
    }
};