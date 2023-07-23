/* 
		Problem: Farmer John Solves 3SUM
		Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=994
*/

#include <bits/stdc++.h>

#define xuong cout << "\n"
#define debug(x) cout << #x << ": " << x << endl
#define rep(i,be,en) for(int i = (be); i<=(en); ++i)
#define fod(i,be,en) for(int i = (be); i>=(en); --i)
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
#define file "threesum"

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using db =  double;
const db EPS = 0.0000000001;

template<class T> bool ckmax(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool ckmin(T &a, T b) {if (a>b) return a=b,1; return 0;}

const int mxV = 2e6;
int n, q, a[5001], cnt[mxV*2+1];
ll dp[5001][5001];

void os() {
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	for(int i=n; i>=1; --i) {
		for(int j=i+2; j<=n; ++j) {
			++cnt[a[j-1] + mxV];
			dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
			dp[i][j] += cnt[mxV - a[i] - a[j]];
		}
		for(int j=i+1; j<n; ++j) {
			--cnt[a[j] + mxV];
		}
	}
	for(int i=1; i<=q; ++i) {
		int l, r;
		cin >> l >> r;
		cout << dp[l][r] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	if (fopen(file".in", "r")) {
		freopen(file".in", "r", stdin);
		freopen(file".out", "w", stdout);
	}

	os();
	return 0;
}
