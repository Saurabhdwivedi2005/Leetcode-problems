
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        int i = 0;

        while(i < bills.size()) {
            if(bills[i] == 5) {
                five++;
            }
            else if(bills[i] == 10) {
                if(five > 0) {
                    ten++;
                    five--;
                }
                else {
                    return false;
                }
            }
            else if(bills[i] == 20) {
                if(five > 0 && ten > 0) {
                    ten--;
                    five--;
                }
                else if(five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }

            i++;
        }

        return true;
    }
};
