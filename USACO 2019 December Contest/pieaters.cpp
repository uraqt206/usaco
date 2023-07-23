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
#define file "pieaters"
 
void setIO() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }
}

const int N = 303, M = N*(N-1)/2;
int n, m, wei[N][N], best[N][N][N], dp[N][N];

int main() {
  setIO();

  cin >> n >> m;

  foru(i, 1, m) {
    int w, l, r;
    cin >> w >> l >> r;
    wei[l][r] = w;
  }

  foru(i, 1, n) {
    ford(l, i, 1) {
      foru(r, i, n) {
        best[i][l][r] = max({wei[l][r], best[i][l+1][r], best[i][l][r-1]});
      }
    }
  }

  ford(i, n, 1) {
    dp[i][i] = wei[i][i];

    foru(j, i+1, n) {
      foru(k, i, j) {
        dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + best[k][i][j]);
      }
    }
  }

  cout << dp[1][n];
}