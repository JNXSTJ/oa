#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
  public:
    typedef long long ll;
    struct node {
        ll t, c;
        node(int t, int c) : t(t), c(c) {}
    };

    int maximumRobots(
        vector<int> &chargeTimes, vector<int> &runningCosts, long long budget) {
        ll sum = accumulate(runningCosts.begin(), runningCosts.end(), 0);
        auto cmp = [](node &a, node &b) {
            return a.t < b.t || a.t == b.t and a.c > b.c;
        };
        priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < runningCosts.size(); ++i) {
            pq.push({chargeTimes[i], runningCosts[i]});
        }
        ll res = 0;
        while (pq.size()) {
            auto tmp = pq.top();
            ll k = min((ll)pq.size(), (budget - tmp.t) / sum);
            res = max(k, res);
            sum -= tmp.c;
            pq.pop();
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> c = {3, 6, 1, 3, 4};
    vector<int> r = {2, 1, 3, 4, 5};
    int b = 25;
    cout << s.maximumRobots(c, r, b) << endl;
}