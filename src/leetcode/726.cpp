#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
  public:
    typedef map<string, int> type;
    bool digit(char c) { return c >= '0' and c <= '9'; }
    int get_num(string &f, int &idx) {
        int ret = 0;
        while (idx < f.size() and digit(f[idx])) {
            ret = ret * 10 + f[idx] - '0';
            idx++;
        }
        return ret;
    }
    bool upper(char c) { return c >= 'A' and c <= 'Z'; }
    bool lower(char c) { return c >= 'a' and c <= 'z'; }
    string get(string &f, int &idx) {
        int start = idx;
        idx++;
        while (idx < f.size() and lower(f[idx])) { idx++; }
        return f.substr(start, idx - start);
    }

    type compute(string &f, int &idx) {
        if (idx >= f.size()) return type();
        if (f[idx] == '(') {
            idx++;
            type ret = compute(f, idx);
            idx++;
            if (idx > f.size()) return ret;
            int num = 1;
            if (digit(f[idx])) { num = get_num(f, idx); }
            for (auto [k, v] : ret) { ret[k] = v * num; }
            auto ret2 = compute(f, idx);
            for (auto [k, v] : ret2) { ret[k] += v; }
            return ret;
        } else {
            type ret;
            while (idx < f.size() and upper(f[idx])) {
                ret[get(f, idx)] += get_num(f, idx);
            }
            return ret;
        }
    }
    string countOfAtoms(string formula) {
        int idx = 0;
        type ans = compute(formula, idx);
        string res;
        for (auto [k, v] : ans) {
            res += k;
            res += to_string(v);
        }
        return res;
    }
};

int main() {
    Solution solu;
    cout << solu.countOfAtoms("H2O") << endl;
    return 0;
}