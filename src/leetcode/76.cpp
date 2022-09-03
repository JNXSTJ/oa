#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    bool check(int count[256]) {
        for (int i = 0; i < 256; i++) {
            if (count[i] > 0) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int count[256] = {0};
        for (auto c : t) count[c]++;
        int l = 0, r = -1;
        int len = INT_MAX;
        int ll = -1, rr = -1;
        while (r < (int)(s.size())) {
            count[s[++r]]--;
            while (check(count)) {
                if (len > r - l + 1) {
                    len = r - l + 1;
                    ll = l;
                    rr = r;
                }
                count[s[l++]]++;
            }
        }
        return ll == -1 ? "" : s.substr(ll, rr - ll + 1);
    }
};

int main() {
    Solution s;
    std::cout << s.minWindow("ADOBECODEBANC", "ABC") << std::endl;
    return 0;
}