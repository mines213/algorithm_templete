#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define fastio ios::sync_with_stdio(0), cin.tie(0);
using namespace std;

vector<vector<pair<ll,ll> > > edges;
ll dist[501];

int main() {
    fastio;
    int V, E;
    cin >> V >> E;
    edges.resize(V + 1);
    fill(dist, dist + V + 1, 0x7f7f7f7f);
    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({w, v});
    }
    dist[1] = 0;
    for (int tc = 0; tc < V - 1; tc++) {
        for (int i = 1; i <= V; i++) {
            if (dist[i] == 0x7f7f7f7f) continue;
            for (const auto &[w,e]: edges[i]) {
                if (dist[e] > dist[i] + w) {
                    dist[e] = dist[i] + w;
                }
            }
        }
    }
    //음수 사이클 확인
    bool cycle=false;
    for (int i = 1; i <= V; i++) {
        if (dist[i] == 0x7f7f7f7f) continue;
        for (const auto &[w,e]: edges[i]) {
            if (dist[e] > dist[i] + w) {
                cycle=true;
            }
        }
    }
    return 0;
}
