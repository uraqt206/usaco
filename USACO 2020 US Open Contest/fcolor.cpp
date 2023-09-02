#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
template<class T> using vec = vector<T>;
 
#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l); i>=(r); --i)
#define fore(x, v) for(auto &x : v)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define file "fcolor"
 
void setIO(string name="") {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }
}

const int N = 2e5+5;
int n, m, e[N], ret[N];
vec<int> adj[N], qu;

int root(int u) {
  return e[u] < 0 ? u : e[u] = root(e[u]);
}

void join(int u, int v) {
  if ((u = root(u)) == (v = root(v))) return;
  e[u] += e[v];
  e[v] = u;
  if (sz(adj[u]) < sz(adj[v])) swap(adj[u], adj[v]);
  adj[u].insert(adj[u].end(), adj[v].begin(), adj[v].end());
  adj[v].clear();
  if (sz(adj[u]) > 1) qu.push_back(u);
}

int main() {
  setIO();
  cin >> n >> m;

  foru(i, 1, m) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  foru(i, 1, n) {
    if (sz(adj[i]) > 1) qu.push_back(i);
    e[i] = -1;
  }

  while (!qu.empty()) {
    auto u = qu.back();
    if (adj[u].size() <= 1) { qu.pop_back(); continue; }
    int x = adj[u].back(); adj[u].pop_back();
    int y = adj[u].back(); 
    join(y, x);
  }

  int cnt = 0;
  foru(i, 1, n) {
    int p = root(i);
    if (!ret[p]) ret[p] = ++cnt;
    cout << ret[p] << "\n";
  }
}