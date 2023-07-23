// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

#define vec vector
#define ins push_back
#define C make_pair
#define forn(i, n) for(int i=1; i<=n; ++i)
#define foru(i, l, r) for(int i=l; i<=r; ++i)
#define revu(i, r, l) for(int i=r; i>=l; --i)

const int mod = 1e9+7;
const int lim = 1e9;
const int nax = 1e5+5;

int k, n, ans = -1, a[nax], c[nax], p[nax], dp[1 << 16];

void solve() {
	cin >> n >> k;

	foru(i, 1, n) {
		cin >> a[i];
	}

	foru(i, 1, k) {
		cin >> c[i];
		p[i] = p[i-1] + c[i];
	}

	foru(mask, 1, (1<<n)) {
		int lef = 0;
		foru(j, 0, n-1) {
			if (mask>>j&1) {
				int prv = dp[mask - (1<<j)];
				int lb = prv, rb = k, mb;
				while (lb < rb) {
					mb = (lb + rb + 1) >> 1;
					if (p[mb] - p[prv] <= a[j+1])	
						lb = mb;
					else
						rb = mb-1;
				}
				dp[mask] = max(dp[mask], lb);
			} else lef += a[j+1];
		}
		if (dp[mask] == k) ans = max(ans, lef);
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	if (fopen("nochange.in", "r")) {
		freopen("nochange.in", "r", stdin);
		freopen("nochange.out", "w", stdout);
	}

	solve();
	// int t;
	// cin >> t;
	// while (t--) solve();
	return 0;
}