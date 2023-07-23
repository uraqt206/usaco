#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, l, r) for(int i=l; i<=r; ++i)
#define FOD(i, l, r) for(int i=r; i>=l; --i)

template<typename T> bool umax(T &res, const T &val) { if (res < val) { res = val; return 1; } return 0; }
template<typename T> bool umin(T &res, const T &val) { if (res > val) { res = val; return 1; } return 0; }

const string read="taming";
const int mxN=105;

void setIO() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	if (read.size()) {
		freopen((read+".in").c_str(), "r", stdin);
		freopen((read+".out").c_str(), "w", stdout);
	}
}

int n, a[mxN], dp[mxN][mxN][mxN], ans;

int main() {
	setIO();
	cin >> n;
	FOR(i, 1, n) cin >> a[i];

	FOR(i, 0, n) FOR(j, 0, n) FOR(k, 0, n) dp[i][j][k] = 1e9;
	dp[1][1][1] = (a[1]!=0);
	
	FOR(i, 2, n) {
		FOR(j, 1, i-1) FOR(k, 1, i)	umin(dp[i][j][k], dp[i-1][j][k] + (a[i]!=i-j));
		FOR(j, 1, i-1) FOR(k, 1, i)	umin(dp[i][i][k], dp[i-1][j][k-1] + (a[i]!=0));
	}

	FOR(i, 1, n) {
		ans = 1e9;
		FOR(j, 1, n) umin(ans, dp[n][j][i]);
		cout << ans << '\n';
	}	
}