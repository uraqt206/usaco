#include<bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for(int i=l; i<=r; ++i)
#define fod(i, l, r) for(int i=r; i>=l; --i)
#define ll long long 
#define ii pair<int, int>
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

template<class T> bool umax(T &a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool umin(T &a, T b) { if (a>b) { a=b; return 1; } return 0; }

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

struct Edge {
	int u, v, w, f;
	void in() {
		cin >> u >> v >> w >> f;
	}
};

const ll oo=1e18;
const int N=1010;
int n, m, d[N];
vector<Edge> edges(N);
vector<int> adj[N];
ll ans=-oo;
priority_queue<ii, vector<ii>, greater<ii>> pq;

ll Try(ll x) {
	memset(d, 0x3f, sizeof(d));
	d[1]=0;
	pq.push(ii(d[1], 1));
	while (pq.size()) {
		int we=pq.top().fi, u=pq.top().se;
		pq.pop();
		if (we!=d[u])
			continue;

		for(int i: adj[u]) if (edges[i].f>=x) {
			int v=edges[i].u^edges[i].v^u;
			if (umin(d[v], we+edges[i].w))
				pq.push(ii(d[v], v));
		}
	}
	return x*1000000LL/d[n];
}

int main() {
	read("pump");
	cin >> n >> m;
	for(int i=1; i<=m; ++i) {
		edges[i].in();
		adj[edges[i].u].push_back(i);
		adj[edges[i].v].push_back(i);
	}

	for(int i=1; i<=m; ++i)
		umax(ans, Try(edges[i].f));

	cout << ans;
}