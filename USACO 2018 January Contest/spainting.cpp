/* Trust The Process */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
#define rep(i,be,en) for(int i = (be); i<=(en); ++i)
#define fod(i,be,en) for(int i = (en); i>=(be); --i)
#define deb(x) cout << #x << ": " << x << "\n"
#define fi first
#define se second
#define vt vector
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define uni(a) ((a).erase(unique(all(a)),(a).end()))
#define file "spainting"
#define lc id<<1
#define rc id<<1|1
 
template<class T> bool ckmax(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool ckmin(T &a, T b) {if (a>b) return a=b,1; return 0;}

const int mod = 1e9+7;

namespace sub1 {
	vt<int> dp;

	void work(int n, int m, int k) {
		ll total = 1;
		rep(i, 1, n) total = (total * m) % mod;

		dp = vt<int>(n+1);
		dp[0] = 1;

		rep(i, 1, n) 
			fod(j, max(1, i-k+2), i)
				dp[i] = (dp[i] + (1LL * (m-(j!=1)) * dp[j-1]) % mod) % mod;

		cout << (total - dp[n] + mod) % mod << "\n";
	}
}

namespace sub2 {
	vt<int> dp;
	
	void work(int n, int m, int k) {
		dp = vt<int>(n+1);
		
		rep(i, 1, n) {
			int lb = max(0, i-k+1), v;
			
			if (lb == 0) v = dp[i-1];
			else v = (dp[i-1] - dp[lb-1] + mod) % mod;

			dp[i] = 1LL * v * (m-1) % mod;
			if (lb == 0) dp[i] = (dp[i] + m) % mod;
			
			dp[i] = (dp[i-1] + dp[i]) % mod;
		}

		ll total = 1;
		rep(i, 1, n) total = (total * m) % mod;
		dp[n] = (dp[n] - dp[n-1] + mod) % mod;
	
		cout << (total - dp[n] + mod) % mod << endl;
	}
}

int n, m, k;

void solve() {
	cin >> n >> m >> k;

	if (n <= 1000 && k <= 1000)
		sub1::work(n, m, k);
	else
		sub2::work(n, m, k);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    if (fopen(file".in", "r")) {
    	freopen(file".in", "r", stdin);
		freopen(file".out", "w", stdout);
    }
	
	solve();
	return 0;
}