#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> bool ckmin(T &a, const T b) { 
	if (a>b) return a=b, 1; return 0;
}

template<class T> bool ckmax(T &a, const T b) {
	if (a<b) return a=b, 1; return 0;
}

#define deb(x) cout << #x << ": " << x << "\n"
#define bitmask(i, j) cout << bitset<j>(i) << "\n"
#define xuong cout << "--------------------\n";
#define vt vector
#define fi first
#define se second
#define rep(i, l, r) for(int i=(l); i<=(r); ++i)
#define fod(i, l, r) for(int i=(r); i>=(l); --i)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define C make_pair
#define file "input"

const int mxN = 505;
int N, B, ret = 251, f[mxN], s[mxN], d[mxN];
bool visit[mxN][mxN];

void go(int i, int j) {
	if (i >= N) {
		ckmin(ret, j);
		return;
	}

	if (visit[i][j])
		return;
	visit[i][j] = 1;

	rep(ni, i+1, i+d[j])
		if (f[ni] <= s[j])
			go(ni, j);

	rep(nj, j+1, B-1)
		if (s[nj] >= f[i])
			go(i, nj);
}

void solve() {
	cin >> N >> B;

	rep(i, 0, N-1)
		cin >> f[i];

	rep(i, 0, B-1)
		cin >> s[i] >> d[i];
	
	go(0, 0);
	cout << ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);

	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}
