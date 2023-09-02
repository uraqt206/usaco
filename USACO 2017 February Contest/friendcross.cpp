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
#define file "friendcross"
 
void setIO(string name="") {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }
}

const int N = 1e5+5;
int n, k, id[N], b[N], bit[N];
ll ans = 0;

void upd(int i, int v) {
  for(; i<=n; i+=i&-i) bit[i] += v;
}

int query(int l, int r) {
  l = max(l, 1);
  r = min(n, r);
  int ans = 0;
  for(; r>=1; r-=r&-r) ans += bit[r];
  for(--l; l>=1; l-=l&-l) ans -= bit[l];
  return ans;
}

void divide(int l, int r) {
  if (l == r) return;
  int m = (l+r)/2;
  divide(l, m);
  divide(m+1, r);
  
  vector<ii> tmpA, tmpB;
  foru(i, l, m) tmpA.emplace_back(id[b[i]], b[i]);
  foru(i, m+1, r) tmpB.emplace_back(id[b[i]], b[i]);
  sort(all(tmpA));
  sort(all(tmpB));

  int i = sz(tmpA);
  ford(j, sz(tmpB)-1, 0) {
    while (i > 0 && tmpA[i-1].first >= tmpB[j].first) {
      --i;
      upd(tmpA[i].second, 1);
    }
    ans += sz(tmpA) - i - query(tmpB[j].second - k, tmpB[j].second + k);
  }

  while (i < sz(tmpA)) {
    upd(tmpA[i].second, -1);
    ++i;
  }
}

int main() {  
  setIO();
  cin >> n >> k;

  foru(i, 1, n) {
    int num;
    cin >> num;
    id[num] = i;
  }

  foru(i, 1, n) {
    cin >> b[i];
  }

  divide(1, n);
  cout << ans << "\n";
}