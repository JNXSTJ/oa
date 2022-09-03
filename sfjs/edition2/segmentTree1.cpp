
/*
线段树模板，点修改
动态范围最小值问题。给出一个有n个元素的数组A1，A2，...,An,你的任务是设计一个数据结构，支持以下两种操作。
- Update(x, v): 把Ax修改为v
- Query(L, R): 计算min{AL, AL+1, ..., AR}

leeetcode
https://leetcode.cn/problems/create-sorted-array-through-instructions/submissions/
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

static const int maxn = 4 * 10 + 10;

class SegmentTree {
  public:
    // A数组长度为n
    SegmentTree(int n) {
        len = n;
        memset(minv, 0, sizeof(int) * maxn);
        memset(sumv, 0, sizeof(int) * maxn);
    }
    int query(int l, int r) {
        ql = l;
        qr = r;
        return _query(1, 0, len - 1);
    }
    void update(int p, int v) {
        this->p = p;
        this->v = v;
        _update(1, 0, len - 1);
    }

  private:
    int ql, qr; // 查询[ql, qr]中的最小值
    int _query(int o, int l, int r) {
        int m = (l + r) / 2, ans = 0;
        if (ql <= l and r <= qr) return sumv[o]; //当前节点完全包含在查询区间内
        if (ql <= m) ans += _query(o * 2, l, m);        //往左走
        if (m < qr) ans += _query(o * 2 + 1, m + 1, r); // 往右走
        return ans;
    }

    int p, v;
    void _update(int o, int l, int r) {
        int m = (l + r) / 2;
        if (l == r) sumv[o] = v;
        else {
            if (p <= m) _update(o * 2, l, m);
            else
                _update(o * 2 + 1, m + 1, r);
            sumv[o] = sumv[o * 2] + sumv[o * 2 + 1];
        }
    }
    int minv[maxn];
    int sumv[maxn];
    int len;
};

class Solution {
  public:
    const int MOD = 1e9 + 7;
    typedef long long ll;
    int createSortedArray(vector<int> &i) {
        map<int, int> count;
        SegmentTree st(10);
        ll res = 0;
        for (auto x : i) {
            int y = st.query(0, x - 1);
            y = min(y, st.query(x + 1, 10 - 1));
            res = (res + y) % MOD;
            st.update(x, ++count[x]);
            int i = 0;
        }
        return res % MOD;
    }
};

int main() {
    Solution s;
    vector<int> i = {1, 5, 6, 2};
    cout << s.createSortedArray(i) << endl;
}