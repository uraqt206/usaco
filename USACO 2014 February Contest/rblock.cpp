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
#define file "rblock"

void read() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	if (fopen(file".in", "r")) {
		freopen(file".in", "r", stdin);
		freopen(file".out", "w", stdout);
	}
}
	
struct Edge {
	int u, v, w;
	
	void init() {
		cin >> u >> v >> w;
	}

	int get(int x) {
		return x ^ u ^ v;
	}
};

int N, M, ret;
vt<Edge> edges;
vt<int> D[3], graph[255];

int dijkstra(int s, vt<int> &D) {
	D = vt<int>(N + 1, 2e9);
	D[s] = 0;

	priority_queue<pii, vt<pii>, greater<pii>> pq;
	pq.push(C(0, s));

	while (!pq.empty()) {
		int u = pq.top().se;
		int du = pq.top().fi;
		pq.pop();

		if (du != D[u]) continue;
		for(int i: graph[u]) {
			int v = edges[i].get(u);

			int dv = du + edges[i].w;
			if (ckmin(D[v], dv)) {
				pq.push(C(D[v], v));
			}
		}
	}

	return D[N];
}

void solve() {
	cin >> N >> M;
	edges.resize(M);

	for(int i=0; i<M; ++i) {
		edges[i].init();
		graph[edges[i].u].push_back(i);
		graph[edges[i].v].push_back(i);
	}

	dijkstra(1, D[0]);
	dijkstra(N, D[1]);

	int ret = 0;
	for(Edge &x: edges) {
		int u = x.u, v = x.v, w = x.w;

		bool fst = !(D[0][u] + D[1][v] + w == D[0][N]);
		bool sec = !(D[1][u] + D[0][v] + w == D[0][N]);

		if (fst && sec) continue;

		x.w *= 2;
		ret = max(ret, dijkstra(1, D[2]));
		x.w /= 2;
	}

	cout << ret - D[0][N];
}

int main() {
	read();
	solve();
	return 0;
}