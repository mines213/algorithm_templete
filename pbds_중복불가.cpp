#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define X first
#define Y second
#define fastio ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    fastio;
    ordered_set OS;
    int N;
    cin >> N;
    return 0;
}

//내림차순 정렬 : less<int> 를 greater<int>로 변경
//커스텀 정렬 예시 :
#define ordered_set tree<edge, null_type, less<edge>, rb_tree_tag,tree_order_statistics_node_update>
struct edge {
    int cnt = 0;
    int panalty = 0;
    bool operator<(const edge &r) const {
        if (cnt == r.cnt) {
            return panalty < r.panalty;
        }
        return cnt > r.cnt;
    }
};
/*
특징 : 중복 불가, O(log n)

기본 기능 : 삽입 삭제 검색 
OS.insert(n);
OS.erase(n);
OS.find(n);
OS.clear()
OS.size()
OS.empty()
OS.begin()
OS.end()
OS.lower_bound()
OS.upper_bound()


pbds의 고유 기능 (세그와 동일한 시간 복잡도이나 상수가 느림)

1. K번째로 작은 원소 찾기 (이터레이타 반환, 가장 작은 걸 찾을려면 0 넣기, 없으면 OS.end() 반환)

OS.find_by_order(k)

2. K보다 작은 원소 개수 찾기

OS.order_of_key(k)

*/
