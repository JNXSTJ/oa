#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    bool judge(vector<int> &count) {
        for (int i = 0; i < count.size(); i++) {
            if (count[i] > 1) return false;
        }
        return true;
    }
    int longestNiceSubarray(vector<int> &nums) {
        int res = 1;
        vector<int> count(32, 0);
        int s = 0, e = 0;
        while (e < nums.size()) {
            int t = nums[e];
            int idx = 0;
            bool flag = true;
            while (t) {
                if (t & 1) {
                    if (++count[idx] > 1) { flag = false; }
                }
                t = t >> 1;
                idx++;
            }
            if (flag) res = max(res, e - s + 1);
            else {
                while (s < e) {
                    t = nums[s];
                    idx = 0;
                    while (t) {
                        if (t & 1) {
                            if (++count[idx] > 1) { flag = false; }
                        }
                        t = t >> 1;
                        idx++;
                    }
                    s++;
                    if (judge(count)) break;
                }
            }
            e++;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> t = {1, 3, 8, 48, 10};
    cout << solution.longestNiceSubarray(t) << endl;
    return 0;
}