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
#define file "nocross"
 
void setIO(string name="") {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }
}

const int N = 1e5+5;
int n, k, a[N], b[N], id[N], ans;
map<int, int> mp;

void add(int x, int y) {
  auto it = mp.lower_bound(x);
  if (it != mp.end() && it -> second >= y) return;
  it = mp.insert(it, {x, y});
  it -> second = y;
  while (it != mp.begin() && prev(it) -> second <= y) mp.erase(prev(it));
}

int query(int i) {
  auto it = mp.upper_bound(i);
  return (it == mp.end() ? 0 : it -> second);
}

int main() {
  setIO();
  cin >> n;
  foru(i, 1, n) cin >> a[i], id[a[i]] = i;
  foru(i, 1, n) cin >> b[i];

  vec<ii> edges;
  foru(i, 1, n) {
    foru(j, max(b[i]-4, 1), min(b[i]+4, n)) {
      edges.emplace_back(id[j], i);
    }
  }

  int j = sz(edges);
  sort(all(edges));
  ford(i, n, 1) {
    vec<ii> upd;
    while (j > 0 && edges[j-1].first >= i) {
      --j;
      int value = query(edges[j].second) + 1;
      upd.emplace_back(edges[j].second, value);
      ans = max(ans, value);
    }
    fore(x, upd) {
      add(x.first, x.second);
    }
  }

  cout << ans;
}