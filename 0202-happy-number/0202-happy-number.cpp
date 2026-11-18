
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;

        while(n != 1) {

            // Check if number is already visited
            if(st.find(n) != st.end()) {
                return false;
            }

            st.insert(n);

            int sum = 0;

            // Calculate sum of squares of digits
            while(n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n = n / 10;
            }

            n = sum;
        }

        return true;
    }
};

