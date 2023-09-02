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
 
void setIO(string name="") {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (!name.empty()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

const int N = 1e5+5;
const int MOD = 1e9+7;

int main() {
  setIO("moop");
  int n;
  cin >> n;
  vec<ii> pt;
  foru(i, 0, n-1) { int x, y; cin >> x >> y; pt.emplace_back(x, y); }
  sort(all(pt));
  vec<int> mx(100000); mx[n-1] = pt[n-1].second;
  ford(i, n-2, 0) mx[i] = max(pt[i].second, mx[i+1]);
  int mn = 2e9, ans = 1;
  foru(i, 0, n-2) {
    mn = min(mn, pt[i].second);
    if (mn > mx[i+1]) ++ans;
  }
  cout << ans;
}