class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string, string> mp;

        // Store key-value pairs
        for (auto &x : knowledge) {
            mp[x[0]] = x[1];
        }

        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {

                int j = i + 1;
                string key = "";

                // Find closing bracket
                while (s[j] != ')') {
                    key += s[j];
                    j++;
                }

                // Check key in map
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } else {
                    ans += "?";
                }

                // Move i after ')'
                i = j;
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};