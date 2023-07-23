#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>

void setIO(string name="") {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (name.size()) freopen((name+".in").c_str(),"r",stdin);
	if (name.size()) freopen((name+".out").c_str(),"w",stdout);
}

struct qry {
	int b, c, idx;
};

const int mxN=1e5+1;
int n, m, c[mxN], ds[mxN], de[mxN], dep[mxN];
bool ans[mxN];
vector<int> adj[mxN], path(mxN);
vector<qry> query[mxN];
stack<int> st[mxN];

int cnt=0;
void dfs1(int u, int p) {
	ds[u]=++cnt;
	for(int v: adj[u]) if (v^p) {
		dep[v]=dep[u]+1;
		dfs1(v, u);
	}
	de[u]=cnt;
}

bool isAnc(int u, int v) {
	return ds[u]<=ds[v] && de[u]>=de[v];
}

void dfs2(int u, int p) {
	st[c[u]].push(u);
	path[dep[u]]=u;

	for(qry tmp: query[u]) {
		if (st[tmp.c].empty()) continue;
		int v=tmp.b, y=st[tmp.c].top(), idx=tmp.idx;
		if (y^u && isAnc(y, v) && isAnc(path[dep[y]+1], v)) continue;
		ans[idx]=1;
	}

	for(int v: adj[u]) if (v^p) 
		dfs2(v, u);

	st[c[u]].pop();
}

int main() {
	setIO("milkvisits");
	cin >> n >> m;
	for(int i=1; i<=n; ++i) 
		cin >> c[i];
	for(int i=1; i<n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i=1; i<=m; ++i) {
		int u, v, h; cin >> u >> v >> h;
		query[u].push_back({v, h, i});
		query[v].push_back({u, h, i});
	}

	dfs1(1, 1);
	dfs2(1, 1);

	for(int i=1; i<=m; ++i)
		cout << ans[i];
}