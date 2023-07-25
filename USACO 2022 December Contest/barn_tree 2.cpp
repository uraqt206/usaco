#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ins push_back
#define vec vector
#define all(x) (x).begin(), (x).end()

struct tmp {
  ll s, t, w;
  tmp(ll _s=0, ll _t=0, ll _w=0) : s(_s), t(_t), w(_w) {}
};

const int nx = 2e5+5;
ll n, a[nx], cnt[nx], sum[nx], need;
vec<int> tree[nx];
vec<tmp> ans;

void prep(int u, int p) {
  cnt[u] = 1;
  sum[u] = a[u];

  for(int v : tree[u]) if (v != p) {
    prep(v, u);
    cnt[u] += cnt[v];
    sum[u] += sum[v];
  }
}

void dfs(int u, int p) {
  for(int v : tree[u]) if (v != p) {
    if (sum[v] >= need * cnt[v]) {
      dfs(v, u);
      ll exc = sum[v] - need * cnt[v];
      if (exc > 0) ans.emplace_back(v, u, exc);
      a[u] += exc;
      a[v] -= exc;
    }
  }

  for(int v : tree[u]) if (v != p) {
    if (sum[v] < need * cnt[v]) {
      ll exc = need * cnt[v] - sum[v];
      ans.emplace_back(u, v, exc);
      a[u] -= exc;
      a[v] += exc;
      dfs(v, u);
    }
  }
}

void solve() {
  cin >> n;
  for(int i=1; i<=n; ++i)
    cin >> a[i];
  for(int i=2; i<=n; ++i) {
    int u, v;
    cin >> u >> v;
    tree[u].ins(v);
    tree[v].ins(u);
  }

  for(int i=1; i<=n; ++i) need += a[i];
  need /= n;

  prep(1, 1);
  dfs(1, 1);

  cout << ans.size() << "\n";
  for(auto x : ans) cout << x.s << " " << x.t << " " << x.w << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("input.inp", "r")) {
    freopen("input.inp", "r", stdin);
    freopen("input.out", "w", stdout);
  }

  solve();
  return 0;
}
