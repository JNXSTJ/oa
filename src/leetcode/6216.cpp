#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    long long minCost(vector<int> &nums, vector<int> &cost) {
        typedef long long ll;
        vector<pair<int, int>> vec;
        for (int i = 0; i < nums.size(); i++) {
            vec.push_back({nums[i], cost[i]});
        }
        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.first < b.first;
        });
        vector<ll> ps(cost.size());
        ps[0] = vec[0].first;
        for (int i = 1; i < vec.size(); i++) {
            ps[i] = ps[i - 1] + vec[i - 1].second;
        }
        ll sum1 = 0, sum2 = 0;
        ll v = vec.back().second;
        for (auto x : vec) { sum2 += (v - x.first) * x.second; }
        long long res = LONG_MAX;
        for (int i = 0; i < vec.size(); i++) {
            if (i > 0) {
                sum1 = sum1 + ps[i - 1] * (vec[i].first - vec[i - 1].first);
            }
            sum2 -= (v - vec[i].first) * vec[i].second;
            res = min(res, sum1 + sum2);
        }
        return res;
    }
};

int main() {
    Solution solu;
    vector<int> nums = {1, 3, 5, 2};
    vector<int> cost = {2, 3, 1, 14};
    cout << solu.minCost(nums, cost) << endl;
}