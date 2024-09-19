#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
#define X first
#define Y second
const int INF = 0x3f3f3f3f;

int v, e;
vector<pair<int, int> > adj[20005]; // {비용, 정점 번호}
int d[20005];

int main() {
    fastio;
    cin >> v >> e;
    fill(d, d + v + 1, INF);
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    int start;
    cin >> start;
    d[start] = 0;
    pq.push({d[start], start});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (d[cur.Y] != cur.X) continue;
        for (auto nxt: adj[cur.Y]) {
            if (d[nxt.Y] > d[cur.Y] + nxt.X) {
                d[nxt.Y] = d[cur.Y] + nxt.X;
                pq.push({d[nxt.Y], nxt.Y});
            }
        }
    }
    return 0;
}
