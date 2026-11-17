
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> freq(1001, 0);
        vector<int> ans;

        // Step 1: Count frequency of elements
        for(int i = 0; i < arr1.size(); i++) {
            freq[arr1[i]]++;
        }

        // Step 2: Add elements according to arr2 order
        for(int i = 0; i < arr2.size(); i++) {
            while(freq[arr2[i]] > 0) {
                ans.push_back(arr2[i]);
                freq[arr2[i]]--;
            }
        }

        // Step 3: Add remaining elements in ascending order
        for(int i = 0; i <= 1000; i++) {
            while(freq[i] > 0) {
                ans.push_back(i);
                freq[i]--;
            }
        }

        return ans;
    }
};
