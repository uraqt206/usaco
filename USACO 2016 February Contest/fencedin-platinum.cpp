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
#define file "fencedin"
 
void setIO() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }
}

const int N = 1e5+5;
int h, w, n, m, ver[N], hor[N];

int main() {
  setIO();
  cin >> h >> w >> n >> m;
  foru(i, 1, n) cin >> ver[i];
  foru(i, 1, m) cin >> hor[i];
  ver[n+1] = h; hor[m+1] = w;
  sort(ver, ver+n+1);
  sort(hor, hor+m+1);
  foru(i, 0, n) ver[i] = ver[i+1] - ver[i];
  foru(i, 0, m) hor[i] = hor[i+1] - hor[i];
  sort(ver, ver+n+1);
  sort(hor, hor+m+1);
  ll ans = 1LL * ver[0] * m + 1LL * hor[0] * n;
  for(int i=1, j=1; i<=n && j<=m; ) {
    if (ver[i] < hor[j]) { ans += 1LL * ver[i++] * (m+1 - j); }
    else { ans += 1LL * hor[j++] * (n+1 - i); }
  }
  cout << ans;
}