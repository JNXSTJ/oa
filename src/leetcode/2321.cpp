#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
  public:
    int maxSubArray(vector<int> &vec) {
        int sum = vec[0];
        int ret = vec[0];
        int min_sum = sum;
        for (int i = 0; i < vec.size(); i++) {
            sum += vec[i];
            ret = max(ret, sum - min_sum);
            min_sum = min(min_sum, sum);
        }
        return ret;
    }
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2) {
        vector<int> a, b;
        for (int i = 0; i < nums1.size(); i++) {
            a.push_back(nums2[i] - nums1[i]);
            b.push_back(-a.back());
        }
        int sum_a = accumulate(a.begin(), a.end(), 0);
        int sum_b = accumulate(b.begin(), b.end(), 0);
        return max(sum_a + maxSubArray(a), sum_b + maxSubArray(b));
    }
};

int main() {
    Solution s;
    vector<int> a{60, 60, 60};
    vector<int> b{10, 90, 10};
    cout << s.maximumsSplicedArray(a, b) << endl;
}