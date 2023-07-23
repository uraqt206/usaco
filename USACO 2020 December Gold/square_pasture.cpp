#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l; i>=(r); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define C make_pair
#define x first
#define y second

const int INF = 1e9+1;
const int MAX_N = 202;

int n;
ll ans, eq;
ii a[MAX_N];

void calc() {
  sort(a+1, a+n+1);
  
  foru(i, 1, n) {
    vector<ll> v;
    int m = 0;

    foru(j, i, n) {
      v.push_back(a[j].y);
      ++m;

      ll len = a[j].x - a[i].x;
      ll mn = max(a[i].y, a[j].y) - len;
      ll mx = min(a[i].y, a[j].y);
      if (mn > mx) continue;

      sort(v.begin(), v.end());

      int i1=0, i2=-1;
      for(int cur=mn; cur<=mx; ++cur) {
        while (i1 < m && v[i1] < cur) ++i1;
        while (i2 < m-1 && v[i2+1] <= cur+len) ++i2;
        if (v[i2] - v[i1] == len) ++eq;
        else ++ans;
        
        if (i2 == m-1) cur += v[i1] - cur;
        else cur += min(v[i1] - cur, v[i2+1] - cur-len - 1);
      }
    }
  }
}

void solve() {
  cin >> n;

  for(int i=1; i<=n; ++i) {
    cin >> a[i].x >> a[i].y;
  }

  calc();
  for(int i=1; i<=n; ++i) swap(a[i].x, a[i].y);
  calc();

  cout << ans + eq/2 + 1;
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
