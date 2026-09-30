class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int right=0;
        int five=0;
        int ten=0;
        while(right<bills.size()){
            if(bills[right]==5){
                five++;

            }
            else if(bills[right]==10){
                if(five<=0){
                    return false;
                }
                ten++;
                five--;
            }
            else if(bills[right]==20){
                if(ten>0 && five>0){
                    ten--;
                    five--;

                }
                else if(five>=3){
                    five-=3;
                }else {
                    return false;
                }
            }
            right++;
        }
        return true;
    }
};