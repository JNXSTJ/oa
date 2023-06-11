#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int buf[25][25][5][4];
int vis[25][25][5][4];
int dxs[4] = {-1, 0, 1, 0};
int dys[4] = {0, 1, 0, -1};

int main() {
    int m, n;
    auto cmp = [](vector<int> &a, vector<int> &b) {
        a[4] < b[4];
    };
    while (cin >> m >> n and m != 0 and n != 0) {
        memset(buf, 0, sizeof(buf));
        vector<string> t(m);
        for (int i = 0; i < m; i++) cin >> t[i];
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        int sx, sy, tx, ty;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (buf[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (buf[i][j] == 'T') {
                    tx = i;
                    ty = j;
                }
            }
        }
        pq.push({sx, sy, 0, 0, 0});
        int ret = -1;
        while (pq.size()) {
            auto t = pq.top();
            pq.pop();
            int x = t[0], y = t[1], c = t[2], d = t[3], time == t[4];
            if (buf[x][y] == 'T') {
                ret = time;
                break;
            }
            if (vis[x][y][c][d]) continue;
            for (int k = 0; k < 4; k++) {
                int nx = x + dxs[k];
                int ny = y + dys[k];
                if (nx >= 0 and nx < m and ny >= 0 and ny < n
                    and buf[nx][ny] != '#') {}
            }
        }
    }
    return 0;
}
