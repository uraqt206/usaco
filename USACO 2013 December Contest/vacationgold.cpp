#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using T = double;

#define ins push_back
#define vec vector
#define foru(i, l, r) for(int i=l; i<=r; ++i)
#define revu(i, l, r) for(int i=r; i>=l; --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define file "vacationgold"

const int lim = 2e9+9;
const int nx = 20020;

int n, m, k, q, hub[nx], idx[nx];
vec<pii> graph[2][nx];
vec<vec<int>> d[2];

void dijkstra(bool t, int s, vec<int> &d) {
  d[s] = 0;

  priority_queue<pii, vec<pii>, greater<pii>> pq;
  pq.push({0, s});

  while (!pq.empty()) {
    pii top = pq.top(); pq.pop();
    int u = top.second, w = top.first;

    if (w ^ d[u]) continue;
    for(pii e : graph[t][u]) {
      int v = e.first, cost = e.second;
      if (d[v] > d[u] + cost) {
        d[v] = d[u] + cost;
        pq.push({d[v], v});
      }
    }
  }
}

int flight(int s, int t) {
  if (idx[s] > 0) return d[0][idx[s]][t];

  int ans = lim;
  for(pii v : graph[0][s]) {
    int i = idx[v.first];
    if (d[1][i][s] < lim && d[0][i][t] < lim)
      ans = min(ans, d[1][i][s] + d[0][i][t]);
  }

  return ans;
}

void solve() {
  cin >> n >> m >> k >> q;
  d[0].ins(vec<int>(n+1, lim));
  d[1].ins(vec<int>(n+1, lim));

  foru(i, 1, m) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[0][u].ins({v, w});
    graph[1][v].ins({u, w});
  }

  foru(i, 1, k) {
    cin >> hub[i];
    idx[hub[i]] = i;

    foru(j, 0, 1) {
      d[j].ins(vec<int>(n+1, lim));
      dijkstra(j, hub[i], d[j].back());
    }
  }

//  foru(i, 1, n) cout << d[0][1][i] << " ";
//  cout << "\n";

  int cnt = 0;
  ll sum = 0;

  foru(_, 1, q) {
    int u, v;
    cin >> u >> v;

    int cost = flight(u, v);
    if (cost == lim) continue;
    ++cnt;
    sum += cost;
  }

  cout << cnt << "\n" << sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }

  int t = 1;
  // cin >> t;
  while (t--) solve();

  return 0;
}
