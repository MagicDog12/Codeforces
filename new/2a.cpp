#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+2;

int t[N][N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool vis[N][N];
int viscnt;

void bfs(int sx, int sy) {
    vis[sx][sy] = 1;
    viscnt = 1;
    queue<pair<int,int>> Q;
    Q.push({sx, sy});
    while(!Q.empty()) {
        auto u = Q.front();
        Q.pop();
        int x = u.first, y = u.second;
        for(int i=0; i<4; ++i) {
            if(~t[x][y] >> i&1) {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if(min(tx, ty) < 0 || max(tx, ty) >= N) continue;
                if(!vis[tx][ty]) {
                    vis[tx][ty] = 1;
                    ++viscnt;
                    Q.push({tx, ty});
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int x0, y0;
    cin >> x0 >> y0;
    for(int i=0; i<n; ++i) {
        int x, y;
        cin >> x >> y;
        if(x == x0) {
            for(int yy = max(y0, y); yy > min(y0,y); --yy) {
                t[x][yy] |= 1;
                t[x-1][yy] |= 2;
            }
        } else {
            for(int xx = min(x0, x); xx < max(x0, x); ++xx) {
                t[xx][y] |= 4;
                t[xx][y+1] |=8;
            }
        }
        x0 = x;
        y0 = y;
    }
    bfs(0,0);
    int ans = 0;
    for(int i=1; i<N; ++i) {
        for(int j=1; j<N; ++j) {
            if(!vis[i][j]) {
                viscnt = 0;
                bfs(i, j);
                ans = max(ans, viscnt);
            }
        }
    }
    cout << ans << endl;
    return 0;
}