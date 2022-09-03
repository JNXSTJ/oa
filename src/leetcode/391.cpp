#include <iostream>
#include <vector>

using namespace std;
class Solution {
  public:
    typedef vector<vector<int>> vii;
    bool flag;
    vector<vector<int>> change(vector<vector<int>> &a) {
        vector<vector<int>> ans;
        sort(a.begin(), a.end(), [](auto &x, auto &y) { return x[0] < y[0]; });
        for (int i = 0; i < a.size(); i++) {
            if (ans.size() == 0) ans.push_back(a[i]);
            else {
                if (ans.back()[1] == a[i][0]) {
                    ans.back()[1] = a[i][1];
                } else if (ans.back()[1] < a[i][0]) {
                    ans.push_back(a[i]);
                } else {
                    flag = false;
                    return {};
                }
            }
        }
        return ans;
    }
    bool judge(vector<vector<int>> &a, vector<vector<int>> &b) {
        // if (a.size() != b.size()) return false;
        vii x = change(a), y = change(b);
        if (x.size() != y.size()) return false;
        if (flag == false) return false;
        for (int i = 0; i < x.size(); i++) {
            if (x[i][0] != y[i][0] or x[i][1] != y[i][1]) return false;
        }
        return true;
    }
    bool isRectangleCover(vector<vector<int>> &r) {
        flag = true;
        vector<vector<int>> v;
        int min_x = INT_MAX, max_x = INT_MIN;
        for (auto x : r) {
            v.push_back({x[0], x[1], x[3], 0});
            v.push_back({x[2], x[1], x[3], 1});
            min_x = min(min_x, x[0]);
            max_x = max(max_x, x[2]);
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b) { return a[0] < b[0]; });
        vector<vector<int>> b[2];
        for (int i = 0; i < v.size();) {
            if (v[i][0] == min_x) {
                b[0].push_back({v[i][1], v[i][2]});
                i++;
            } else if (v[i][0] == max_x) {
                b[1].push_back({v[i][1], v[i][2]});
                i++;
            } else {
                vector<vector<int>> a[2];
                int start = i;
                while (v[i][0] == v[start][0]) {
                    a[v[i][3]].push_back({v[i][1], v[i][2]});
                    i++;
                }
                if (judge(a[0], a[1]) == false) {
                    cout << v[start][0] << endl;
                    return false;
                }
            }
        }
        if (judge(b[0], b[1]) == false) return false;
        return true;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> res = {{0, 0, 4, 1}, {7, 0, 8, 2}, {6, 2, 8, 3},
                               {5, 1, 6, 3}, {4, 0, 5, 1}, {6, 0, 7, 2},
                               {4, 2, 5, 3}, {2, 1, 4, 3}, {0, 1, 2, 2},
                               {0, 2, 2, 3}, {4, 1, 5, 2}, {5, 0, 6, 1}};
    cout << solution.isRectangleCover(res) << endl;
    return 0;
}