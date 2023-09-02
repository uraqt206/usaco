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

const int MOD = 1e9+7, MAX = 1e9;
int n, k;
vector<ii> comp;

int mul(int a, int b) { return 1LL * a * b % MOD; }
int add(int a, int b) { a += b; if (a >= MOD) a -= MOD; return a; }
int neg(int a, int b) { a -= b; if (a < 0) a += MOD; return a; }

int exp(int n, int k) {
  if (k == 0) return 1;
  int tmp = exp(n, k/2);
  tmp = mul(tmp, tmp);
  if (k & 1) tmp = mul(tmp, n);
  return tmp;
}

int calc(int vl, int len) {
  vector<int> dp(len+2);
  dp[0] = 1;
  int cnt =  MAX - vl, cur = dp[0];
  foru(i, 1, len+1) {
    dp[i] = cur;
    cur = add(mul(cur, cnt), cur);
    if (i >= k) cur = neg(cur, mul(dp[i-k], exp(cnt, k)));
  }
  return dp[len+1];
}

int main() {
  freopen("tracking2.in", "r", stdin);
  freopen("tracking2.out", "w", stdout);

  cin >> n >> k;

  int lst = -1, cnt = 0;
  foru(i, 1, n-k+1) {
    int num;
    cin >> num;
    if (num == lst) cnt += 1;
    else {
      if (cnt) comp.emplace_back(lst, cnt);
      lst = num; cnt = 1;
    }
  }
  comp.emplace_back(lst, cnt);

  int ret = 1, m = sz(comp);
  foru(i, 0, m-1) {
    int len = comp[i].se+k-1;
    if (i > 0) if (comp[i-1].fi > comp[i].fi) len -= k;
    if (i < m-1) if (comp[i+1].fi > comp[i].fi) len -= k;
    ret = mul(ret, calc(comp[i].fi, max(0, len)));
  }

  cout << ret;
}