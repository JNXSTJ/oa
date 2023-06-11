
// create by taojain
// Date: 2022-09-03 22:15

// 线段树(4): 曲间设置,动态开点,范围很大，不适合一开始就建树
// Set(L, R, v): 把AL, AL+1, ..., AR的值全部修改为v
// Query(L, R): 计算子序列AL,AL+1,...,AR的元素和，最小值和最大值
#include <vector>
#include <iostream>
using namespace std;

const int maxn = 1000 * 4 + 10;
int sumv[maxn];
int minv[maxn];
int maxv[maxn];
int setv[maxn] = {-1};

struct node {
    int left, right;
    int sum;
    int setv;
    node *left_son, *right_son;
};

void maintain(int o, int l, int r) {
    int lc = o * 2, rc = o * 2 + 1;
    sumv[o] = minv[o] = maxv[o] = 0;
    if (r > l) {
        sumv[o] = sumv[lc] + sumv[rc];
        minv[o] = min(minv[lc], minv[rc]);
        maxv[o] = max(maxv[lc], maxv[rc]);
    }
    minv[o] = setv[o];
    maxv[o] = setv[o];
    sumv[o] = setv[o] * (r - l + 1);
}

void pushdown(node o) {
    int lc = o * 2, rc = o * 2 + 1;
    if (setv[o]
        >= 0) { // 本节点有标记才传递。注意本题中set值非负，所以-1代表没有标记
        setv[lc] = setv[rc] = setv[o];
        setv[o] = -1; // 清楚本节点标记
    }
}

int ll, rr, v;
void update(node n) {
    int l = n.left, r = n.right;
    node *left_son = n.left_son;
    node *right_son = n.right_son;
    if (ll <= l and rr >= r) {
        n.setv = v;
    } else {
        if (left_son == nullptr) { n.left_son = new node(); }
        if (right_son == nullptr) { n.right_son = new node(); }
        pushdown(n);
        int m = (l + r) / 2;
        if (ll <= m) update(n->left_son);
        else
            maintain(lc, l, m);
        if (rr > m) update(n->right_son);
        else
            maintain(rc, m + 1, r);
    }
    maintain(o, l, r);
}

int _sum, _min, _max;
void query(int o, int l, int r) {
    if (setv[o] >= 0) {
        _sum += setv[o] * (min(r, rr) - max(l, ll) + 1);
        _min = min(_min, setv[o]);
        _max = max(_max, setv[o]);
    } else if (ll <= l and rr >= r) {
        _sum += sumv[o];
        _min = min(_min, minv[o]);
        _max = max(_max, maxv[o]);
    } else {
        int m = (l + r) / 2;
        if (ll <= m) query(o * 2, l, m);
        if (rr > m) query(o * 2 + 1, m + 1, r);
    }
}

int main() {
    memset(sumv, 0, sizeof(sumv));
    memset(minv, 0, sizeof(minv));
    memset(maxv, 0, sizeof(maxv));
    memset(setv, -1, sizeof(setv));

    int start = 0, end = 999;
    ll = 0, rr = 1, v = 2;
    update(1, start, end);

    ll = 0, rr = 3, v = 3;
    update(1, start, end);

    ll = 0, rr = 2;
    _sum = 0;
    _max = INT_MIN;
    _min = INT_MAX;
    query(1, start, end);
    cout << _min << endl;
    cout << _max << endl;
    cout << _sum << endl;
}