#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    int findMaximizedCapital(
        int k, int w, vector<int> &profits, vector<int> &capital) {
        int sz = profits.size();
        priority_queue<int, vector<int>, less<int>> pq;
        typedef pair<int, int> pii;
        vector<pii> v;
        for (int i = 0; i < profits.size(); i++) {
            v.push_back({capital[i], profits[i]});
        }
        sort(v.begin(), v.end());
        int res = 0, cur = 0;
        for (int i = 0; i < k; i++) {
            while (cur < sz and v[cur].first <= w) { pq.push(v[cur++].second); }
            if (pq.size()) {
                w += pq.top();
                pq.pop();
            } else
                break;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> p{1, 2, 3};
    vector<int> c{0, 1, 1};
    cout << sol.findMaximizedCapital(2, 0, p, c) << endl;
}