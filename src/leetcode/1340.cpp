#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int dfs(vector<int> &arr, int d, int idx, vector<int> &dp) {
        if (idx < 0 || idx >= arr.size()) return 0;
        if (dp[idx] > 0) return dp[idx];
        int res = 1;
        for (int i = -d; i <= d; i++) {
            if (i == 0) continue;
            if (idx + i >= 0 and idx + i < arr.size()
                and arr[i] > arr[idx + i]) {
                int ret = dfs(arr, d, idx + i, dp);
                res = max(res, ret + 1);
            }
        }
        dp[idx] = res;
        cout << idx << " " << res << endl;
        return res;
    }
    int maxJumps(vector<int> &arr, int d) {
        int res = 1;
        vector<int> dp(arr.size(), -1);
        for (int i = 0; i < arr.size(); i++) {
            res = max(res, dfs(arr, d, i, dp));
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> arr = {6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12};
    cout << s.maxJumps(arr, 2) << endl;
}