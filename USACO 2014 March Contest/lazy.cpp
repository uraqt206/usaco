#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define vt vector
#define mp make_pair
#define fi first
#define se second
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define file "lazy"

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

void read() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	if (fopen(file".in", "r")) {
		freopen(file".in", "r", stdin);
		freopen(file".out", "w", stdout);
	}
}

int N, K, A[404][404], P[404][404];

void solve() {
	cin >> N >> K;

	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=N; ++j) {
			cin >> A[i][j];
		}
	}

	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=N; ++j) {
			P[i][j] = P[i - 1][j] + A[i][j];
		}
	}

	ll ret = 0;
	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=N; ++j) {
			ll local = P[min(N, i + K)][j] - P[max(0, i - K - 1)][j];
			
			for(int k=j-1, rad=K-1; k>=max(1, j-K); --k, --rad)
				local += P[min(N, i + rad)][k] - P[max(0, i - rad - 1)][k];

			for(int k=j+1, rad=K-1; k<=min(N, j+K); ++k, --rad)
				local += P[min(N, i + rad)][k] - P[max(0, i - rad - 1)][k];

			ret = max(ret, local);
		}
	}

	cout << ret;
}

int main() {
	read();
	solve();
	return 0;
}
