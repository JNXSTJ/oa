
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> gen(vector<int> &vec) {
    sort(vec.begin(), vec.end());
    vector<int> ret;
    priority_queue<
        pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
        que;
    que.push(make_pair(vec[0], 0));
    while (que.size()) {
        auto t = que.top();
        que.pop();
        int v = t.first;
        int idx = t.second;
        ret.push_back(v);
        if (idx + 1 < vec.size()) {
            que.push(make_pair(v - vec[idx] + vec[idx + 1], idx + 1));
            que.push(make_pair(v + vec[idx + 1], idx + 1));
        }
    }
    return ret;
}

int main() {
    vector<int> vec{1, 2, 3, 4, 5, 0, 1, 1, 2};
    auto ret = gen(vec);
    for (auto x : ret) { cout << x << endl; }
    return 0;
}
