#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
  public:
    static const int maxn = 10;
    int ss[maxn * 4];
    typedef long long ll;
    ll MOD = 1e9 + 10;
    int ql, qr; // A[ql, ..., qr]
    int p, v;   // A[p] = v;
    int query(int l, int r, int o) {
        if (r < l) return 0;
        int m = (l + r) / 2;
        if (ql <= l and r <= qr) return ss[o];
        int count = 0;
        if (ql <= m) count += query(l, m, 2 * o + 1);
        if (m < qr) count += query(m + 1, r, 2 * o + 2);
        return count;
    }
    void update(int l, int r, int o) {
        int m = (l + r) / 2;
        if (l == r) ss[o] = v;
        else {
            if (p <= m) update(l, m, o * 2 + 1);
            else
                update(m + 1, r, o * 2 + 2);
            ss[o] = ss[o * 2 + 1] + ss[o * 2 + 2];
        }
    }
    int createSortedArray(vector<int> &i) {
        map<int, int> count;
        memset(ss, 0, sizeof(ss));
        ll res = 0;
        for (auto x : i) {
            ql = 0;
            qr = x - 1;
            int y = query(0, maxn - 1, 0);
            ql = x + 1;
            qr = maxn - 1;
            y = min(y, query(0, maxn - 1, 0));
            res = (res + y) % MOD;
            p = x;
            v = ++count[x];
            update(0, maxn - 1, 0);
        }
        return res % MOD;
    }
};

int main() {
    Solution solu;
    vector<int> i = {1, 5, 6, 2};
    cout << solu.createSortedArray(i) << endl;
    return 0;
}
