// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define vec vector
#define ins push_back

const int mxn = 10001, mxm = 1001;
const int lim = 1e9;
int n, m, nxt[mxm][26], dp[mxn][mxm];
string s, t;

int calc(const string &p) {
	string join = t + "#" + p;
	int n = join.size();

	vec<int> kmp(n);
	for(int i=1, j=0; i<n; ++i) {
		while (j > 0 && join[i] != join[j])
			j = kmp[j-1];
		if (join[i] == join[j]) 
			++j;
		kmp[i] = j;
	}

	return kmp[n-1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("necklace.in", "r", stdin);
	freopen("necklace.out", "w", stdout);
	
	cin >> s >> t;
	n = s.size();
	m = t.size();

	string tmp;
	for(int i=-1; i<m; ++i) {
		if (i >= 0) tmp.ins(t[i]);
		for(int j=0; j<26; ++j) {
			tmp.ins(j + 'a');
			nxt[i+1][j] = calc(tmp);
			tmp.pop_back();
		}
	}

	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;

	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) if (dp[i][j] < lim) {
			if (nxt[j][s[i]] < m) dp[i+1][nxt[j][s[i]-'a']] = min(dp[i+1][nxt[j][s[i]-'a']], dp[i][j]);
			dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
		}
	}

	cout << *min_element(dp[n], dp[n]+m);
	return 0;
}