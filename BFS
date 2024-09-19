#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
#define X first
#define Y second

int N,M;
int board[100][100];
bool visited[100][100];
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
int main() {
    fastio;
    cin >> N >> M; //세로 , 가로
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }
    queue<pair<int,int>> Q;
    visited[0][0]=true;
    Q.push({0,0});
    while(!Q.empty()) {
        pair<int,int> cur=Q.front(); Q.pop();
        for (int i=0; i<4; i++) {
            int nx=cur.X+dx[i];
            int ny=cur.Y+dy[i];
            if (nx<0 || nx>=M || ny<0 || ny>=N) continue;
            if (visited[ny][nx]==true || board[ny][nx]==1) continue;
            visited[ny][nx]=true;
            Q.push({nx,ny});
        }
    }
    return 0;
}
