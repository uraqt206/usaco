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
#define file "nocow"

const int nx = 101;
int n, m, k, cnt[nx];
vec<string> a[nx], b[nx];

void solve() {
  cin >> n >> k;

  foru(i, 1, n) {
    for(int c=1; c<=1000000; ++c) {
      string s;
      cin >> s;
      if (s.back() == '.') break;
      if (c > 4) a[i].ins(s);
    }
  }
  m = a[1].size();

  cnt[m] = 1;
  revu(j, 0, m-1) {
    foru(i, 1, n) b[j].ins(a[i][j]);
    sort(all(b[j]));
    b[j].resize(unique(all(b[j])) - b[j].begin());
    cnt[j] = cnt[j+1] * (int)b[j].size();
  }

//  foru(j, 0, m-1) cout << cnt[j] << " ";
//  cout << "\n";

  vec<string> cur(n+1, "");
  string ans, comp;

  foru(j, 0, m-1) {
    foru(i, 1, n)
      cur[i] += a[i][j];

    for(string s : b[j]) {
      string nxt = comp + s;
      int cand = cnt[j+1];
      foru(i, 1, n) if (cur[i] == nxt) --cand;

      if (cand < k) k -= cand;
      else {
        comp += s;
        if (!ans.empty()) ans.ins(' ');
        ans += s;
        break;
      }
    }
  }

  cout << ans;
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
