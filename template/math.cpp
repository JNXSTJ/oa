#include <list>
using namespace std;

// 最大公因数
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 快速质因数分解
// C++ Version
list<int> breakdown(int N) {
    list<int> result;
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) { // 如果 i 能够整除 N，说明 i 为 N 的一个质因子。
            while (N % i == 0) N /= i;
            result.push_back(i);
        }
    }
    if (N != 1) { // 说明再经过操作之后 N 留下了一个素数
        result.push_back(N);
    }
    return result;
}
