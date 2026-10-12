class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0) return 0;
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        s=s.substr(i);
        long ans=0;
        int sign=1;
        if(s[0]=='-') sign=-1;
        int MAX=INT_MAX,MIN=INT_MIN;
        i=(s[0]=='+' || s[0]=='-') ?1:0;
        while(i<s.length()){
            if(s[0]==' '|| !isdigit(s[i])) break;
            ans=ans*10+s[i]-'0';
            i++;
            if(sign==-1 && -1*ans<MIN) return MIN;
            if(sign==1 && ans>MAX) return MAX;
        }
        return (int)(sign*ans);
        
    }
};