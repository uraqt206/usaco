#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define vec vector
#define foru(i, l, r) for(int i=l; i<=r; ++i)
#define revu(i, r, l) for(int i=r; i>=l; --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()

const int lim = 2e9;
const int N = 2e5+5;

struct edge {
	int u[2], d[2];

	edge(int u1=0, int d1=0, int u2=0, int d2=0) {
		u[0] = u1; u[1] = u2;
		d[0] = d1; d[1] = d2;
	}

	bool operator < (const edge &a) {
		return d[0] < a.d[0];
	}
};

int n, m, a[N];
vector<int> st[N], en[N];
vector<edge> edges;
bool vis[N];

void solve() {
	cin >> n >> m;

	for(int i=0; i<m; ++i) {
		int u, r, v, s;
		cin >> u >> r >> v >> s;

		edges.emplace_back(u, r, v, s);
		st[u].push_back(i);
		en[v].push_back(i);
	}

	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		sort(all(st[i]), [&](int x, int y){
			return edges[x] < edges[y];
		});
	}

	queue<int> qu;
	for(int x : st[1]) {
		qu.push(x);
		vis[x] = 1;
	}

	while (!qu.empty()) {
		int i = qu.front();
		int u = edges[i].u[1], t = edges[i].d[1] + a[u];
		qu.pop();

		while (!st[u].empty()) {
			int x = st[u].back();
			if (t <= edges[x].d[0]) {
				st[u].pop_back();
				qu.push(x);
				vis[x] = 1;
			} else break;
		}
	}
	
	for(int i=1; i<=n; ++i) {
		int ans = (i==1 ? 0 : lim);
		for(int x : en[i]) if (vis[x])
			ans = min(ans, edges[x].d[1]);
		cout << (ans == lim ? -1 : ans) << "\n";
	}
}

int main() {
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		solve();
		return 0;
}
