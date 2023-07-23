// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define vec vector
#define ins push_back

const int lim = 1e9;
const int mxn = 1002;
int n, m, a[mxn];
ll dp[mxn][mxn][2];

int main() {
	freopen("cowrun.in", "r", stdin);
	freopen("cowrun.out", "w", stdout);

	cin >> n;
	for(int i=1; i<=n; ++i)
		cin >> a[i];
	a[++n] = 0;
	sort(a+1, a+n+1);

	int st = 1;
	while (a[st] != 0) ++st;

	memset(dp, 0x3f, sizeof(dp));
	dp[st][st][0] = dp[st][st][1] = 0;

	for(int len=2; len<=n; ++len) {
		ll lef = n-len+1;
		for(int i=1; i<=n-len+1; ++i) {
			int l = i, r = i+len-1;

			dp[l][r][0] = min(dp[l][r][0], dp[l+1][r][0] + abs(a[l+1] - a[l]) * lef);
			dp[l][r][0] = min(dp[l][r][0], dp[l+1][r][1] + abs(a[r] - a[l]) * lef);

			dp[l][r][1] = min(dp[l][r][1], dp[l][r-1][1] + abs(a[r-1] - a[r]) * lef);
			dp[l][r][1] = min(dp[l][r][1], dp[l][r-1][0] + abs(a[l] - a[r]) * lef);
		}
	}

	cout << min(dp[1][n][0], dp[1][n][1]);
}