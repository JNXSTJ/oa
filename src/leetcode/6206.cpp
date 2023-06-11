#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1e5 * 4 + 10;
int maxv[maxn] = {0};
int ql, qr; // 查询[ql, qr]中的最大值
int query(int o, int l, int r) {
    int m = (l + r) / 2, ans = INT_MIN;
    if (ql <= l and r <= qr) return maxv[o]; //当前节点完全包含在查询区间内
    if (ql <= m) ans = max(ans, query(o * 2, l, m));        //往左走
    if (m < qr) ans = max(ans, query(o * 2 + 1, m + 1, r)); // 往右走
    return ans;
}

int p, v;
void update(int o, int l, int r) {
    int m = (l + r) / 2;
    if (l == r) maxv[o] = v;
    else {
        if (p <= m) update(o * 2, l, m);
        else
            update(o * 2 + 1, m + 1, r);
        maxv[o] = max(maxv[o * 2], maxv[o * 2 + 1]);
    }
}

class Solution {
  public:
    int lengthOfLIS(vector<int> &nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            ql = max(nums[i] - k, 0);
            qr = max(nums[i] - 1, 0);
            int t = query(1, 0, 1e5);
            p = nums[i];
            v = t + 1;
            update(1, 0, 1e5);
        }
        return query(1, 0, 1e5);
    }
};

int main() {
    Solution solu;
    vector<int> d = {4, 2, 1, 4, 3, 4, 5, 8, 15};

    cout << solu.lengthOfLIS(d, 3) << endl;
    return 0;
}