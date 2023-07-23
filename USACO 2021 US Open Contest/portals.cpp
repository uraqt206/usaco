#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
 
#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l); i>=(r); --i)
#define fore(x, v) for(auto &x : v)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define file "input"
 
void setIO() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }
}

const int N = 1e5+5;
int n, a[N][4], e[N * 2];
ll ans = 0;
vector<pair<int, ii>> edges;

int root(int u) { 
  return e[u] < 0 ? u : e[u] = root(e[u]);
}

bool join(int u, int v) {
  u = root(u); v = root(v);
  if (u == v) return 0;
  if (e[u] > e[v]) swap(u, v);
  e[u] += e[v];
  e[v] = u;
  return 1;
}

int main() {
  setIO();

  cin >> n;
  foru(i, 1, n*2) e[i] = -1;

  foru(i, 1, n) {
    int wei; cin >> wei;
    foru(j, 0, 3) cin >> a[i][j];
    join(a[i][0], a[i][1]);
    join(a[i][2], a[i][3]);
    edges.push_back({wei, {a[i][0], a[i][2]}});
  }

  sort(all(edges));
  fore(x, edges) if (join(x.se.fi, x.se.se)) ans += x.fi;
  cout << ans;
}