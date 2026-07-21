class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.length();
        // existing count of 1
        int activecount=count(begin(s),end(s),'1');
        vector<int>inactiveblock;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int start=i;
                while(i<n && s[i]=='0') i++;
                inactiveblock.push_back(i-start);
                
            }else{
                 i++;

            }
           
        }
        int maxcount=0;
        // maxcount=max(inactiveblok[i],inactiveblok[i-1])
        for(int i=1;i<inactiveblock.size();i++){
            maxcount=max(maxcount,inactiveblock[i]+inactiveblock[i-1]);

        }
        return maxcount+activecount;
       
    }
};