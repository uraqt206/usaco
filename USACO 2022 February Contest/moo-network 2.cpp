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

using state = pair<ll, ii>;
const int N = 1e5+5, V = 1e6;

int n, m;
bool inMst[V+1][11];
vector<int> a[11];
priority_queue<state, vector<state>, greater<state>> pq;

ll dist(int x, int y, int u, int v) {
  return 1LL * (u-x) * (u-x) + 1LL * (v-y) * (v-y);
}

void relax(int x, int y, int u, int v) {
  if (inMst[u][v]) return;
  ll range = dist(x, y, u, v);
  pq.push({range, {u, v}});
}

int main() {
  setIO();
  
  cin >> n;

  foru(i, 1, n) {
    int x, y;
    cin >> x >> y;
    a[y].push_back(x);
  }

  foru(i, 0, 10) if (!a[i].empty()) {
    sort(all(a[i]));
    if (pq.empty()) {
      pq.push({0, {a[i][0], i}});
    }
  }

  ll ans = 0;
  while (!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    int x = cur.se.fi, y = cur.se.se;
    if (inMst[x][y]) continue;
    inMst[x][y] = 1;
    ans += cur.fi;
    foru(ny, 0, 10) if (!a[ny].empty()) {
      int id = (upper_bound(all(a[ny]), x) - a[ny].begin());
      if (id < sz(a[ny])) relax(x, y, a[ny][id], ny);
      --id; 
      if (id >= 0) relax(x, y, a[ny][id], ny);
      --id;
      if (id >= 0) relax(x, y, a[ny][id], ny);
    }
  }
  cout << ans;
}