#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    int maximumSwap(int num) {
        if (num == 0) return 0;
        vector<int> tmp;
        while (num != 0) {
            tmp.push_back(num % 10);
            num /= 10;
        }
        for (int i = tmp.size() - 1; i >= 0; i--) {
            int idx = 0;
            for (int j = 0; j < i; j++) {
                if (tmp[idx] > tmp[j]) idx = j;
            }
            if (tmp[idx] > tmp[i]) {
                cout << idx << endl;
                cout << i << endl;
                swap(tmp[idx], tmp[i]);
                break;
            }
        }
        int ret = 0;
        for (int i = tmp.size() - 1; i >= 0; i--) ret = ret * 10 + tmp[i];
        return ret;
    }
};

int main() {
    Solution solution;
    solution.maximumSwap(2736);
}