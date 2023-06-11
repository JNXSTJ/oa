
// create by taojain
// Date: 2022-09-03 17:11

// 线段树(3): 曲间设置
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

void pushdown(int o) {
    int lc = o * 2, rc = o * 2 + 1;
    if (setv[o]
        >= 0) { // 本节点有标记才传递。注意本题中set值非负，所以-1代表没有标记
        setv[lc] = setv[rc] = setv[o];
        setv[o] = -1; // 清楚本节点标记
    }
}

int ll, rr, v; // 将区间[ll, rr]的元素的值设置为vv
void update(int o, int l, int r) {
    int lc = o * 2, rc = o * 2 + 1;
    if (ll <= l and rr >= r) {
        setv[o] = v;
    } else {
        pushdown(o);
        int m = (l + r) / 2;
        if (ll <= m) update(lc, l, m);
        else
            maintain(lc, l, m);
        if (rr > m) update(rc, m + 1, r);
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