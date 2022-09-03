#include <queue>
#include <iostream>

using namespace std;

int main() {
    auto cmp = [&](int &a, int &b) {
        return a < b;
    };
    // 这个是大顶堆，奇怪
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    pq.push(1);
    pq.push(2);
    pq.push(3);
    while (pq.size()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    // 大根堆
    priority_queue<int, vector<int>, less<int>> pq1;
    cout << endl;
    pq1.push(1);
    pq1.push(2);
    pq1.push(3);
    while (pq1.size()) {
        cout << pq1.top() << " ";
        pq1.pop();
    }
    // 小根堆
    priority_queue<int, vector<int>, greater<int>> pq2;
    cout << endl;
    pq2.push(1);
    pq2.push(2);
    pq2.push(3);
    while (pq2.size()) {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    return 0;
}