#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define lc (id<<1)
#define rc (id<<1)+1
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

template<class T> bool umax(T &a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool umin(T &a, T b) { if (a>b) { a=b; return 1; } return 0; }

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

/*

<=> (t1 + t2 + t3 + ... + tk) / (w1 + w2 + w3 + ... + wk) >= x
<=> (t1 + t2 + t3 + ... + tk) >= x*w1 + x*w2 + x*w3 + ... + x*wk
<=> t1-w1*x + t2-w2*x + ... + tk-wk*x >= 0

*/

const ll MAX=1e15;
const int N=303;
ll n, w[N], t[N], W;
ll dp[1001];

bool f(int x) {
    for(int i=1; i<=W; ++i)
        dp[i]=-MAX;
    for(int i=1; i<=n; ++i) {
        ll val = t[i]*1000 - w[i]*x;

        for(int j=W; j>=1; --j) {
            int p=max(0LL, j-w[i]);
            if (dp[p]>-MAX)
                umax(dp[j], dp[p]+val);
        }
    }
    return dp[W]>=0;
}

int main() {
    setIO("talent");
    cin >> n >> W;
    for(int i=1; i<=n; ++i)
        cin >> w[i] >> t[i];

    int lb=-1, rb=250000000, mb;
    while (lb<rb) {
        mb=(lb+rb+1)>>1;
        if (f(mb))
            lb=mb;
        else
            rb=mb-1;
    }

    cout << lb << '\n';
}