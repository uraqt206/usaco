#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=101;
int n, m;
ll r[mxN], sum, val, dp[8][mxN], ans=1e15;

int main() {
	freopen("cbarn2.in", "r", stdin);
	freopen("cbarn2.out", "w", stdout);

	cin >> n >> m;
	for(int i=1; i<=n; ++i)
		cin >> r[i];

	for(int num=n; ~num; --num) {
		memset(dp, 0x3f, sizeof(dp));

		dp[0][0]=0;
		for(int k=1; k<=m; ++k)
			for(int i=1; i<=n; ++i) {
				sum=val=0;
				for(int j=i; j>=k; --j) {
					dp[k][i]=min(dp[k][i], dp[k-1][j-1]+val);
					sum+=r[j]; val+=sum;
				}
			}
		rotate(r+1, r+2, r+n+1);
		ans=min(ans, dp[m][n]);
	}

	cout << ans;
}