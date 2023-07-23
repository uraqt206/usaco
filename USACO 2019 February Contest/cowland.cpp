#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l); i>=(r); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define C make_pair
#define fi first
#define se second

const ll LINF = 1e18;
const int INF = 2e9;
const int MOD = 1e9+7;
const int N = 1e5+5;
const int LOG = 18;

int n, q, e[N], st[N], en[N];
vector<int> graph[N];

// lca
int lg[N], anc[N][LOG], high[N], bit[N];

void upd(int i, int v) { for(; i<=n; i+=i&-i) bit[i] ^= v; }
int query(int i) { int ans = 0; for(; i>=1; i-=i&-i) ans ^= bit[i]; return ans; }

int cnt=0;
void dfs(int u, int p) {
  st[u] = ++cnt;
  anc[u][0] = p;
  high[u] = high[p] + 1;
  for(int j=1; j<=lg[high[u]]; ++j) anc[u][j] = anc[anc[u][j-1]][j-1];
  for(int v : graph[u]) if (v != p) dfs(v, u);
  en[u] = cnt;
  upd(st[u], e[u]);
  upd(en[u]+1, e[u]);
}

int lca(int u, int v) {
  if (high[u] < high[v]) swap(u, v);
  for(int k=high[u]-high[v], i=LOG-1; i>=0; --i) if (high[anc[u][i]] >= high[v]) u = anc[u][i];
  if (u == v) return u;
  for(int k=high[u], i=lg[k]; i>=0; --i) if (anc[u][i] != anc[v][i]) {
    u = anc[u][i];
    v = anc[v][i];
  }
  return anc[u][0];
}

void solve() {
  cin >> n >> q;

  for(int i=2; i<=n; ++i) lg[i] = lg[i>>1]+1;

  for(int i=1; i<=n; ++i) {
    cin >> e[i];
  }

  for(int i=1; i<n; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  high[0] = -1;
  dfs(1, 0);

  for(int i=1; i<=q; ++i) {
    int cmd; cin >> cmd;
    if (cmd == 1) {
      int k, v;
      cin >> k >> v;
      upd(st[k], v ^ e[k]);
      upd(en[k]+1, v ^ e[k]);
      e[k] = v;
    } else {
      int u, v;
      cin >> u >> v;
      int cla = lca(u, v);
      cout << (query(st[u]) ^ query(st[v]) ^ e[cla]) << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("input.inp", "r")) {
    freopen("input.inp", "r", stdin);
    freopen("input.out", "w", stdout);
  }

  if (fopen("cowland.in", "r")) {
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
  }


  solve();
}