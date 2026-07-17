class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0;i<s.size();i++){
            // char ch1=s[i],ch2=t[i];
            if(s[i]!=t[i]){
                return false;
            }
            
            
        }
        return true;
        
    }
};