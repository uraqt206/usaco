#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define vec vector
#define ins push_back
#define all(x) (x).begin(), (x).end()
#define int long long

const int nx = 1505;
int n, q;
char a[nx][nx];
int cost[nx][nx], sub[nx][nx];
ll ans = 0;

void rem(int u, int v) {
  int siz = sub[u][v]+1;

  while (true) {
    if (a[u][v] == 'R') ++v;
    else ++u;

    sub[u][v] -= siz;
    if (v > n || u > n) {
      ans -= siz * cost[u][v];
      break;
    }
  }
}

void add(int u, int v) {
  int siz = sub[u][v]+1;

  while (true) {
    if (a[u][v] == 'R') ++v;
    else ++u;

    sub[u][v] += siz;
    if (v > n || u > n) {
      ans += siz * cost[u][v];
      break;
    }
  }
}

void solve() {
  cin >> n;

  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      cin >> a[i][j];
      if (a[i][j] == 'R') sub[i][j+1] += sub[i][j] + 1;
      else sub[i+1][j] += sub[i][j] + 1;
    }
    cin >> cost[i][n+1];
    ans += cost[i][n+1] * sub[i][n+1];
  }

//  for(int i=1; i<=n+1; ++i) {
//    for(int j=1; j<=n+1; ++j) cout << sub[i][j] << " ";
//    cout << "\n";
//  }

  for(int i=1; i<=n; ++i) {
    cin >> cost[n+1][i];
    ans += cost[n+1][i] * sub[n+1][i];
  }

  cout << ans << "\n";

  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;

    rem(u, v);
//    if (q == 0) cout << ans << "\n";
    a[u][v] = (a[u][v] == 'R' ? 'D' : 'R');
    add(u, v);

    cout << ans << "\n";
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("input.inp", "r")) {
    freopen("input.inp", "r", stdin);
    freopen("input.out", "w", stdout);
  }

  solve();
  return 0;
}