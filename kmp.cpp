#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define fastio ios::sync_with_stdio(0), cin.tie(0);
using namespace std;

vector<int> failure(string &p) {
    int n = p.size();
    vector<int> f(n);
    f[0] = 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && p[i] != p[j]) j = f[j - 1];
        if (p[i] == p[j]) {
            f[i] = ++j;
        }
    }
    return f;
}

vector<int> kmp(string &s, string &p) {
    vector<int> first_index;
    int n = s.size(), m = p.size();
    vector<int> pi = failure(p);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) j = pi[j - 1];
        if (s[i] == p[j]) {
            if (j == m - 1) {
                first_index.push_back(i - m + 1);
                j = pi[j];
            } else j++;
        }
    }
    return first_index;
}

int main() {
    fastio;
    int N;
    cin >> N;
    return 0;
}
