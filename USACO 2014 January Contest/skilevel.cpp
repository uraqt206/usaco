/* Trust The Process */
 
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
#define xuong cout << "\n------\n";
#define rep(i,be,en) for(int i = (be); i<=(en); ++i)
#define fod(i,be,en) for(int i = (en); i>=(be); --i)
#define fi first
#define se second
#define vec vector
#define C make_pair
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define uni(a) ((a).erase(unique(all(a)),(a).end()))
#define file "skilevel"
 
template<class T> bool ckmax(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool ckmin(T &a, T b) {if (a>b) return a=b,1; return 0;}

const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
int n, m, t;
vec<int> a, e, cnt;
vec<pair<int, pii>> edges;
ll ans = 0;

int root(int u) {
	return e[u] < 0 ? u : e[u] = root(e[u]);
}

void join(int u, int v, int w) {
	if ((u=root(u)) == (v=root(v)))
		return;
	if (e[u] > e[v]) swap(u, v);
	int tot = - (e[u] + e[v]);

	if (tot >= t) {
		if (e[u] > -t) ans += (1LL * cnt[u] * w);
		if (e[v] > -t) ans += (1LL * cnt[v] * w);
	}

	cnt[u] += cnt[v];
	e[u] += e[v];
	e[v] = u;
}

int pos(int i, int j) { return i*m + j; }

void os() {
	cin >> n >> m >> t;

	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			int x; cin >> x;
			e.push_back(-1);
			a.push_back(x);
		}
	}

	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			int x; cin >> x;
			cnt.push_back(x);
		}
	}

	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			for(int k=0; k<4; ++k) {
				int ni = i+dx[k], nj = j+dy[k];
				if (ni<0 || nj<0 || ni>=n || nj>=m) continue;
				int id1 = pos(i, j), id2 = pos(ni, nj);
				edges.push_back(C(abs(a[id1] - a[id2]), C(id1, id2)));
			}
		}
	}
	
	sort(all(edges));
	for(auto &x: edges) {
		int w = x.fi, u = x.se.fi, v = x.se.se;
		join(u, v, w);
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	if (fopen(file".in", "r")) {
		freopen(file".in", "r", stdin);
		freopen(file".out", "w", stdout);
	}

	int t = 1;
	//cin >> t;
	while (t--) os();
}

