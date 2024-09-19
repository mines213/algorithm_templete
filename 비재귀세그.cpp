#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0);
using namespace std;

//구간합 활용 1. kth
//구간합 활용 2. Inversion counting
//걍 무조건 long long 써라
int tree_size, base;
vector<ll> seg_tree;

void init(int size) {
    tree_size = size;
    seg_tree.clear();
    seg_tree.resize(tree_size << 2, 0);
    for (base = 1; base < tree_size; base <<= 1);
}

void update(int i, ll x) {
    i += base;
    seg_tree[i] = x;
    for (i = i >> 1; i > 0; i = i >> 1)
        seg_tree[i] = seg_tree[i << 1] + seg_tree[i << 1 | 1];
}

ll query(int p, int q) {
    // [p,q]
    p += base, q += base;

    ll ret = 0;
    while (p < q) {
        if (p & 1) ret = ret + seg_tree[p++];
        if (~q & 1) ret = ret + seg_tree[q--];

        p = p >> 1, q = q >> 1;
    }

    if (p == q) ret = ret + seg_tree[p];
    return ret;
}

int top_down_query(ll k) {
    int d = 1;
    while (d < base) {
        if (seg_tree[d << 1] >= k)
            d = d << 1;
        else {
            k -= seg_tree[d << 1];
            d = d << 1 | 1;
        }
    }
    return d - base;
}

int main() {
    fastio;
    int N;
    cin >> N;
    init(N);
    return 0;
}
