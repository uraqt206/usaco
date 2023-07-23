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

const int INF = 2e9;
const ll LINF = 1e18;
const int N = 50050;

struct rect {
  int u=INF, v=INF, p=-INF, q=-INF;

  void add(int x, int y) {
    u = min(u, x);
    p = max(p, x);
    v = min(v, y);
    q = max(q, y);
  }

  ll value() {
    return 1LL * (p-u) * (q-v);
  }
};

ii block[N];
ll init = LINF;
ll ans = LINF;

void calc(vector<ii> &a) {
  int n = a.size();
  vector<int> comp;
  for(int i=1; i<=n; ++i) {
    comp.push_back(a[i-1].fi);
    block[i] = {INF, -INF};
  }
  sort(all(comp));
  comp.resize(unique(all(comp)) - comp.begin());
  for(int i=1; i<=n; ++i) {
    int p = upper_bound(all(comp), a[i-1].fi) - comp.begin();
    block[p].fi = min(block[p].fi, a[i-1].se);
    block[p].se = max(block[p].se, a[i-1].se);
  }
  vector<rect> lb(n+1);
  rect rb;
  for(int i=1; i<=comp.size(); ++i) {
    lb[i] = lb[i-1];
    lb[i].add(comp[i-1], block[i].fi);
    lb[i].add(comp[i-1], block[i].se);
  }
  init = lb[comp.size()].value();
  ans = min(ans, lb[comp.size()].value());
  for(int i=comp.size(); i>1; --i) {
    rb.add(comp[i-1], block[i].fi);
    rb.add(comp[i-1], block[i].se);
    ans = min(ans, lb[i-1].value()+rb.value());
  }
}

void solve(){
  int n;
  cin >> n;

  vector<ii> a(n);
  for(auto &i : a) cin >> i.fi >> i.se;

  for(int r=0; r<2; ++r) {
    calc(a);
    for(int i=0; i<n; ++i) swap(a[i].fi, a[i].se);
  }

  cout << init - ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("input.inp", "r")) {
    freopen("input.inp", "r", stdin);
    freopen("input.out", "w", stdout);
  }

  if (fopen("split.in", "r")) {
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
  }


  solve();
}