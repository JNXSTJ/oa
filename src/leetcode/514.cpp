#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution {
  public:
    int findRotateSteps(string ring, string key) {
        int sz = ring.size();
        vector<vector<int>> dp;
        map<char, vector<int>> c;
        for (int i = 0; i < ring.size(); i++) { c[ring[i]].push_back(i); }
        dp.push_back(vector<int>(c[key[0]].size()));
        for (int j = 0; j < c[key[0]].size(); j++) {
            int idx = c[key[0]][j];
            dp[0][j] = min(idx, abs(sz - idx));
        }
        for (int i = 1; i < key.size(); i++) {
            dp.push_back(vector<int>(c[key[i]].size(), INT_MAX));
            for (int j = 0; j < c[key[i]].size(); j++) {
                int idx1 = c[key[i]][j];
                for (int k = 0; k < c[key[i - 1]].size(); k++) {
                    int idx2 = c[key[i - 1]][k];
                    int v = min(abs(idx2 - idx1), sz - abs(idx2 - idx1));
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + v);
                }
            }
        }
        int ret = INT_MAX;
        for (auto x : dp.back()) { ret = min(ret, x); }
        return ret + key.size() + 1;
    }
};

int main() {
    Solution solu;
    cout << solu.findRotateSteps("godding", "gd") << endl;
    return 0;
}