#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define fi first
#define se second
#define ins push_back
#define vec vector
#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l); i>=(r); --i)
#define fore(i, v) for(auto &i : v)
#define file "input"

const int N = 303;
const int mod = 1e9+7;

ll n, q, A, B;
char d[N];
int dp[N][18][18][3], ans[2][N][N];
string a, b;

void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

void convert(ll A, string &a) {
  while (A > 0) {
    a.ins(A%10 + 48);
    A /= 10;
  }
  reverse(a.begin(), a.end());
}

int type(char a, char b) {
  if (a > b) return 1;
  if (a < b) return 2;
  return 0;
}

int addLeft(int t1, int t2) {
  if (t2 == 1) return 1;
  if (t2 == 2) return 2;
  return t1;
}

int addRight(int t1, int t2) {
  if (t2 == 0) return t1;
  if (t1 != 0) return t1;
  return t2;
}

void calc(bool t, string &s) {
  int m = s.size();
  s = ">" + s;
  
  foru(i, 1, n) {
    memset(dp, 0, sizeof(dp));

    foru(j, i-1, n) {
      int cur = j-i+1;

      foru(l, 1, m) {
        add(ans[t][i][j], dp[cur][l][m][0]);
        add(ans[t][i][j], dp[cur][l][m][1]);
        if (l > 1) add(ans[t][i][j], dp[cur][l][m][2]);
      }

      foru(l, 1, m) {
        foru(r, l, m) {
          // skip
          foru(c, 0, 2) 
            add(dp[cur+1][l][r][c], dp[cur][l][r][c]);
          
          // add left
          if (l > 1) {
            foru(c, 0, 2)
              add(dp[cur+1][l-1][r][addLeft(c, type(s[l-1], d[j+1]))], dp[cur][l][r][c]);
          }

          // add right
          if (r < m) {
            foru(c, 0, 2)
              add(dp[cur+1][l][r+1][addRight(c, type(s[r+1], d[j+1]))], dp[cur][l][r][c]);
          } 
        }
      }

      foru(l, 1, m)
        add(dp[cur+1][l][l][type(s[l], d[j+1])], 2);
    }
  }
}

void prep() { 
  convert(A, a);
  convert(B, b);
  calc(0, a);
  calc(1, b);

  // for(int i=1; i<=n; ++i) {
  //   for(int j=i; j<=n; ++j) {
  //     cout << ans[1][i][j] << " ";   
  //   }
  //   cout << "\n";
  // }

  // cout << dp[1][1][1][2];
}

void solve() {
  cin >> n >> A >> B; --A;
  foru(i, 1, n) cin >> d[i];
  prep();

  cin >> q;
	foru(i, 1, q) {
		int l, r;
		cin >> l >> r;
		cout << (ans[1][l][r] - ans[0][l][r] + mod) % mod << "\n";
	}
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();
  return 0;
}
