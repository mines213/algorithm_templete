#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
int parent[101];
int ran[101]; //rank

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    //union
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (ran[u] > ran[v]) {
        parent[v] = u;
    }
    else if (ran[u] < ran[v]) {
        parent[u] = v;
    }
    else {
        parent[v] = u;
        ran[u]++;
    }
}

int main() {
	fastio;
	int N;
	memset(ran,0,sizeof ran);
	for (int i=1; i<=N; i++) {
		parent[i]=i;
	}
	return 0;
}
