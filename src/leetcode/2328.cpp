#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int MOD = 1e9 + 7;
    int dxs[4] = {-1, 0, 1, 0};
    int dys[4] = {0, 1, 0, -1};
    int m, n;
    int get(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &g) {
        int ret = 1;
        if (!(i >= 0 and i < n and j >= 0 and j < m)) return 0;
        if (dp[i][j] > -1) return dp[i][j];
        for (int k = 0; k < 4; k++) {
            int nx = i + dxs[k];
            int ny = j + dys[k];
            if ((nx >= 0 and nx < n and ny >= 0 and ny < m)
                and g[i][j] > g[nx][ny]) {
                ret = (ret + get(nx, ny, dp, g)) % MOD;
            }
        }
        dp[i][j] = ret;
        return ret;
    }
    int countPaths(vector<vector<int>> &g) {
        int res = 0;
        n = g.size(), m = g.back().size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = (res + get(i, j, g, dp)) % MOD;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) { cout << dp[i][j] << endl; }
        }
        return res;
    }
};

int main() {
    Solution solu;
    vector<vector<int>> g = {{1, 1}, {3, 4}};
    cout << solu.countPaths(g) << endl;
}