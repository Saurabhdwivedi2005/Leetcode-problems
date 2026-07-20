class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        // Find next greater element for every element in nums2
        for (int i = nums2.size() - 1; i >= 0; i--) {

            // Remove all smaller or equal elements
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // Store the next greater element
            if (st.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = st.top();

            // Push current element
            st.push(nums2[i]);
        }

        // Build answer for nums1
        vector<int> ans;
        for (int x : nums1) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};