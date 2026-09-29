class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int left = 0;
        int right = 0;

        int n = name.size();
        int m = typed.size();

        string st = "";

        while (right < m) {
            if (left < n && name[left] == typed[right]) {
                st.push_back(name[left]);
                left++;
                right++;
            }
            else if (right > 0 && typed[right] == typed[right - 1]) {
                right++;
            }
            else {
                return false;
            }
        }

        return st == name;
    }
};