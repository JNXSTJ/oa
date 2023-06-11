#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &m) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) { pq.push(i); }
        sort(m.begin(), m.end(), [](auto &a, auto &b) { return a[0] < b[0]; });
        auto cmp = [](pair<int, int> &a, pair<int, int> &b) {
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
            pq2(cmp);
        map<int, int> count;
        for (int i = 0; i < m.size(); i++) {
            auto &t = m[i];
            int s = t[0], e = t[1];
            while (pq2.size() and s > pq2.top().first) {
                pq.push(pq2.top().second);
                pq2.pop();
            }
            if (pq.size()) {
                pq2.push({e - 1, pq.top()});
                count[pq.top()]++;
                pq.pop();
            } else {
                auto t = pq2.top();
                pq2.pop();
                count[t.second]++;
                pq2.push({t.first + e - s, t.second});
            }
        }
        int res = 0;
        int kk = -1;
        for (auto [k, v] : count) {
            if (v > res) {
                res = v;
                kk = k;
            } else if (v == res) {
                kk = min(kk, k);
            }
        }
        return kk;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> t = {{19, 20}, {14, 15}, {13, 14}, {11, 20}};
    cout << solution.mostBooked(2, t) << endl;
    return 0;
}