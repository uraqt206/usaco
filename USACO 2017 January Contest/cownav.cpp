#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l; i>=(r); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()

const int INF = 2e9;
const int N = 21;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int n, m;
char a[N][N];
int dp[N][N][4][N][N][4];

struct state {
  int x1, y1, v1;
  int x2, y2, v2;

  state(int _x1=0, int _y1=0, int _v1=0, int _x2=0, int _y2=0, int _v2=0) {
    x1 = _x1; y1 = _y1; v1 = _v1;
    x2 = _x2; y2 = _y2; v2 = _v2;
  }

  int value() {
    return dp[x1][y1][v1][x2][y2][v2];
  }

  friend state walk(state to, int dir1, int dir2) {
    to.v1 = dir1; to.v2 = dir2;
    
    if ((to.x1 != 1) || (to.y1 != n)) {
      to.x1 += dx[dir1]; to.y1 += dy[dir1];
      if (to.x1 < 1) to.x1 = 1; if (to.x1 > n) to.x1 = n;
      if (to.y1 < 1) to.y1 = 1; if (to.y1 > n) to.y1 = n;
      if (a[to.x1][to.y1] == 'H') {
        to.x1 -= dx[dir1];
        to.y1 -= dy[dir1];
      }
    }
    
    if ((to.x2 != 1) || (to.y2 != n)) {
      to.x2 += dx[dir2]; to.y2 += dy[dir2];
      if (to.x2 < 1) to.x2 = 1; if (to.x2 > n) to.x2 = n;
      if (to.y2 < 1) to.y2 = 1; if (to.y2 > n) to.y2 = n;
      if (a[to.x2][to.y2] == 'H') {
        to.x2 -= dx[dir2];
        to.y2 -= dy[dir2];
      }
    }

    return to;
  }
};

queue<state> bfs;

void relax(state at, int d) {
  int &cur = dp[at.x1][at.y1][at.v1][at.x2][at.y2][at.v2];
  if (cur == -1) {
    cur = d;
    bfs.push(at);
  }
}

void solve() {
  cin >> n;

  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      cin >> a[i][j];
    }
  }

  memset(dp, -1, sizeof(dp));
  dp[n][1][0][n][1][1] = 0;
  bfs.push(state(n, 1, 0, n, 1, 1));

  while (!bfs.empty()) {
    auto at = bfs.front(); bfs.pop();

    for(int x : {-1, 1}) {
      int v1 = (at.v1 + x + 4) % 4;
      int v2 = (at.v2 + x + 4) % 4;
      state to = at; to.v1 = v1; to.v2 = v2;
      relax(to, at.value() + 1);
    }

    state to = walk(at, at.v1, at.v2);
    relax(to, at.value() + 1);
  }

  int ans = INF;
  for(int i=0; i<4; ++i)
    for(int j=0; j<4; ++j) if (dp[1][n][i][1][n][j] != -1)
      ans = min(ans, dp[1][n][i][1][n][j]);
  
  cout << ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("input.inp", "r")) {
    freopen("input.inp", "r", stdin);
    freopen("input.out", "w", stdout);
  }

  if (fopen("cownav.in", "r")) {
    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout);
  }


  solve();
}