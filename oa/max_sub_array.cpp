#include <iostream>
#include <vector>
using namespace std;

// 最大子数组
// leetcode 2321
// https://leetcode.cn/problems/maximum-score-of-spliced-array/

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

int main() {
    vector<int> vec = {1, 2, 3, 4, -23, 6, 7, 8};
    cout << maxSubArray(vec) << endl;
}