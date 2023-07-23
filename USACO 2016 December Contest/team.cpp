#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define ii pair<int, int>

const int mod=1e9+9;
const int N=1010;

int n, m, k;
int a[N], b[N];
ll dp[N][N];

int main() {
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);

    cin >> n >> m >> k;
    for(int i=1; i<=n; ++i)
        cin >> a[i];
    for(int i=1; i<=m; ++i)
        cin >> b[i];

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+(a[i]>b[j]);

    for(int x=2; x<=k; ++x) {
        for(int i=n; i>=1; --i)
            for(int j=m; j>=1; --j)
                if (a[i]>b[j])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 0;

        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
                dp[i][j]=(dp[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mod)%mod;
    }

    cout << dp[n][m];
}