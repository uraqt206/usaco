#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

template<class T> bool umax(T &a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool umin(T &a, T b) { if (a>b) { a=b; return 1; } return 0; }

void setIO(string name="") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (name.size()) freopen((name+".inp").c_str(),"r",stdin);
	if (name.size()) freopen((name+".out").c_str(),"w",stdout);
}

const int mxN=300;
int n, a[mxN], dp[mxN+1][mxN+1];

int main() {
	setIO("");
	memset(dp, 0x3f, sizeof(dp));
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];

	for(int i=n; i>=1; --i) {
		dp[i][i]=1;
		for(int j=i+1; j<=n; ++j)
			for(int k=i; k<j; ++k)
				umin(dp[i][j], dp[i][k]+dp[k+1][j]-(a[i-1]==a[k]));
	}

	cout << dp[1][n];
}