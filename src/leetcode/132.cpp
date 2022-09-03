#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    typedef vector<bool> vb;
    typedef vector<vector<bool>> vbb;
    int minCut(string s) {
        int l = s.size();
        vbb ss = vbb(s.size(), vb(s.size(), false));
        for (int i = 0; i < l; i++) ss[i][i] = true;
        for (int i = 2; i <= l; i++) {
            for (int j = 0; j + i < s.size(); j++) {
                if (i == 2) {
                    ss[j][j + 1] = s[j] == s[j + 1];
                } else {
                    ss[j][j + i - 1] =
                        s[j] == s[j + i - 1] and ss[j + 1][j + i - 2];
                }
            }
        }
        vector<int> ret(s.size(), INT_MAX);
        ret[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            if (ss[0][i]) {
                ret[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (ss[j + 1][i]) ret[i] = min(ret[i], ret[j] + 1);
            }
        }
        return ret.back();
    }
};

int main() {
    Solution s;
    std::cout << s.minCut("AA") << endl;
    return 0;
}