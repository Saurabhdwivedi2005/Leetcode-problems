class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=s.size()-1;
        int cnt=0;
        int j=t.size()-1;
        while(i>=0 && j>=0){
            if(s[i]==t[j]){
                cnt++;
                i--;
                j--;
            }
            else{
                j--;
            }
        }
        if(cnt==s.size()){
            return true;
        }else{
            return false;
        }
        
        return-1;
    }
};