class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans=0;
        for(char ch :s){
            ans=ans^ch;
        }
        for(char ch :t){
            ans=ans^ch;
        }
        return ans;
        
    }
};