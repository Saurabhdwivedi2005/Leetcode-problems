
class Solution {
public:
    using ll = long long;

    const ll mod1 = 1000000007;
    const ll mod2 = 1000000009;
    const ll base1 = 911382323;
    const ll base2 = 972663749;

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<ll> h1(n + 1), h2(n + 1);
        vector<ll> p1(n + 1, 1), p2(n + 1, 1);

        for(int i = 0; i < n; i++) {
            h1[i+1] = (h1[i] * base1 + nums[i]) % mod1;
            h2[i+1] = (h2[i] * base2 + nums[i]) % mod2;

            p1[i+1] = p1[i] * base1 % mod1;
            p2[i+1] = p2[i] * base2 % mod2;
        }

        auto check = [&](int len) {
            unordered_map<unsigned long long, int> mp;

            for(int i = 0; i + len <= n; i++) {
                ll a = (h1[i+len] - h1[i] * p1[len] % mod1 + mod1) % mod1;
                ll b = (h2[i+len] - h2[i] * p2[len] % mod2 + mod2) % mod2;

                unsigned long long key =
                    (static_cast<unsigned long long>(a) << 32) | b;

                mp[key]++;
            }

            for(auto &it : mp) {
                if(it.second == 1) return true;
            }

            return false;
        };

        int l = 1, r = n;

        while(l < r) {
            int mid = l + (r-l)/2;

            if(check(mid))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};
