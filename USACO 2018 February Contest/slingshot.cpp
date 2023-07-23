#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l; i>=(r); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define lc id<<1
#define rc id<<1|1
#define fi first
#define se second

const ll LINF = 1e15;
const int INF = INT_MAX;
const int MX = 1e9;
const int N = 1e5+5;

struct qry {
  int s, t, id;
  qry(int _s=0, int _t=0, int _i=0) : s(_s), t(_t), id(_i) {}
};

struct segment_tree {
  ll sgt[N * 16];

  void reset() {
    memset(sgt, 0x3f, sizeof(sgt));
  }

  void upd(int id, int lb, int rb, int i, ll v) {
    if (lb ^ rb) {
      int mb = (lb + rb) >> 1;
      if (i <= mb) upd(lc, lb, mb, i, v);
      else upd(rc, mb+1, rb, i, v);
      sgt[id] = min(sgt[lc], sgt[rc]);
    } else sgt[id] = v;
  }

  ll query(int id, int lb, int rb, int u, int v) {
    if (u <= lb && rb <= v) return sgt[id];
    if (lb > v || rb < u) return LINF;
    int mb = (lb + rb) >> 1;
    return min(query(lc, lb, mb, u, v), query(rc, mb+1, rb, u, v));
  }
} lower, higher;

int n, m, q;
ll ans[N];
vector<int> comp;
vector<qry> slings[2];
vector<qry> go[2];

int pos(int i) {
  return upper_bound(all(comp), i) - comp.begin();
}

vector<ii> query[N * 4], shoot[N * 4];

void calc(vector<qry> slings, vector<qry> ques) {
  lower.reset();
  higher.reset();

  for(int i=1; i<=m; ++i) {
    if (!query[i].empty()) query[i].clear();
    if (!shoot[i].empty()) shoot[i].clear();
  }

  for(auto sling : slings) {
    int ps = pos(sling.s);
    int pt = pos(sling.t);
    shoot[ps].emplace_back(pt, sling.id);
  }

  for(auto x : ques) {
    int ps = pos(x.s);
    int pt = pos(x.t);
    query[ps].emplace_back(pt, x.id);
  }
  
  // first phase : account for case that x' >= x
  for(int i=m; i>=1; --i) {
    for(auto x : shoot[i]) {
      lower.upd(1, 1, m, x.fi, comp[i-1] + x.se - comp[x.fi-1]);
      higher.upd(1, 1, m, x.fi, comp[i-1] + x.se + comp[x.fi-1]);
    }

    for(auto x : query[i]) {
      ans[x.se] = min(ans[x.se], lower.query(1, 1, m, 1, x.fi) - comp[i-1] + comp[x.fi-1]);
      ans[x.se] = min(ans[x.se], higher.query(1, 1, m, x.fi+1, m) - comp[i-1] - comp[x.fi-1]);
    }
  }

  lower.reset();
  higher.reset();

  // second phase : account for case that x' <= x
  for(int i=1; i<=m; ++i) {
    for(auto x : shoot[i]) {
      lower.upd(1, 1, m, x.fi, -comp[i-1] + x.se - comp[x.fi-1]);
      higher.upd(1, 1, m, x.fi, -comp[i-1] + x.se + comp[x.fi-1]);
    }

    for(auto x : query[i]) {
      ans[x.se] = min(ans[x.se], lower.query(1, 1, m, 1, x.fi) + comp[i-1] + comp[x.fi-1]);
      ans[x.se] = min(ans[x.se], higher.query(1, 1, m, x.fi+1, m) + comp[i-1] - comp[x.fi-1]);
    }
  }
}

void solve() {
  cin >> n >> q;

  for(int i=1; i<=n; ++i) {
    int x, y, t;
    cin >> x >> y >> t;
    bool straight = (x < y);
    if (!straight) { x = MX - x; y = MX - y; }
    slings[straight].emplace_back(x, y, t);
    comp.push_back(x);
    comp.push_back(y);
  }

  for(int i=1; i<=q; ++i) {
    int x, y;
    cin >> x >> y;
    bool straight = (x < y);
    if (!straight) { x = MX - x; y = MX - y; }
    ans[i] = abs(x-y);
    go[straight].emplace_back(x, y, i);
    comp.push_back(x);
    comp.push_back(y);
  }

  sort(all(comp));
  comp.resize(unique(all(comp)) - comp.begin());
  m = comp.size();

  calc(slings[0], go[0]);
  calc(slings[1], go[1]);

  for(int i=1; i<=q; ++i) 
    cout << ans[i] << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("input.inp", "r")) {
    freopen("input.inp", "r", stdin);
    freopen("input.out", "w", stdout);
  }

  freopen("slingshot.in", "r", stdin);
  freopen("slingshot.out", "w", stdout);

  solve();
}