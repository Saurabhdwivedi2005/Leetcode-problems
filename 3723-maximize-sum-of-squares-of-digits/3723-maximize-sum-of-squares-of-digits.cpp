class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        int digit;
        if(sum>9*num) return ans;
        while(num>0){
            digit=min(9,sum);
            ans.push_back('0' + digit);;
            sum=sum-digit;
            num--;
        }
        return ans;
    }
};