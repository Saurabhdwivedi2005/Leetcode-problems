class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans=0;
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(int i=0;i<s.size();i++){
            mp1[s[i]]++;
            
        }
        for(int i=0;i<t.size();i++){
            mp2[t[i]]++;
        }
        for(auto it : mp2){
            if(it.second>mp1[it.first])
                return it.first;
            

        }
        return ' ';
    }
};