
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        vector<int> freq1(1001, 0);
        vector<int> freq2(1001, 0);
        vector<int> ans;

        for(int i = 0; i < arr1.size(); i++) {
            freq1[arr1[i]]++;
        }

        for(int i = 0; i < arr2.size(); i++) {
            freq2[arr2[i]]++;
        }

        for(int i = 0; i < arr2.size(); i++) {

            int x = arr2[i];

            while(freq1[x] > 0 || freq2[x] > 0) {
                ans.push_back(x);
                freq1[x]--;
                freq2[x]--;
            }
        }

        // Remaining elements in ascending order
        for(int i = 0; i <= 1000; i++) {
            while(freq1[i] > 0) {
                ans.push_back(i);
                freq1[i]--;
            }
        }

        return ans;
    }
};
