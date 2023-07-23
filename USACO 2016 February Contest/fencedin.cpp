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

const int N = 2005;
int h, w, n, m, ver[N], hor[N], e[N*N];
vector<pair<int, ii>> edges;
ll sum, mst;

int root(int u) {
  return e[u] < 0 ? u : e[u] = root(e[u]);
}

bool join(int u, int v) {
  if ((u = root(u)) == (v = root(v))) return 0;
  if (e[u] > e[v]) swap(u, v);
  e[u] += e[v];
  e[v] = u;
  return 1;
}

int id(int c, int r) {
  return c * (m + 1) + r + 1;
}

void solve() {
  cin >> h >> w >> n >> m;

  ver[0] = 0; ver[n+1] = h;
  for(int i=1; i<=n; ++i) {
    cin >> ver[i];
  }

  hor[0] = 0; hor[m+1] = w;
  for(int i=1; i<=m; ++i) {
    cin >> hor[i];
  }

  sort(ver, ver+n+2);
  sort(hor, hor+m+2);

  vector<ii> edgeVer, edgeHor;
  for(int i=1; i<=m+1; ++i) {
    edgeVer.emplace_back(hor[i]-hor[i-1], i-1);
  }
  for(int i=1; i<=n+1; ++i) {
    edgeHor.emplace_back(ver[i]-ver[i-1], i-1);
  }

  sort(all(edgeVer));
  sort(all(edgeHor));

  for(int i=1; i<=(n+1)*(m+1); ++i) e[i] = -1;
  ll ans = 0;
  for(int iv=0, ih=0; iv<edgeVer.size() || ih<edgeHor.size(); ) {
    if (ih == edgeHor.size() || (edgeVer[iv].fi < edgeHor[ih].fi)) {
      int j = edgeVer[iv].se;
      for(int i=0; i<n; ++i) {
        if (join(id(i, j), id(i+1, j))) ans += edgeVer[iv].fi;
      }
      ++iv;
    } else {
      int i = edgeHor[ih].se;
      for(int j=0; j<m; ++j) {
        if (join(id(i, j), id(i, j+1))) ans += edgeHor[ih].fi;
      }
      ++ih;
    }
  }

  cout << ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("fencedin.in", "r")) {
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
  }


  solve();
}