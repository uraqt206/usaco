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

const int N = 2e5+5;
int n, lst[N], bit[N];

void upd(int i, int v) { 
  for(i=n-i+1; i<=n; i+=i&-i) bit[i] += v;
}

int query(int i) {
  int ans = 0;
  for(i=n-i+1; i>=1; i-=i&-i) ans += bit[i];
  return ans;
}

int main() {
  setIO();

  cin >> n;

  ll ans = 0;
  foru(i, 1, n) {
    int num;
    cin >> num;
    ans += query(lst[num]+1);
    upd(lst[num], -1);
    lst[num] = i;
    upd(lst[num], 1);
  }

  cout << ans;
}