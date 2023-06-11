#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    int count = 0;
    unordered_map<tuple<int, int, int>, int> t;
    unordered_map<int, int> cc;
    unordered_map<int, TreeNode *> ans;
    int dfs(TreeNode *root) {
        if (root) {
            int a = dfs(root->left);
            int b = dfs(root->right);
            if (t.count({a, b, root->val}) == 0) {
                t[{a, b, root->val}] = ++count;
            }
            int idx = t[{a, b, root->val}];
            ans[idx] = root;
            cc[idx]++;
            return idx;
        } else {
            return 0;
        }
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        dfs(root);
        vector<TreeNode *> ret;
        for (auto [k, v] : cc) {
            if (v > 1) ret.push_back(ans[k]);
        }
        return ret;
    }
};
int main() {
    Solution s;
    return 0;
}