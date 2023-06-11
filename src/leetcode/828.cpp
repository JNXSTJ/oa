#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
  public:
    int len;
    int compute(vector<int> &c) {
        int ret = 0;
        if (c.size() == 0) return 0;
        int l, r;
        for (int i = 0; i < c.size(); i++) {
            if (c[i] == 0) l = 1;
            else if (i == 0)
                l = c[i] + 1;
            else
                l = c[i] - c[i - 1];
            if (c[i] == len - 1) r = 1;
            else if (i == c.size() - 1)
                r = len - c[i];
            else
                r = c[i + 1] - c[i];
            ret += r * l;
        }
        return ret;
    }
    int uniqueLetterString(string s) {
        int ret = 0;
        len = s.size();
        vector<vector<int>> count(256);
        for (int i = 0; i < s.size(); i++) { count[s[i]].push_back(i); }
        for (int i = 0; i < count.size(); i++) { ret += compute(count[i]); }
        return ret;
    }
};

int main() {
    Solution solu;
    cout << solu.uniqueLetterString("abc") << endl;
    return 0;
}