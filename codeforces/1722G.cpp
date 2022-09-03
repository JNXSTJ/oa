#include <vector>
#include <iostream>
//#define DEBUG

using namespace std;

int main() {
#ifdef DEBUG
    if (freopen("./a.in", "r", stdin) == NULL) //将输入重定向为从文件a.in读入
        cout << "Open a.in failed" << endl;

#endif

    string tt("Timur");
    sort(tt.begin(), tt.end());
    int t, n;
    cin >> t;
    string str;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cin >> str;
        sort(str.begin(), str.end());
        cout << (str == tt ? "YES" : "NO") << endl;
    }
    return 0;
}