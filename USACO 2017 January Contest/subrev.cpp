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
#define file "subrev"
 
void setIO() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }
}

const int N = 51;

int n, a[N], dp[N][N][N][N];

void relax(int i, int j, int l, int r, int val) {
  dp[i][j][l][r] = max(dp[i][j][l][r], val);
}

int main() {
  setIO();

  cin >> n;

  foru(i, 1, n) {
    cin >> a[i];
  }

  ford(i, n, 1) {
    dp[i][i][a[i]][a[i]] = 1;

    ford(l, a[i], 1)
      foru(r, a[i], 50)
        dp[i][i][l][r] = 1;

    foru(j, i+1, n) {
      // if we dont use a[i] and a[j] at all
      foru(l, 1, 50) {  
        foru(r, l, 50) {
          dp[i][j][l][r] = max(dp[i+1][j][l][r], dp[i][j-1][l][r]);
        }
      }

      // if we use a[i]
      foru(r, a[i], 50) {
        relax(i, j, a[i], r, dp[i+1][j][a[i]][r] + 1);
      } 

      // if we use a[j]
      ford(l, a[j], 1) {
        relax(i, j, l, a[j], dp[i][j-1][l][a[j]] + 1);
      }

      // if we reverse a[i] and a[j]
      foru(l, 1, 50) {
        foru(r, l, 50) {
          int current = dp[i+1][j-1][l][r];
          if (a[j] <= l) relax(i, j, a[j], r, current + 1);
          if (r <= a[i]) relax(i, j, l, a[i], current + 1);
          if (a[j] <= l && r <= a[i]) relax(i, j, a[j], a[i], current + 2);
        }
      }

      ford(l, 50, 1) {
        foru(r, l, 50) {
          dp[i][j][l][r] = max({dp[i][j][l][r], dp[i][j][l+1][r], dp[i][j][l][r-1]});
        }
      }
    }
  }

  cout << dp[1][n][1][50];
}