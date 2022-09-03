
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    int mod;
    string ans;
    unordered_set<int> st;
    void dfs(int v, int k) {
        if (st.count(v)) return;

        st.insert(v);
        // cout << v << endl;
        int t = v % k;
        cout << "t:" << t << endl;
        ans += '0' + t;
        int i = 0;
        for (int i = 0; i < k; i++) { dfs((v % mod) * k + i, k); }
    }
    string crackSafe(int n, int k) {
        if (n == 1) {
            string ret(k, ' ');
            for (int i = 0; i < k; i++) ret[i] = '0' + i;
            return ret;
        }
        mod = pow(k, n - 1);
        if (n > 1) ans = string(n - 1, '0');
        dfs(0, k);
        return ans;
    }
};
int main() {
    Solution s;
    cout << s.crackSafe(3, 4) << endl;
    return 0;
}