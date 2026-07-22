class Solution {
public:

    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            // Remove greater or equal elements
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }

            result[i] = st.empty() ? -1 : st.top();

            // IMPORTANT: Push outside the if-else
            st.push(i);
        }

        return result;
    }


    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            // Remove greater elements
            while (!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }

            result[i] = st.empty() ? n : st.top();

            // IMPORTANT: Push outside the if-else
            st.push(i);
        }

        return result;
    }


    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        long long M = 1e9 + 7;

        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        for (int i = 0; i < n; i++) {

            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;

            long long totalways = ls * rs;

            long long totalsum = arr[i] * totalways;

            sum = (sum + totalsum) % M;
        }

        return sum;
    }
};