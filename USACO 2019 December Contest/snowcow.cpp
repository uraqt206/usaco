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
#define file "snowcow"

void setIO(string name="") {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }
}

const int N = 2e5+5;
int n, q, cnt, a[N], st[N], en[N];
ll ft[2][N];
vec<int> adj[N];
set<ii> color[N];

void modify(int t, int i, ll v) {
  for(; i<=n; i+=i&-i) ft[t][i] += v;
}

void inc(int l, int r, ll v) {
  modify(0, l, v);
  modify(0, r+1, -v);
  modify(1, l, v * -(l-1));
  modify(1, r+1, v * r);
}

ll query(int t, int i) {
  ll ans = 0;
  for(; i>=1; i-=i&-i) ans += ft[t][i];
  return ans;
}

ll get(int i) {
  return query(0, i) * i + query(1, i);
}

void dfs(int u, int p) {
  st[u] = ++cnt;
  fore(v, adj[u]) if (v != p) dfs(v, u);
  en[u] = cnt;
}

int main() {
	setIO();

  cin >> n >> q;

  foru(i, 2, n) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);
  foru(i, 1, q) {
    int cmd;
    cin >> cmd;
    
    if (cmd == 1) {
      int node, c;
      cin >> node >> c;
      auto it = color[c].upper_bound(make_pair(en[node], N));
      while (it != color[c].begin()) {
        auto prv = *prev(it);
        if (prv.fi < st[node]) break;
        inc(prv.fi, prv.se, -1);
        color[c].erase(prev(it));
      }
      auto it2 = (color[c].insert(make_pair(st[node], en[node]))).fi;
      if (it2 != begin(color[c]) && (*prev(it2)).se >= en[node]) {
        color[c].erase(it2);
        continue;
      }
      inc(st[node], en[node], 1);
    }
    else {
      int node;
      cin >> node;
      cout << get(en[node]) - get(st[node]-1) << "\n";
    }
  }
}