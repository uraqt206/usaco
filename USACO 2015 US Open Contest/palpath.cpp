#include <bits/stdc++.h>

#define xuong cout << "\n"
#define debug(x) cout << #x << ": " << x << endl
#define rep(i,be,en) for(int i = (be); i<=(en); ++i)
#define fod(i,be,en) for(int i = (en); i>=(be); --i)
#define each(x, a)   for(auto &x: a)
#define ll long long
#define fi first
#define se second
#define vec vector
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()
#define uni(a) ((a).erase(unique(all(a)),(a).end()))
#define C make_pair
#define deb(x) cout << #x << ": " << x << "\n"
#define file "palpath"

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using db =  double;
const db EPS = 0.0000000001;

template<class T> bool ckmax(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool ckmin(T &a, T b) {if (a>b) return a=b,1; return 0;}

const int mod = 1e9+7;
int n;
char a[502][502];
int dp[2][502][502];

void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

void solve() {
	cin >> n;

	rep(i, 1, n) {
		rep(j, 1, n) {
			cin >> a[i][j];
		}
	}

	int cur = 1, prv = 0;
	dp[0][0][n+1] = 1;

	rep(k, 0, n-1) {
		rep(x, 1, n) {
			fod(u, x, n) {
				int &val = dp[cur][x][u];
				val = 0;
				int y = k - x + 2, v = n-u + n-k;
				if (y < 1 || y > n) continue;
				if (v < 1 || v > n) continue;
				if (x > u || y > v) continue;
				if (a[x][y] ^ a[u][v]) continue;

				add(val, dp[prv][x][u]);
				add(val, dp[prv][x-1][u]);
				add(val, dp[prv][x][u+1]);
				add(val, dp[prv][x-1][u+1]);
			}
		}
		dp[prv][0][n+1] = 0;
		cur ^= 1;
		prv ^= 1;
	}

	int ret = 0;
	for(int i=1; i<=n; ++i)
		add(ret, dp[prv][i][i]);

	cout << ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

  if (fopen(file".in", "r")) {
      freopen(file".in", "r", stdin);
      freopen(file".out", "w", stdout);
  }

  solve();
  return 0;
}
