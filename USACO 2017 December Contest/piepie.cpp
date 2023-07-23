#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l; i>=(r); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define fi first
#define se second
#define C make_pair
#define ar array

const int N = 1e5+5;

int n, d, e[2][N], mn[2][N];
ar<int, 3> a[2][N];
int ret[N], dist[2][N];
queue<ii> qu;

bool cmp0(ar<int, 3> a, ar<int, 3> b) {
  return a[0] < b[0];
}

bool cmp1(ar<int, 3> a, ar<int, 3> b) {
  return a[1] < b[1];
}

int root(int r, int u) {
  return e[r][u] < 0 ? u : e[r][u] = root(r, e[r][u]);
}

void join(int r, int u, int v) {
  u = root(r, u); v = root(r, v);
  // if (u == v) return;
  assert(u != v);
  if (e[r][u] > e[r][v]) swap(u, v);
  mn[r][u] = min(mn[r][u], mn[r][v]);
  e[r][v] = u;
}

void solve() {
  memset(dist, -1, sizeof(dist));
  cin >> n >> d;

  for(int r=0; r<2; ++r) {
    for(int i=1; i<=n; ++i) {
      cin >> a[r][i][0] >> a[r][i][1]; a[r][i][2] = i;
    }
  }
  
  sort(a[0]+1, a[0]+n+1, cmp1);
  sort(a[1]+1, a[1]+n+1, cmp0);

  for(int r=0; r<2; ++r) {
    for(int i=1; i<=n; ++i) {
      mn[r][i] = i;
      e[r][i] = -1;
      if (a[r][i][r^1] == 0) {
        qu.push(C(r, i));
        dist[r][i] = 1;
        if (i > 1 && dist[r][i-1] != -1) join(r, i, i-1);
      }
    }
  }

  while (!qu.empty()) {
    auto now = qu.front(); qu.pop();
    int r = now.fi, i = now.se;
    int tis = a[r][i][r];
    
    int lb = 0, rb = n, mb;
    while (lb < rb) {
      mb = (lb + rb + 1) >> 1;
      if (a[r^1][mb][r] <= tis) lb = mb;
      else rb = mb-1; 
    }

    if (lb == 0) continue;
    if (dist[r^1][lb] != -1) lb = mn[r^1][root(r^1, lb)]-1;
    while (lb > 0 && a[r^1][lb][r] >= tis-d) {
      dist[r^1][lb] = dist[r][i]+1;
      qu.push(C(r^1, lb));
      if (lb < n && dist[r^1][lb+1] != -1) join(r^1, lb, lb+1);
      if (lb > 1 && dist[r^1][lb-1] != -1) join(r^1, lb, lb-1);
      lb = mn[r^1][root(r^1, lb)]-1;
    }
  }

  for(int i=1; i<=n; ++i) ret[a[0][i][2]] = dist[0][i];
  for(int i=1; i<=n; ++i) cout << ret[i] << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("input.inp", "r")) {
    freopen("input.inp", "r", stdin);
    freopen("input.out", "w", stdout);
  }

  if (fopen("piepie.in", "r")) {
    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);
  }


  solve();
}