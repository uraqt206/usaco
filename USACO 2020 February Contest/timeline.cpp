#include <bits/stdc++.h>

#define conqueror_of_uraqt int main()
#define xuong cout << "\n"
#define debug(x) cout << #x << ": " << x << "\n"
#define go(i,l,r) for(int i=(l); i<=(r); ++i)
#define rev(i,l,r) for(int i=(r); i>=(l); --i)
#define x first
#define y second
#define vec vector
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define uni(a) ((a).erase(unique(all(a)),(a).end()))
#define C make_pair
#define file "timeline"

template<class T> bool ckmax(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool ckmin(T &a, T b) {if (a>b) return a=b,1; return 0;}

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mxN = 1e5+5;
int n, k, m, f[mxN];
vec<pair<int, int>> e[mxN];
bool used[mxN];

void dfs(int u) {
	used[u] = 1;
	for(auto [v, w]: e[u]) {
		if (!used[v]) dfs(v);
		ckmax(f[u], f[v] + w);
	}
}

void solve() {
	cin >> n >> k >> m;
	for(int i=1; i<=n; ++i) cin >> f[i];
	for(int i=1; i<=m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		e[v].push_back(C(u, w));
	}
	for(int i=1; i<=n; ++i) {
		if (!used[i]) dfs(i);
		cout << f[i] << "\n";
	}
}

conqueror_of_uraqt {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if (fopen(file".in", "r")) {
		freopen(file".in", "r", stdin);
		freopen(file".out", "w", stdout);
	}
	solve();
	return 0;
}