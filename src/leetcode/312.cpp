#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxCoins(vector<int> &n) {
        int l = n.size();
        if (l == 1) return 1;
        if (l == 2) return max(n[0], n[1]) + 1;
        // dp[i][j] = dp[i][k] + dp[k + 1][j] + n[i-1][j+1]
        vector<vector<int>> dp(l, vector<int>(l, 0));
        for (int i = 0; i < l; i++) {
            if (i == 0) dp[i][i] = n[i + 1];
            else if (i == l - 1)
                dp[i][i] = n[i - 1];
            else
                dp[i][i] = n[i - 1] * n[i + 1];
        }
        for (int k = 2; k <= l; k++) {
            for (int i = 0; i + k - 1 < l; i++) {
                for (int j = i; j < i + k; j++) {
                    int left = i - 1 >= 0 ? n[i - 1] : 1;
                    int right = i + k < l ? n[i + k] : 1;
                    int &v = dp[i][i + k - 1];
                    int ll = j - 1 >= i ? dp[i][j - 1] : 0;
                    int rr = i + 1 <= j ? dp[i + 1][j] : 0;
                    v = max(v, left * right + ll + rr);
                }
            }
        }
        return dp[0][l - 1];
    }
};

int main() {
    Solution solu;
    vector<int> n{3, 1, 5, 8};
    cout << solu.maxCoins(n) << endl;
    return 0;
}