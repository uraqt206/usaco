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

const int N = 5005, MOD = 1e9+7;
int n, m, dp[N][N][2];
string a, b;

string reformat(string a) {
  string ret;
  for(char &c : a) {
    if (c == '1') continue;
    if (c == '0') ret.clear();
    if (c != '+') c = '2';
    ret += c;
  }
  return ret;
}

void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int main() {
  setIO();

  int t;
  cin >> t;

  foru(_, 1, t) {
    cin >> n >> a >> b;
    a = reformat(a);
    b = reformat(b);
    n = sz(a), m = sz(b);
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    foru(i, 0, n) {
      foru(j, 0, m) {
        foru(k, 0, 1) if (dp[i][j][k] > 0) {
          int current = dp[i][j][k];
          if (j < m) add(dp[i][j+1][1], current);
          if (k == 0 && i < n) add(dp[i+1][j][0], current);
          else if (k == 1 && b[j-1] != a[i]) add(dp[i+1][j][0], current);
        }
      }
    }
    cout << (dp[n][m][0] + dp[n][m][1]) % MOD << "\n";
  }
}