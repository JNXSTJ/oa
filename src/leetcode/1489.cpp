#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int tree[101];
    int find_tree(int x) {
        return tree[x] == x ? x : tree[x] = find_tree(tree[x]);
    }
    int kruskal(int n, vector<vector<int>> &edges, int exclu, int inclu) {
        for (int i = 0; i < n; i++) tree[i] = i;
        int sum = 0;
        int count = n;
        if (inclu >= 0) {
            auto &e = edges[inclu];
            int a = e[0], b = e[1], c = e[2];
            int ta = find_tree(a), tb = find_tree(b);
            if (ta != tb) {
                tree[ta] = tb;
                sum += c;
            }
        }
        for (int i = 0; i < edges.size(); i++) {
            if (i == exclu) continue;
            auto &e = edges[i];
            int a = e[0], b = e[1], c = e[2];
            int ta = find_tree(a), tb = find_tree(b);
            if (ta != tb) {
                tree[ta] = tb;
                if (exclu == 3) cout << "edge index " << i << endl;
                sum += c;
            }
        }
        return sum;
    }
    vector<vector<int>>
    findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });
        int ret = kruskal(n, edges, -1, -1);
        cout << ret << endl;
        vector<vector<int>> ans(2);
        for (int i = 0; i < edges.size(); i++) {
            cout << "i: " << i << endl;
            int t = kruskal(n, edges, i, -1);
            cout << t << endl;
            if (t > ret) ans[0].push_back(i);
            int tt = kruskal(n, edges, -1, i);
            cout << tt << endl;
            if (t == ret and tt == ret) { ans[1].push_back(i); }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {0, 2, 1}, {2, 3, 4},
                                 {3, 4, 2}, {3, 5, 2}, {4, 5, 2}};
    solution.findCriticalAndPseudoCriticalEdges(6, edges);
    return 0;
}