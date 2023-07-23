#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using il = pair<ll, ll>;

#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l); i>=(r); --i)
#define fore(x, v) for(auto &x : v)
#define fi first
#define se second
#define int long long

void setIO(string name) {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (!name.empty()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

const ll LINF = 1e18;
const int INF = 2e9;
const int N = 2e5+5;
int n, q, a[N];
il node[N*4];
ll lazy[N*4];

il comb(il a, il b) {
  return {min(a.fi, b.fi), a.se + b.se};
}

void app(int id, int lb, int mb, int rb) {
  int len[2] = {mb-lb+1, rb-mb};
  for(int k=0; k<2; ++k) {
    int c = id*2+k;
    lazy[c] += lazy[id];
    node[c].fi += lazy[id];
    node[c].se += lazy[id]*len[k];
  }
  lazy[id] = 0;
}

void build(int id, int lb, int rb) {
  if (lb ^ rb) {
    int mb = (lb + rb) >> 1;
    build(id*2, lb, mb);
    build(id*2+1, mb+1, rb);
    node[id] = comb(node[id*2], node[id*2+1]);
  } else node[id] = {a[lb], a[lb]};
}

void inc(int id, int lb, int rb, int l, int r, ll v) {
  if (l <= lb && rb <= r) {
    lazy[id] += v;
    node[id].fi += v; 
    node[id].se += v*(rb-lb+1);
    return;
  }
  else if (lb > r || rb < l) {
    return;
  }

  int mb = (lb + rb) >> 1;
  app(id, lb, mb, rb);
  inc(id*2, lb, mb, l, r, v);
  inc(id*2+1, mb+1, rb, l, r, v);
  node[id] = comb(node[id*2], node[id*2+1]);
}

il query(int id, int lb, int rb, int l, int r) {
  if (l <= lb && rb <= r) return node[id];
  if (lb > r || rb < l) return {LINF, 0};
  int mb = (lb + rb) >> 1;
  app(id, lb, mb, rb);
  node[id] = comb(node[id*2], node[id*2+1]);
  return comb(query(id*2, lb, mb, l, r), query(id*2+1, mb+1, rb, l, r));
}

signed main() {
  setIO("haybales");

  cin >> n >> q;

  foru(i, 1, n) cin >> a[i];
  build(1, 1, n);

  foru(t, 1, q) {
    char c; cin >> c;
    int l, r, v;

    if (c == 'P') {
      cin >> l >> r >> v;
      inc(1, 1, n, l, r, v);
    } 
    else {
      cin >> l >> r;
      auto ans = query(1, 1, n, l, r);
      if (c == 'M') cout << ans.fi << "\n";
      else cout << ans.se << "\n";
    }
  }
}