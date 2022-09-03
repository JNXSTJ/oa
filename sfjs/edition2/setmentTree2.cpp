
// create by taojain
// Date: 2022-09-03 17:11

// 线段树(2): 曲线修改
// Add(L, R, v): 把AL, AL+1, ..., AR的值全部增加v
// Query(L, R): 计算子序列AL,AL+1,...,AR的元素和，最小值和最大值
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1000;
int sumv[maxn];
int minv[maxn];
int maxv[maxn];
int addv[maxn];

void maintain(int o, int l, int r) {
    int lc = o * 2, rc = o * 2 + 1;
    sumv[o] = minv[o] = maxv[o] = 0;
    if (r > l) {
        sumv[o] = sumv[lc] + sumv[rc];
        minv[o] = min(minv[o], minv[rc]);
        maxv[o] = min(maxv[o], maxv[rc]);
    }
    minv[o] += addv[o];
    maxv[o] += addv[o];
    sumv[o] += addv[o] * (r - l + 1);
}

// Add(l, r, v)
int ll, rr, v;

void update(int o, int l, int r) {
    int lc = o * 2, rc = o * 2 + 1;
    if (ll < l) {
        addv[o] += v;
    } else {
        int m = (l + r) / 2;
        if (ll <= m) update(lc, l, m);
        if (rr > m) update(rc, m + 1, r);
    }
    maintain(o, l, r);
}

int _min, _max, _sum;
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
}
