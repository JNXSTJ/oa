#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
  public:
    typedef long long ll;
    ll get(ll k, ll m) {
        ll res = 0;
        ll mul = 1;
        for (int i = 0; i < m; i++) {
            res += mul;
            mul *= k;
        }
        return res;
    }
    string smallestGoodBase(string n) {
        /*
        cout << get(496, 7) << endl;
        ll n_val = stol(n);
        int bits_max = float(log(n_val) / log(2));
        for (int m = bits_max; m >= 2; m--)
        {
            int k = pow(n_val, 1.0/m);
            cout << m << " " << k << endl;
            if (get(k, m) == n_val) {
                return to_string(k);
            }
        }
        return to_string(n_val - 1);
        */
        long nVal = stol(n);
        int mMax = floor(log(nVal) / log(2));
        for (int m = mMax; m > 1; m--) {
            int k = pow(nVal, 1.0 / m);
            long mul = 1, sum = 1;
            for (int i = 0; i < m; i++) {
                mul *= k;
                sum += mul;
            }
            if (sum == nVal) { return to_string(k); }
        }
        return to_string(nVal - 1);
    }
};

int main() {
    Solution solu;
    cout << solu.smallestGoodBase("3") << endl;
    return 0;
}