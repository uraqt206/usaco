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
#define file "mincross"
 
void setIO(string name="") {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }
}

const int N = 1e5+5;
int n, id[N], a[N], b[N], c[N], bit[N];
ll ans = 1e18, current;

void upd(int i, int v) { for(; i<=n; i+=i&-i) bit[i] += v; }
int query(int i) { int ans = 0; for(; i>=1; i-=i&-i) ans += bit[i]; return ans; }

int main() {
  setIO();
  cin >> n;
  foru(i, 1, n) cin >> a[i];
  foru(i, 1, n) cin >> b[i];

  foru(r, 0, 1) {
    foru(i, 1, n) {
      id[b[i]] = i;
    }

    current = 0;
    memset(bit, 0, sizeof(bit));

    foru(i, 1, n) {
      c[i] = id[a[i]];
      upd(c[i], 1);
      current += i - query(c[i]);
    }

    ans = min(ans, current);
    ford(i, n, 2) {
      current -= n - c[i];
      current += c[i] - 1;
      ans = min(ans, current);
    }

    foru(i, 1, n) {
      swap(a[i], b[i]);
    }
  }

  cout << ans;
}