
// create by taojain
// Date: 2022-09-03 17:11

// 线段树(2): 曲间修改
// Add(L, R, v): 把AL, AL+1, ..., AR的值全部增加v
// Query(L, R): 计算子序列AL,AL+1,...,AR的元素和，最小值和最大值
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>
#include <stdio.h>

using namespace std;

const int maxn = 1000 * 4 + 10;
int sumv[maxn];
int minv[maxn];
int maxv[maxn];
int addv[maxn];

void maintain(int o, int l, int r) {
    int lc = o * 2, rc = o * 2 + 1;
    sumv[o] = minv[o] = maxv[o] = 0;
    if (r > l) {
        sumv[o] = sumv[lc] + sumv[rc];
        minv[o] = min(minv[lc], minv[rc]);
        maxv[o] = max(maxv[lc], maxv[rc]);
    }
    minv[o] += addv[o];
    maxv[o] += addv[o];
    sumv[o] += addv[o] * (r - l + 1);
}

// Add(l, r, v)
int ll, rr, v;

void update(int o, int l, int r) {
    int lc = o * 2, rc = o * 2 + 1;
    if (ll <= l and rr >= r) {
        addv[o] += v;
    } else {
        int m = (l + r) / 2;
        if (ll <= m) update(lc, l, m);
        if (rr > m) update(rc, m + 1, r);
    }
    maintain(o, l, r);
}

int _min, _max, _sum; // 全局变量，目前位置的最小值、最大值和累加和
void query(int o, int l, int r, int add) {
    if (ll <= l and rr >= r) {
        _sum += sumv[o] + add * (r - l + 1);
        _min = min(_min, minv[o] + add);
        _max = max(_max, maxv[o] + add);
    } else {
        int m = (l + r) / 2;
        if (ll <= m) query(o * 2, l, m, add + addv[o]);
        if (rr > m) query(o * 2 + 1, m + 1, r, add + addv[o]);
    }
}

int main() {
    memset(sumv, 0, sizeof(sumv));
    memset(minv, 0, sizeof(minv));
    memset(maxv, 0, sizeof(maxv));

    int start = 0, end = 999;
    ll = 0, rr = 1, v = 2;
    update(1, start, end);

    ll = 0, rr = 3, v = 3;
    update(1, start, end);

    ll = 0, rr = 2;
    _sum = 0;
    _max = INT_MIN;
    _min = INT_MAX;
    query(1, start, end, 0);
    cout << _min << endl;
    cout << _max << endl;
    cout << _sum << endl;
}
