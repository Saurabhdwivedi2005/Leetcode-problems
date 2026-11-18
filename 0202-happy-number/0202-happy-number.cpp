class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>st;

        while(n != 1) {
            int sum = 0;
            if(st.find(n) != st.end()) {
                return false;
            }

            st.insert(n);

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