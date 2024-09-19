#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define fastio ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
int d[105][105];

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        fill(d[i], d[i] + N + 1, 0x3f3f3f3f);
        d[i][i] = 0;
    }
    while (M--) {
        int s, e, w;
        cin >> s >> e >> w;
        d[s][e] = min(d[s][e], w);
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    return 0;
}
