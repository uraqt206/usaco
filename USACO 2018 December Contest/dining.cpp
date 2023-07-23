#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>
#define fi first
#define se second

template<class T> bool umax(T &a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool umin(T &a, T b) { if (a>b) { a=b; return 1; } return 0; }

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

const int oo=2e9;
const int N=50002;
int n, m, k;
vector<vector<ii>> adj(N);
vector<int> f(N), g(N);
priority_queue<ii, vector<ii>, greater<ii>> pq;

void dijkstra(vector<vector<ii>> &adj, vector<int> &d, int s) {
	for(int i=1; i<=n; ++i)
		d[i]=oo;
	d[s]=0;
	pq.push(ii(0, s));
	while (pq.size()) {
		int u=pq.top().se, we=pq.top().fi;
		pq.pop();

		if (we!=d[u])
			continue;
		
		for(ii b: adj[u])
			if (umin(d[b.se], d[u]+b.fi))
				pq.push(ii(d[b.se], b.se));
	}
}

int main() {
	setIO("dining");
	cin >> n >> m >> k;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({w, v});
		adj[v].push_back({w, u});
	}
	
	dijkstra(adj, f, n);
	while (k--) {
		int pos, yummy;
		cin >> pos >> yummy;
		adj[n+1].push_back(ii(f[pos]-yummy, pos));
	}
	dijkstra(adj, g, n+1);

	for(int i=1; i<n; ++i)
		cout << (g[i]<=f[i]) << "\n";
}