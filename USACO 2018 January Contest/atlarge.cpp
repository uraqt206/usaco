/* DP ON TREE SOLUTION */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T> void maximize(T & a, const T & b) { if (a<b) a=b; }
template<class T> void minimize(T & a, const T & b) { if (a>b) a=b; }

void read(string name) {
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}

const int oo = 2e9;
const int N = 100100;

int n, root;
vector<int> adj[N];
vector<int> d(N), dp(N), mn(N, oo);
/*
	dp[i]: minimum number of farmer needed to prevent Bessie from reaching the leaf from node i
	d[i]:  minimum time for Bessie to reach node i
	mn[i]: minimum time for one of the farmer in subtree i to reach node i (we can call it "x")
	
	if (d[i] < mn[i]) then dp[i] = sum of dp[j] / j is child of i
    It means that if Bessie can reach node i earliest, then the farmer have to block all the child of i

	else dp[i] = 1
	If a farmer can reach node i sooner than Bessie, then only that farmer is sufficient to block Bessie
*/

void dfs(int u, int p) {
    if (adj[u].size() == 1)
        mn[u] = 0;

    for(int v: adj[u]) if (v!=p) {
        d[v] = d[u]+1;
        dfs(v, u);
        minimize(mn[u], mn[v]+1);
    }

    if (d[u] < mn[u]) {
        for(int v: adj[u]) if (v!=p)
            dp[u] += dp[v];
    }
    else
        dp[u] = 1;
}

int main() {
    read("atlarge");
    cin >> n >> root;

    for(int i=1; i<n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (adj[root].size() == 1) {
        cout << 0;
        return 0;
    }

    dfs(root, root);
    cout << dp[root];
}