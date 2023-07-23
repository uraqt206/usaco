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

const int ff[] = {0, 1, 0, 2, 2}, ss[] = {0, 1, 2, 0, 2};
ll dp[40][3][2][2];
vector<int> a, b, c;

void convert(ll num, vector<int> &a) {
  a.clear();
  foru(i, 0, 38) {
    a.push_back(num % 3);
    num /= 3;
  }
}

int main() {
  setIO();

  int m;
  cin >> m;

  foru(_, 1, m) {
    ll x, y, d;
    cin >> d >> x >> y;
    convert(x, a);
    convert(y, b);
    convert(d, c);

    memset(dp, 0, sizeof(dp));
    dp[0][1][0][0] = 1;

    foru(i, 0, 38) {
      int j = a[i], k = b[i], l = c[i];
      foru(cmp, 0, 2) foru(ex, 0, 1) foru(ey, 0, 1) if (dp[i][cmp][ex][ey] > 0) {
        foru(bit_d, 0, 2) {
          int bit_x = (ex + j + bit_d) % 3, n_ex = (ex + j + bit_d) >= 3;
          int bit_y = (ey + k + bit_d) % 3, n_ey = (ey + k + bit_d) >= 3;

          if (bit_x % 2 == bit_y % 2) {
            int ncmp = cmp;
            if (bit_d < l) ncmp = 0;
            else if (bit_d > l) ncmp = 2;
            dp[i+1][ncmp][n_ex][n_ey] += dp[i][cmp][ex][ey];
          }
        }
      }
    }

    cout << dp[39][1][0][0] + dp[39][0][0][0] << "\n";
  }
}