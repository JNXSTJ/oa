#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
  public:
    vector<int>
    sortItems(int n, int m, vector<int> &group, vector<vector<int>> &b) {
        for (int i = 0; i < group.size(); i++) {
            if (group[i] == -1) group[i] = m++;
        }
        queue<int> que;
        vector<int> in(n, 0);
        vector<vector<int>> g(m, {});
        vector<vector<int>> edges(n);
        for (int i = 0; i < b.size(); i++) {
            for (int j = 0; j < b[i].size(); j++) {
                edges[b[i][j]].push_back(i);
            }
        }
        for (int i = 0; i < group.size(); i++) { g[group[i]].push_back(i); }
        for (int i = 0; i < n; i++) { in[i] = b[i].size(); }
        for (int i = 0; i < m; i++) {
            bool flag = true;
            for (int x : g[i]) {
                if (in[x]) {
                    flag = false;
                    break;
                }
            }
            if (flag) que.push(i);
        }
        cout << que.size() << endl;
        vector<int> res;
        map<int, int> count;
        for (int i = 0; i < g.size(); i++) count[i] = g[i].size();
        while (que.size()) {
            int x = que.front();
            cout << x << endl;
            que.pop();
            for (int t : g[x]) {
                res.push_back(t);
                for (int next : edges[t]) {
                    in[next]--;
                    if (in[next] == 0) {
                        count[group[next]]--;
                        if (count[group[next]] == 0) que.push(group[next]);
                    }
                }
            }
        }
        if (res.size() == n) return res;
        else
            return {};
    }
};

int main() {
    Solution solution;
    int n = 8;
    int m = 2;
    vector<int> g = {-1, -1, 1, 0, 0, 1, 0, -1};
    vector<vector<int>> pre = {{}, {6}, {5}, {6}, {3, 6}, {}, {}, {}};
    solution.sortItems(n, m, g, pre);
    return 0;
}