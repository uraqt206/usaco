#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l; i>=(r); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()

const int N = 1001;
const int INF = 1e9;
const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

int n, m, mat[N][N];
int dist[N][N][2][4];

struct state {
  int x, y, type, dir;
  state(int _x=0, int _y=0, int _s=0, int _d=0) : x(_x), y(_y), type(_s), dir(_d) {}

  int value() {
    return dist[x][y][type][dir];
  }

  bool add(int dis) {
    if (dist[x][y][type][dir] == -1) {
      dist[x][y][type][dir] = dis+1;
      return 1;
    }
    return 0;
  }
};
queue<state> qu;

bool e(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= m;
}

bool can_pass(state at, int dir) {
  int nx = at.x + dx[dir], ny = at.y + dy[dir];
  if (!e(nx, ny)) return 0;
  if (mat[nx][ny] == 0) return 0;
  if (mat[nx][ny] == 3) return at.type == 1;
  return 1;
}

state walk(state at, int dir) {
  int nx = at.x + dx[dir], ny = at.y + dy[dir];
  at.x = nx; at.y = ny; at.dir = dir; 
  if (mat[nx][ny] == 2) at.type = 1;
  if (mat[nx][ny] == 4) at.type = 0;
  return at;
}

void solve() {
  cin >> n >> m;

  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      cin >> mat[i][j];
    }
  }

  memset(dist, -1, sizeof(dist));
  dist[1][1][0][0] = 0;
  qu.push(state(1, 1, 0, 0));

  while (!qu.empty()) {
    auto at = qu.front(); qu.pop();

    if (at.x == n && at.y == m) {
      cout << at.value();
      return;
    }
    
    if (mat[at.x][at.y] == 4) {
      if (can_pass(at, at.dir)) {
        state to = walk(at, at.dir);
        if (to.add(at.value())) {
          qu.push(to);
        }
        continue;
      }
    }

    for(int dir=0; dir<4; ++dir) {
      if (!can_pass(at, dir)) {
        continue;
      }
      state to = walk(at, dir);
      if (to.add(at.value())) {
        qu.push(to);
      }
    }
  }

  cout << "-1";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  freopen("dream.in", "r", stdin);
  freopen("dream.out", "w", stdout);

  solve();
}