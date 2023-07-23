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
#define file "disrupt"
 
void setIO() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }
}

const int N = 5e4+4, LOG = 16;
int n, m, t, st[N], en[N], anc[N][LOG], ans[N];
vector<int> graph[N];
set<ii> at[N], rem[N];
vector<ii> e;

void dfs(int u, int p) {
  st[u] = ++t;
  anc[u][0] = p;
  foru(j, 1, LOG-1) anc[u][j] = anc[anc[u][j-1]][j-1];
  fore(i, graph[u]) { int v = e[i].fi ^ e[i].se ^ u; if (v != p) dfs(v, u); }
  en[u] = t;
}

bool isanc(int u, int v) {
  return st[u] <= st[v] && st[v] <= en[u];
}

int lca(int u, int v) {
  if (isanc(u, v)) return u;
  ford(j, LOG-1, 0) if (!isanc(anc[u][j], v)) u = anc[u][j];
  return anc[u][0];
}

void dfs2(int u, int p) {
  fore(i, graph[u]) {
    int v = e[i].fi ^ e[i].se ^ u;
    if (v == p) continue;
    dfs2(v, u);
    ans[i] = (at[v].empty() ? -1 : (*at[v].begin()).fi);
    if (sz(at[u]) < sz(at[v])) swap(at[u], at[v]);
    fore(x, at[v]) at[u].insert(x);
  }
  fore(x, rem[u]) {
    at[u].erase(x);
  }
}

int main() {
  setIO();

  cin >> n >> m;

  foru(i, 2, n) {
    int u, v, w;
    cin >> u >> v;
    graph[u].emplace_back(sz(e));
    graph[v].emplace_back(sz(e));
    e.emplace_back(u, v);
  }
  dfs(1, 1);

  foru(i, 1, m) {
    int u, v, w;
    cin >> u >> v >> w;
    if (u == v) continue;
    int l = lca(u, v);
    at[u].insert({w, i});
    at[v].insert({w, i});
    rem[l].insert({w, i});
  }

  dfs2(1, 1);
  foru(i, 0, n-2) cout << ans[i] << "\n";
}