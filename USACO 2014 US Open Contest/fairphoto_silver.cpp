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
#define file "fairphoto"

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

int bs(vt<pii> &a, int x) {
	int lb = 0, rb=a.size(), mb;
	while (lb < rb) {
		mb = (lb + rb) >> 1;
		if (a[mb].fi <= x)
			rb = mb;
		else
			lb = mb + 1;
	}
	return lb;
}

const int mxN = 100100;
int N, K;
vt<pii> C, V[2];

void solve() {
	cin >> N;

	for(int i=1; i<=N; ++i) {
		int x, y;
		char type;

		cin >> x >> type;
		y = (type == 'W' ? 1 : -1);
		C.push_back(mp(x, y));
	}

	sort(C.begin(), C.end());

	int ret = 0;
	for(int i=0, ps=0, par=0; i<N; ++i) {
		if (V[par].empty() || ps < V[par].back().fi)
			V[par].push_back(mp(ps, C[i].fi));
		
		ps += C[i].se;
		par ^= 1;

		int pos = bs(V[par], ps);
		if (pos == V[par].size()) continue;
		ckmax(ret, C[i].fi - V[par][pos].se);
	}

	cout << ret;
}

signed main() {
	read();
	solve();
	return 0;
}
