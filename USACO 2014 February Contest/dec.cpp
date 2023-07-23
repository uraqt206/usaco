#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> bool ckmax(T &A, const T B) {
	if (A < B) {
		A = B;
		return 1;
	}
	return 0;
}

template<class T> bool ckmin(T &A, const T B) {
	if (A > B) {
		A = B;
		return 1;
	}
	return 0;
}

#define vt vector
#define C make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define file "dec"

void read() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	if (fopen(file".in", "r")) {
		freopen(file".in", "r", stdin);
		freopen(file".out", "w", stdout);
	}
}

vt<pii> bonus[21];
int N, B, mat[21][21], dp[1 << 20];

void solve() {
	cin >> N >> B;

	for(int i=1; i<=B; ++i) {
		int k, p, x;
		cin >> k >> p >> x;
		bonus[k].push_back(C(p, x));
	}

	for(int i=1; i<=N; ++i)
		for(int j=1; j<=N; ++j)
			cin >> mat[i][j];

	for(int i=0; i<(1 << N); ++i) {		
		int cnt = __builtin_popcount(i);

		for(int j=0; j<N; ++j) if (i & (1 << j)) {
			int prv = i - (1 << j);	
			dp[i] = max(dp[i], dp[prv] + mat[j + 1][cnt]);
		}

		for(pii award: bonus[cnt]) {
			if (dp[i] >= award.fi)
				dp[i] += award.se;
		}
	}

	cout << dp[(1 << N) - 1];
}

int main() {
	read();
	solve();
	return 0;
}